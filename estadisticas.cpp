#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANO 10000
#define REPETICIONES 100
//jose miguel ruiz marquez 180200
void generarArregloAleatorio(int arreglo[TAMANO]);
void insertionSort(int arreglo[TAMANO]);
void quickSort(int arreglo[TAMANO], int primero, int ultimo);
void bubbleSort(int arreglo[TAMANO]);
void mostrarArreglo(int arreglo[TAMANO]);

int main() {
    int arregloOriginal[TAMANO];
    int arregloCopia[TAMANO];
    clock_t inicio, fin;
    double tiempoEjecucion[REPETICIONES];
    generarArregloAleatorio(arregloOriginal);

    for (int i = 0; i < REPETICIONES; ++i) 
	{
        for (int j = 0; j < TAMANO; ++j) 
		{
            arregloCopia[j] = arregloOriginal[j];
        }

        inicio = clock();
        insertionSort(arregloCopia);
        fin = clock();
        tiempoEjecucion[i] = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
    }

    double promedio = 0, minimo = tiempoEjecucion[0], maximo = tiempoEjecucion[0];
    for (int i = 0; i < REPETICIONES; ++i) 
	{
        promedio += tiempoEjecucion[i];

        if (tiempoEjecucion[i] < minimo) 
		{
            minimo = tiempoEjecucion[i];
        }

        if (tiempoEjecucion[i] > maximo) 
		{
            maximo = tiempoEjecucion[i];
        }
    }
    promedio /= REPETICIONES;

    printf("Insertion Sort:\n");
    printf("promedio: %.2f ms\n", promedio);
    printf("minimo: %.2f ms\n", minimo);
    printf("maximo: %.2f ms\n\n", maximo);

    for (int i = 0; i < REPETICIONES; ++i) 
	{
        for (int j = 0; j < TAMANO; ++j) 
		{
            arregloCopia[j] = arregloOriginal[j];
        }
        
        inicio = clock();
        quickSort(arregloCopia, 0, TAMANO - 1);
        fin = clock();

        tiempoEjecucion[i] = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
    }

    promedio = 0, minimo = tiempoEjecucion[0], maximo = tiempoEjecucion[0];
    for (int i = 0; i < REPETICIONES; ++i) {
        promedio += tiempoEjecucion[i];

        if (tiempoEjecucion[i] < minimo) {
            minimo = tiempoEjecucion[i];
        }

        if (tiempoEjecucion[i] > maximo) {
            maximo = tiempoEjecucion[i];
        }
    }
    promedio /= REPETICIONES;

    printf("Quick Sort:\n");
    printf("promedio: %.2f ms\n", promedio);
    printf("minimo: %.2f ms\n", minimo);
    printf("maximo: %.2f ms\n\n", maximo);

    for (int i = 0; i < REPETICIONES; ++i) 
	{
        for (int j = 0; j < TAMANO; ++j) 
		{
            arregloCopia[j] = arregloOriginal[j];
        }

        inicio = clock();
        bubbleSort(arregloCopia);
        fin = clock();

        tiempoEjecucion[i] = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
    }

    promedio = 0, minimo = tiempoEjecucion[0], maximo = tiempoEjecucion[0];
    for (int i = 0; i < REPETICIONES; ++i) 
	{
        promedio += tiempoEjecucion[i];

        if (tiempoEjecucion[i] < minimo) 
		{
            minimo = tiempoEjecucion[i];
        }

        if (tiempoEjecucion[i] > maximo) 
		{
            maximo = tiempoEjecucion[i];
        }
    }
    promedio /= REPETICIONES;

    printf("Bubble Sort:\n");
    printf("promedio: %.2f ms\n", promedio);
    printf("minimo: %.2f ms\n", minimo);
    printf("maximi: %.2f ms\n\n", maximo);

    return 0;
}

void generarArregloAleatorio(int arreglo[TAMANO]) 
{
    srand(time(NULL));
    for (int i = 0; i < TAMANO; ++i) 
	{
        arreglo[i] = rand() % 10000; 
    }
}

void insertionSort(int arreglo[TAMANO]) 
{
    for (int i = 1; i < TAMANO; ++i) 
	{
        int clave = arreglo[i];
        int j = i - 1;

        while (j >= 0 && arreglo[j] > clave) 
		{
            arreglo[j + 1] = arreglo[j];
            --j;
        }

        arreglo[j + 1] = clave;
    }
}

void quickSort(int arreglo[TAMANO], int primero, int ultimo) 
{
    int pivot, i, j, temp;
    if (primero < ultimo) {
        pivot = primero;
        i = primero;
        j = ultimo;
        while (i < j) {
            while (arreglo[i] <= arreglo[pivot] && i < ultimo) 
			{
                i++;
            }
            while (arreglo[j] > arreglo[pivot]) 
			{
                j--;
            }
            if (i < j) {
                temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
            }
        }
        temp = arreglo[j];
        arreglo[j] = arreglo[pivot];
        arreglo[pivot] = temp;
        quickSort(arreglo, primero, j - 1);
        quickSort(arreglo, j + 1, ultimo);
    }
}

void bubbleSort(int arreglo[TAMANO]) 
{
    for (int i = 0; i < TAMANO - 1; ++i) 
	{
        for (int j = 0; j < TAMANO - i - 1; ++j) 
		{
            if (arreglo[j] > arreglo[j + 1]) 
			{
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}


void mostrarArreglo(int arreglo[TAMANO]) 
{
    for (int i = 0; i < TAMANO; ++i) 
	{
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

