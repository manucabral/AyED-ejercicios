/*
    Agregue al código anterior la funcionalidad para poder modificar un número, solicitando al 
    usuario en qué posición está el número que quiere modificar y cuál es el nuevo valor. Los 
    cambios deben ser guardados en el archivo.
*/

#include <iostream>

int read_archive(char *filename)
{
    FILE *file = fopen(filename, "rb");
    int num = 0;
    if (file)
    {
        fseek(file, 0, SEEK_SET);
        std::cout << "Valores del archivo: " << std::endl;
        while (!feof(file))
        {
            fread(&num, sizeof(int), 1, file);
            std::cout << num << std::endl;
        }

        fclose(file);
        return 0;
    }
    else
    {
        std::cout << "El archivo esta vacio" << std::endl;
        return 1;
    }
}

int overwrite_archive(char *filename, int pos, int data)
{
    FILE *file = fopen(filename, "rb+");
    if (file)
    {
        fseek(file, 0, SEEK_END);
        if (pos > ftell(file) / sizeof(int))
            std::cout << "Error: no existe esa posicion" << std::endl;
        else
        {
            fseek(file, sizeof(int) * (pos - 1), SEEK_SET);
            fwrite(&data, sizeof(int), 1, file);
        }
        fclose(file);
        return 0;
    }
    else
        return 1;
}

void write_data(FILE *file)
{
    int num = 0;
    std::cout << "Ingresa valor: ";
    std::cin >> num;
    fwrite(&num, sizeof(int), 1, file);
}

int write_archive(char *filename, int max)
{
    FILE *file = fopen(filename, "wb");
    if (file)
    {
        for (int i = 0; i < max; i++)
            write_data(file);

        fclose(file);
        return 0;
    }
    else
        return 1;
}

void process_write(char *filename)
{
    int max = 0;
    std::cout << "Cantidad de valores a ingresar:";
    std::cin >> max;
    write_archive(filename, max);
}

void process_overwrite(char *filename)
{
    int position = 0;
    int value = 0;
    std::cout << "Ingresa posicion a modificar";
    std::cin >> position;
    std::cout << "Ingresa el valor";
    std::cin >> value;
    overwrite_archive(filename, position, value);
}

void show_menu(char *filename)
{
    std::cout << std::endl
              << "ARCHIVO " << filename << std::endl;
    std::cout << "1. Leer archivo" << std::endl;
    std::cout << "2. Ingresar datos al archivo" << std::endl;
    std::cout << "3. Modificar el archivo" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

int main(int argc, char const *argv[])
{
    char filename[24];
    int option = -1;

    std::cout << "Ingrese el nombre del archivo:";
    std::cin >> filename;

    do
    {
        show_menu(filename);
        std::cin >> option;

        if (option == 1)
            read_archive(filename);

        if (option == 2)
            process_write(filename);

        if (option == 3)
            process_overwrite(filename);

    } while (option != 0);

    return 0;
}
