/**
 * Extender el programa anterior poniendo un menú principal con las siguientes opciones:
 * Agregar un alumno
 * > Listar todos los alumnos
 * > Buscar alumno por legajo
 * > Buscar alumno por DNI
 * > Ordenar archivo por legajo.
 * > Salir
 * Implemente la funcionalidad para cada opción en subprogramas.
 */

#include <iostream>
#include <stdlib.h>

#define FILENAME "alumnos"

using namespace std;

typedef struct
{
    int dni, legajo;
    char nombre[24], apellido[24], fecha_nacimiento[24];
} Student;

void inputStudent(Student &student)
{
    std::cout << "Nombre:";
    fflush(stdin);
    std::cin >> student.nombre;
    std::cout << "Apellido:";
    fflush(stdin);
    std::cin >> student.apellido;
    std::cout << "Fecha de nacimiento:";
    fflush(stdin);
    std::cin >> student.fecha_nacimiento;
    std::cout << "DNI: ";
    std::cin >> student.dni;
    std::cout << "Legajo:";
    std::cin >> student.legajo;
}

void displayStudent(Student &student)
{
    std::cout << std::endl;
    std::cout << student.nombre << " ";
    std::cout << student.apellido << " ";
    std::cout << student.fecha_nacimiento << " ";
    std::cout << student.dni << " ";
    std::cout << student.legajo << " " << std::endl;
}

int pushStudent(const char *filename, Student &student)
{
    FILE *file;
    if (file = fopen(filename, "ab"))
    {
        fwrite(&student, sizeof(student), 1, file);
        fclose(file);
        return 1;
    }
    else
        return 0;
}

void menu(void)
{
    std::cout << std::endl
              << "1. Agregar alumno" << std::endl;
    std::cout << "2. Listar todos los alumnos" << std::endl;
    std::cout << "3. Buscar alumno por legajo" << std::endl;
    std::cout << "4. Buscar alumno por DNI" << std::endl;
    std::cout << "5. Ordenar archivo por legajo" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

void pushProcess(const char *filename)
{
    Student student;
    inputStudent(student);

    if (pushStudent(filename, student))
        std::cout << "> Alumno registrado correctamente.";
    else
        std::cout << "> Hubo un error al registrar al alumno.";
}

void listProcess(const char *filename)
{
    FILE *file;
    Student student;
    if (file = fopen(filename, "rb"))
    {
        fread(&student, sizeof(student), 1, file);
        while (!feof(file))
        {
            displayStudent(student);
            fread(&student, sizeof(student), 1, file);
        }
        fclose(file);
    }
}

void searchStudent(const char *filename, int type, int value)
{
    FILE *file;
    Student student;
    int found = 0;
    if (file = fopen(filename, "rb"))
    {
        while (!found and fread(&student, sizeof(student), 1, file))
        {
            if ((type == 0 ? student.legajo : student.dni) == value)
            {
                found = 1;
                displayStudent(student);
            }
        }
        if (found == 0)
            std::cout << "> No se pudo encontrar al alumno" << std::endl;
        fclose(file);
    }
}

void searchProcess(const char *filename, int type)
{
    int value = 0;
    const char *msg = type == 0 ? "> Ingresa el legajo:" : "> Ingresa el dni:";
    std::cout << msg;
    std::cin >> value;
    searchStudent(filename, type, value);
}

int getFileSize(const char *filename)
{
    FILE *file;
    int filesize = 0;
    file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    filesize = ftell(file) / sizeof(Student);
    fseek(file, 0, SEEK_SET);
    return filesize;
}

void readArchive(const char *filename, Student *students, int size)
{
    FILE *file;
    Student student;
    if (file = fopen(filename, "rb"))
    {
        fseek(file, 0, SEEK_SET);
        fread(students, sizeof(Student), size, file);
        fclose(file);
    }
}

void swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Student *students, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (students[j].dni > students[j + 1].dni)
                swap(&students[j], &students[j + 1]);
}

int writeArchive(const char *filename, Student *students, int size)
{
    FILE *file;
    if (file = fopen(filename, "wb"))
    {
        fseek(file, 0, SEEK_SET);
        fwrite(students, sizeof(Student), size, file);
        fclose(file);
        return 0;
    }
    else
        return 1;
}

void sortProcess(const char *filename)
{
    int size = getFileSize(filename);
    Student students[size];
    readArchive(filename, students, size);
    bubbleSort(students, size);
    writeArchive(filename, students, size);
}

int main(int argc, char const *argv[])
{
    int opc = -1;
    do
    {
        menu();
        cin >> opc;

        if (opc == 1)
            pushProcess(FILENAME);

        if (opc == 2)
            listProcess(FILENAME);

        if (opc == 3)
            searchProcess(FILENAME, 0);

        if (opc == 4)
            searchProcess(FILENAME, 1);

        if (opc == 5)
            sortProcess(FILENAME);

    } while (opc != 0);
    return 0;
}
