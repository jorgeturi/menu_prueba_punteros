#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
void reserva_memoria_para_matriz(float **, int, int);
void reserva_memoria_para_matriz(float **nombre_de_la_matriz, int numero_de_columnas ,int numero_de_filas)
{
    nombre_de_la_matriz=(float**)malloc(numero_de_columnas*sizeof(float*)); //reservo a matriz "numero de columas" columnas en heap
    for (int i=0 ; i<= numero_de_filas ; i++)                               //reservo a matriz "numero de filas" filas en heap
    {
    *(nombre_de_la_matriz+i)=(float*)malloc(numero_de_filas*sizeof(float));
    }
}

void llenar_matriz(float **, int, int);
void llenar_matriz(float **nombre_de_la_matriz, int numero_de_columnas ,int numero_de_filas)
{
    for (int i=0 ; i<numero_de_columnas ; i++)  //llenamos cada columna
        {
            printf ("\n");
            for (int j=0 ; j<numero_de_filas ; j++) //llenando cada una de sus filas
            {
                printf("[%d][%d]:",i,j);            //se imprime componente por componente
                scanf("%f", (*(nombre_de_la_matriz+i)+j)); //se llena el contenido de la columna + "j" bytes*tipo de dato
            }
        }
}


void imprimir_matriz(float **, int, int);
void imprimir_matriz(float **nombre_de_la_matriz, int numero_de_columnas ,int numero_de_filas)
    {
        for (int i=0 ; i<numero_de_columnas ; i++)  //se imprime cada columna
        {
            printf ("\n");                          //baja un espacio cada vez que se cambia de columna
            for (int j=0 ; j<numero_de_filas ; j++) //con sus respectivas filas
            {
                printf("[%d][%d] %f \t", i,j, *(*(nombre_de_la_matriz+i)+j)); //indicando componentes, se tabula por cada componente de la fila
            }
        }
    }

int comprobar_reserva_matriz(float **, int, int); //devuelve int por si algun espacio no puede ser agarrado
int comprobar_reserva_matriz(float **nombre_de_la_matriz, int numero_de_columnas ,int numero_de_filas) //se pasa la matriz, numero de filas y columnas reservadas
    {
        for (int i=0 ; i<numero_de_columnas ; i++) //revisa en cada columna
        {
            if(nombre_de_la_matriz+numero_de_columnas == NULL) //si la columna no puede ser reservada
            {
             printf("la columna nº %d , no puede reservar esa memoria", numero_de_columnas);
             return (100);                                      //si eso sucede, se envia un 100 CODIGO DE ERROR, COLUMNA NULL
            }

            for (int j=0 ; j<numero_de_filas ; j++) //dentro de cada columna, se revisa si las filas que pertenecen a esa columna
            {
              if(nombre_de_la_matriz+numero_de_filas == NULL) //puede ser reservada
                {
                    printf("la fila nº %d, de la columna nº %d, no puede reservar esa memoria", numero_de_filas, numero_de_columnas);
                    return (101);                             //si no puede ser reservada, se envia un 101 CODIGO DE ERROR, FILA DE COLUMNA NULL
                }
            }
            //al terminar con todas las filas de una columna
        }   //se pasa a la siguiente columna
        return (0); //retorna 0 si todo sale bien
    }

    void transponer_matriz(float **, float **, int);
void transponer_matriz(float **nombre_de_la_matriz, float**nombre_de_la_transpuesta, int orden_de_la_matriz)
    {
        for (int i=0 ; i<orden_de_la_matriz ; i++)  //se imprime cada columna
        {

            for (int j=0 ; j<orden_de_la_matriz ; j++) //con sus respectivas filas
            {
              *(*(nombre_de_la_transpuesta+j)+i) = *(*(nombre_de_la_matriz+i)+j); //indicando componentes, se tabula por cada componente de la fila
            }
        }
    }
int main()
{
    int N_COLUMNAS = 4;
    int N_FILAS = 4;
    int matriz_cuadrada = 0;
    int ORDEN = 0;

    float**matriz; //matriz es un puntero doble

    matriz=(float**)malloc(N_COLUMNAS*sizeof(float*)); //reservo a matriz "numero de columas" columnas en heap
    for (int i=0 ; i<= N_FILAS ; i++)                               //reservo a matriz "numero de filas" filas en heap
    {
    *(matriz+i)=(float*)malloc(N_FILAS*sizeof(float));
    }

   //reserva_memoria_para_matriz(matriz,N_COLUMNAS,N_FILAS);
   comprobar_reserva_matriz(matriz, N_COLUMNAS, N_FILAS);
   llenar_matriz(matriz,N_COLUMNAS,N_FILAS);
   imprimir_matriz(matriz,N_COLUMNAS,N_FILAS);

   int N_COLUMNAST = N_FILAS;
   int N_FILAST = N_COLUMNAS;

    float**matrizt; //matriz es un puntero doble

    matrizt=(float**)malloc(N_COLUMNAST*sizeof(float*)); //reservo a matriz "numero de columas" columnas en heap
    for (int i=0 ; i<= N_FILAST ; i++)                               //reservo a matriz "numero de filas" filas en heap
    {
    *(matrizt+i)=(float*)malloc(N_FILAST*sizeof(float));
    }
    comprobar_reserva_matriz(matrizt, N_COLUMNAST, N_FILAST);

    if (N_FILAS == N_COLUMNAS)
    {
        matriz_cuadrada=1;
        ORDEN = N_FILAS;
    }

    transponer_matriz(matriz, matrizt, ORDEN);
    printf ("\n \n");
    imprimir_matriz(matrizt, N_FILAS, N_COLUMNAS);
    printf ("\n");

    if (matriz_cuadrada == 0)
    {
        printf("no puede calcularse la inversa \n");
        printf("no puede calcularse su determinante \n");
    }

    fflush(stdin);
    char ingresado;
    int a;
       scanf ("%c", &ingresado);
       int isdigit (int);
       a = isdigit (ingresado) ;
       printf ("%d" , a);



}
