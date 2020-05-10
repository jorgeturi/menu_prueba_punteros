
#include <stdio.h>
#include <malloc.h>

void borrar_pantalla()   //pongo 50 espacios para "borrar" la pantalla
{
    int i=0;
    while (i<50)
    {
        i=i+1;
        printf("\n");
    }
}


void tecla_para_continuar()
{
    char c;
    printf("presione enter para continuar\n");
    scanf("%c",&c);
    scanf("%c",&c);
}

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

int comprobar_reserva_matriz(float **nombre_de_la_matriz, int numero_de_columnas ,int numero_de_filas) //se pasa la matriz, numero de filas y columnas reservadas
    {
        for (int i=0 ; i<numero_de_columnas ; i++) //revisa en cada columna
        {
            if(nombre_de_la_matriz+numero_de_columnas == NULL) //si la columna no puede ser reservada
            {
             printf("la columna n� %d , no puede reservar esa memoria", numero_de_columnas);
             return (100);                                      //si eso sucede, se envia un 100 CODIGO DE ERROR, COLUMNA NULL
            }

            for (int j=0 ; j<numero_de_filas ; j++) //dentro de cada columna, se revisa si las filas que pertenecen a esa columna
            {
              if(nombre_de_la_matriz+numero_de_filas == NULL) //puede ser reservada
                {
                    printf("la fila n� %d, de la columna n� %d, no puede reservar esa memoria", numero_de_filas, numero_de_columnas);
                    return (101);                             //si no puede ser reservada, se envia un 101 CODIGO DE ERROR, FILA DE COLUMNA NULL
                }
            }
            //al terminar con todas las filas de una columna
        }   //se pasa a la siguiente columna
        return (0); //retorna 0 si todo sale bien
    }


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

    void reserva_memoria_para_matriz(float **nombre_de_la_matriz, int numero_de_columnas ,int numero_de_filas)
{
    nombre_de_la_matriz=(float**)malloc(numero_de_columnas*sizeof(float*)); //reservo a matriz "numero de columas" columnas en heap
    for (int i=0 ; i<= numero_de_filas ; i++)                               //reservo a matriz "numero de filas" filas en heap
    {
    *(nombre_de_la_matriz+i)=(float*)malloc(numero_de_filas*sizeof(float));
    }
}