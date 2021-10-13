/**
 * Dado una vector de polizas
 * Realice un procedimiento que reciba el vector de polizas, el tamaño logico del vector, una feha
 * en formato (AAAAMMDD) y la ruta/nombre del archivo. El procedimiento debe crear un archivo con los datos
 * de todas aquellas polizas del vector que esten vencidas considerando la fecha pasada por parametro.
 */

#include <iostream>

// Estructura dado  por el enunciado.
struct Poliza
{
    int nroPoliza, fechaVencimiento;
    char DNIAsegurado[11], nombreAsegurado[50], apellidoAsegurado[50], patenteVehiculo[20];
};

void GuardarPolizasVencidas(Poliza *polizas, int tam, int fecha, char *nombreArchivo)
{
    FILE *f;
    if(f = fopen(nombreArchivo, "w")){
        for(int i=0;i<tam;i++)
            if(fecha > polizas[i].fechaVencimiento)
                fwrite(&polizas[i], sizeof(Poliza), 1, f);
        fclose(f);
    }
}
 