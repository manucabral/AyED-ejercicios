/*
    Escriba un programa que permita a un usuario ingresar n valores float y se guarden en un 
    archivo, el número n lo informa al comienzo del programa. 
    Al finalizar el programa debe listar todos los números guardados en el archivo.
*/

#include <iostream>

int read_archive(char *filename)
{
    FILE *file = fopen(filename, "rb");
    float num = 0;

    if (file)
    {
        while (fread(&num, sizeof(float), sizeof num, file))
            std::cout << num << std::endl;
        fclose(file);
        return 0;
    }
    else
        return 1;
}

int write_archive(char *filename, int max)
{
    FILE *file = fopen(filename, "wb");
    float num = 0;

    if (file)
    {
        for (int i = 0; i < max; i++)
        {
            std::cout << "Ingresa valor: ";
            std::cin >> num;
            fwrite(&num, sizeof(float), sizeof num, file);
        }
        fclose(file);
        return 0;
    }
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    char filename[24];
    int max = 0;

    std::cout << "Ingrese el nombre del archivo:";
    std::cin >> filename;

    std::cout << "Ingrese cantidad de valores que ingresara: ";
    std::cin >> max;

    write_archive(filename, max);
    read_archive(filename);

    return 0;
}
