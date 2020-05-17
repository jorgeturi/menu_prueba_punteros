#include <stdio.h>
#include <stdlib.h>

void imprimir_matriz(float ***, int N_FILAS , int N_COLUMNAS);
float ** reservar_memoria(float ***matriz, int N_FILAS, int N_COLUMNAS);
float ** llenar_matriz(float ***matriz, int N_FILAS, int N_COLUMNAS);
float ** transponer_2_matrices(float ***matriz_a_transponer, float***matriz_transpuesta, int N_FILAS, int N_COLUMNAS);

double calcular_determinante(float **fuente);

int main()
{
    float ** matriz = NULL;
    float ** matrizt = NULL;

    int N_FILAS = 3;
    int N_COLUMNAS = 3;
    int N_FILAST;
    int N_COLUMNAST;

    int matriz_cuadrada = 0;
    int ORDEN = 0;

    if (N_FILAS == N_COLUMNAS)
    {
        matriz_cuadrada = 1;
        ORDEN = N_FILAS;
    }

    N_FILAST = N_COLUMNAS;
    N_COLUMNAST = N_FILAS;

    matriz = reservar_memoria(&matriz, N_FILAS, N_COLUMNAS);
    matrizt = reservar_memoria(&matrizt, N_FILAST, N_COLUMNAST);

    matriz = llenar_matriz(&matriz, N_FILAS, N_COLUMNAS);
    matrizt = transponer_2_matrices (&matriz, &matrizt, N_FILAS, N_COLUMNAS);


    imprimir_matriz (&matriz, N_FILAS, N_COLUMNAS);
    imprimir_matriz (&matrizt, N_FILAST, N_COLUMNAST);
    double determinante;
    determinante = calcular_determinante(matriz);
    printf ("el determinante es: %f", determinante);

    //float **matrizadj = NULL;
    return 0;
}


float** reservar_memoria(float ***matriz,int N_FILAS,int N_COLUMNAS)
{
    *matriz=(float**)malloc(N_FILAS*sizeof(float**));

    if (*matriz ==NULL)
    {
        puts("memoria insuficiente");
        exit (500);
    }


    for (int i=0 ; i<N_FILAS ; i++)
    {
        *(*(matriz)+i) =(float*)malloc(N_COLUMNAS*sizeof(float*));

        if ( *(*(matriz)+i) ==NULL)
    {
        puts("memoria insuficiente");
        exit (500);
    }


    }

    return *matriz;
}

void imprimir_matriz(float *** matriz_a_imprimir, int N_FILAS, int N_COLUMNAS)
{
    for(int i=0; i<N_FILAS; i++)
    {
        for(int j=0; j<N_COLUMNAS; j++)
        {
            printf("\t[%d][%d] = %3f", i, j, *(*(*(matriz_a_imprimir)+i)+j) );
        }
        puts("\n");
    }
}

float ** llenar_matriz(float ***matriz,int N_FILAS,int N_COLUMNAS)
{

        for(int f=0; f<N_FILAS; f++)
        {
            printf("\tFila numero %d:\n",f+1);
            for(int c=0; c<N_COLUMNAS; c++)
            {
                printf("\t\tColumna %d [%d][%d] = ", c, f, c);
                scanf("%f", *(*(matriz)+f)+c );
            }
            printf("\n");
        }


    return *matriz;
}

float ** transponer_2_matrices(float ***matriz_a_transponer, float***matriz_transpuesta, int N_FILAS, int N_COLUMNAS)
{
  for(int i=0; i<N_FILAS; i++)
    {
        for(int j=0; j<N_COLUMNAS; j++)
        {
                *(*(*(matriz_transpuesta)+j)+i) = *(*(*(matriz_a_transponer)+i)+j);
        }
    }

    return *matriz_transpuesta;
}

float **calcular_adjunta(float **fuente, float **destino)
{
    destino[0][0] = fuente[1][1]*fuente[2][2]-fuente[2][1]*fuente[1][2];
    destino[0][1] = -(fuente[1][0]*fuente[2][2]-fuente[2][0]*fuente[1][2]);
    destino[0][2] = fuente[1][0]*fuente[2][1]-fuente[2][0]*fuente[1][1];
    destino[1][0] = -(fuente[0][1]*fuente[2][2]-fuente[2][1]*fuente[0][2]);
    destino[1][1] = fuente[0][0]*fuente[2][2]-fuente[2][0]*fuente[0][2];
    destino[1][2] = -(fuente[0][0]*fuente[2][1]-fuente[2][0]*fuente[0][1]);
    destino[2][0] = fuente[0][1]*fuente[1][2]-fuente[1][1]*fuente[0][2];
    destino[2][1] = -(fuente[0][0]*fuente[1][2]-fuente[1][0]*fuente[0][2]);
    destino[2][2] = fuente[0][0]*fuente[1][1]-fuente[1][0]*fuente[0][1];

    return destino;
}

double calcular_determinante(float **fuente)
{
    double determinante;

    determinante = (fuente[0][0]*fuente[1][1]*fuente[2][2]+fuente[0][1]*fuente[1][2]*fuente[2][0]+
                    fuente[1][0]*fuente[2][1]*fuente[0][2]-(fuente[0][2]*fuente[1][1]*fuente[2][0])-
                    (fuente[0][1]*fuente[1][0]*fuente[2][2])-(fuente[1][2]*fuente[2][1]*fuente[0][0]));

    return determinante;
}

