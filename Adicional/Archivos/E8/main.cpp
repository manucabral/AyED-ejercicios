/**
 * Agregar la funcionalidad de borrar un alumno. El borrado puede hacerse lógico, 
 * es decir poniendo una bandera en el registro que esté activo.
 */

#include <iostream>
#include <stdlib.h>

#define FILENAME "alumnos"

using namespace std;

typedef struct
{
    int dni, legajo;
    bool deleted;
    char name[24], surname[24], birth_date[24];
} Student;

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

void menu(void)
{
    std::cout << std::endl
              << "1. Agregar alumno" << std::endl;
    std::cout << "2. Listar todos los alumnos" << std::endl;
    std::cout << "3. Buscar alumno por legajo" << std::endl;
    std::cout << "4. Buscar alumno por DNI" << std::endl;
    std::cout << "5. Ordenar archivo por legajo" << std::endl;
    std::cout << "6. Borrar alumno por DNI" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

void inputStudent(Student &student)
{
    std::cout << "Nombre:";
    fflush(stdin);
    std::cin >> student.name;
    std::cout << "Apellido:";
    fflush(stdin);
    std::cin >> student.surname;
    std::cout << "Fecha de nacimiento:";
    fflush(stdin);
    std::cin >> student.birth_date;
    std::cout << "DNI: ";
    std::cin >> student.dni;
    std::cout << "Legajo:";
    std::cin >> student.legajo;
    student.deleted = false;
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

void displayStudent(Student &student)
{
    std::cout << std::endl;
    std::cout << student.name << " ";
    std::cout << student.surname << " ";
    std::cout << student.birth_date << " ";
    std::cout << student.dni << " ";
    std::cout << student.legajo << " ";
    std::cout << student.deleted << std::endl;
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
            if ((type == 0 ? student.legajo : student.dni) == value and !student.deleted)
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

void removeStudent(const char *filename, int value)
{
    FILE *file;
    Student student;
    int found = 0;
    if (file = fopen(filename, "rb+"))
    {
        while (!found and fread(&student, sizeof(Student), 1, file))
        {
            if (student.dni == value)
            {
                found = 1;
                student.deleted = true;
                fseek(file, (-1) * sizeof(Student), SEEK_CUR);
                fwrite(&student, sizeof(student), 1, file);
            }
        }
        if (found == 0)
            std::cout << "> No se puedo encontrar al alumno para borrarlo." << std::endl;
        else
            std::cout << "> Alumno borrado correctamente." << std::endl;
        fclose(file);
    }
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
            if(!student.deleted)
                displayStudent(student);
            fread(&student, sizeof(student), 1, file);
        }
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

void sortProcess(const char *filename)
{
    int size = getFileSize(filename);
    Student students[size];
    readArchive(filename, students, size);
    bubbleSort(students, size);
    writeArchive(filename, students, size);
}

void removeProcess(const char *filename)
{
    int value = 0;
    std::cout << "Ingrese el DNI del alumno a borrar:";
    std::cin >> value;
    removeStudent(filename, value);
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
        
        if(opc == 6)
            removeProcess(FILENAME);

    } while (opc != 0);
    return 0;
}
