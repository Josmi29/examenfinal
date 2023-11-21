#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arreglo_tamano 50000
//jose miguel ruiz marquez 180200

int busquedaSecuencial(int array[], int n, int elemento) 
{
    for (int i = 0; i < n; i++) 
	{
        if (array[i] == elemento) 
		{
            return i; 
        }
    }
    return -1;
}

int busquedaBinaria(int array[], int inicio, int fin, int elemento) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (array[medio] == elemento) {
            return medio; // Elemento encontrado, devuelve la posición
        }

        if (array[medio] < elemento) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1; 
}

void quicksort(int array[], int inicio, int fin) 
{
    if (inicio < fin) 
	{
        int pivote = array[(inicio + fin) / 2];
        int i = inicio;
        int j = fin;

        while (i <= j) 
		{
            while (array[i] < pivote) 
			{
                i++;
            }

            while (array[j] > pivote) 
			{
                j--;
            }

            if (i <= j) 
			{
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }

        if (inicio < j) 
		{
            quicksort(array, inicio, j);
        }

        if (i < fin) 
		{
            quicksort(array, i, fin);
        }
    }
}

int main() 
{
    int array[arreglo_tamano];
    for (int i = 0; i < arreglo_tamano; i++) 
	{
        array[i] = rand() % arreglo_tamano;
    }
t
    quicksort(array, 0, arreglo_tamano - 1);
    
    srand(time(NULL));
    int busqueda, posicion;
    clock_t inicio, fin;
    double tiempo;
    double tiemposSecuencial[100];
    double tiemposBinaria[100];

    for (int i = 0; i < 100; i++) 
	{
        busqueda = rand() % arreglo_tamano;
        
        inicio = clock();
        posicion = busquedaSecuencial(array, arreglo_tamano, busqueda);
        fin = clock();
        tiempo = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiemposSecuencial[i] = tiempo;
        inicio = clock();
        posicion = busquedaBinaria(array, 0, arreglo_tamano - 1, busqueda);
        fin = clock();
        tiempo = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiemposBinaria[i] = tiempo;
    }

    double promedioSecuencial = 0, minSecuencial = tiemposSecuencial[0], maxSecuencial = tiemposSecuencial[0];
    double promedioBinaria = 0, minBinaria = tiemposBinaria[0], maxBinaria = tiemposBinaria[0];

    for (int i = 0; i < 100; i++) 
	{
        promedioSecuencial += tiemposSecuencial[i];
        promedioBinaria += tiemposBinaria[i];

        if (tiemposSecuencial[i] < minSecuencial) 
		{
            minSecuencial = tiemposSecuencial[i];
        }

        if (tiemposSecuencial[i] > maxSecuencial)
		{
            maxSecuencial = tiemposSecuencial[i];
        }

        if (tiemposBinaria[i] < minBinaria) 
		{
            minBinaria = tiemposBinaria[i];
        }

        if (tiemposBinaria[i] > maxBinaria) 
		{
            maxBinaria = tiemposBinaria[i];
        }
    }

    promedioSecuencial /= 100;
    promedioBinaria /= 100;

    printf("Búsqueda Secuencial:\n");
    printf("Tiempo Promedio: %.6f ms\n", promedioSecuencial);
    printf("Tiempo Mínimo: %.6f ms\n", minSecuencial);
    printf("Tiempo Máximo: %.6f ms\n\n", maxSecuencial);

    printf("Búsqueda Binaria:\n");
    printf("Tiempo Promedio: %.6f ms\n", promedioBinaria);
    printf("Tiempo Mínimo: %.6f ms\n", minBinaria);
    printf("Tiempo Máximo: %.6f ms\n", maxBinaria);

    return 0;
}

