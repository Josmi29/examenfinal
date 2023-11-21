#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tamano 30
//jose miguel ruiz marquez 180200
void llenarMatrizAleatoria(int matriz[tamano][tamano]);
void mostrarMatriz(int matriz[tamano][tamano]);
void multiplicarMatrices(int matrizA[tamano][tamano], int matrizB[tamano][tamano], int resultado[tamano][tamano]);

int main() 
{
    srand(time(NULL));
    int matrizA[tamano][tamano];
    int matrizB[tamano][tamano];
    int resultado[tamano][tamano];

    llenarMatrizAleatoria(matrizA);
    llenarMatrizAleatoria(matrizB);

    printf("matriz 1:\n");
    mostrarMatriz(matrizA);
    printf("\nmatriz 2:\n");
    mostrarMatriz(matrizB);

    clock_t inicio = clock();

    multiplicarMatrices(matrizA, matrizB, resultado);

    clock_t fin = clock();
    double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
    
    printf("\nmultiplicación:\n");
    mostrarMatriz(resultado);

    
    printf("\ntiempo: %.2f milisegundos\n", tiempoEjecucion);

    return 0;
}

void llenarMatrizAleatoria(int matriz[tamano][tamano]) 
{
    for (int i = 0; i < tamano; ++i) 
	{
        for (int j = 0; j < tamano; ++j) 
		{
            matriz[i][j] = rand() % 10;
        }
    }
}

void mostrarMatriz(int matriz[tamano][tamano]) 
{
    for (int i = 0; i < tamano; ++i) 
	{
        for (int j = 0; j < tamano; ++j) 
		{
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int matrizA[tamano][tamano], int matrizB[tamano][tamano], int resultado[tamano][tamano]) 
{
    for (int i = 0; i < tamano; ++i) 
	{
        for (int j = 0; j < tamano; ++j) 
		{
            resultado[i][j] = 0;
            for (int k = 0; k < tamano; ++k) 
			{
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

