#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

void borrar_pantalla(void);
void tecla_para_continuar(void);
void imprimir_matriz(float **, int, int);
void transponer_matriz(float **, float **, int);
void llenar_matriz(float **, int, int);
int comprobar_reserva_matriz(float **, int, int); //devuelve int por si algun espacio no puede ser agarrado
void reserva_memoria_para_matriz(float **, int, int);


int main()
{
    int N_COLUMNAS = 4;
    int N_FILAS = 4;
    int matriz_cuadrada = 0;
    int ORDEN = 0;

    float**matriz; //matriz es un puntero doble

    int N_COLUMNAST = N_FILAS;
    int N_FILAST = N_COLUMNAS;

    float**matrizt; //matriz es un puntero doble

    if (N_FILAS == N_COLUMNAS)
    {
        matriz_cuadrada=1;
        ORDEN = N_FILAS;
    }

   

    
   

 
    

    

    
    /*fflush(stdin);
    char ingresado;
    int a;
       scanf ("%c", &ingresado);
       int isdigit (int);
       a = isdigit (ingresado) ;
       printf ("%d" , a);
       */














    char opcion_elegida = '1'; //variable para las opciones del menu
    char confirmacion;       //variable para almacenar la confirmacion de salida

    while (opcion_elegida!=0)             //mientras la opcion elegida sea distinto de 5 imprime el menu, arranca en 0 por eso al menos 1 vez se muestra
{
    printf("Menu de operaciones\n");      //menu
    printf("1.Ingresar matriz\n");
    printf("2.Imprimir matriz\n");
    printf("3.Transponer matriz\n");
    printf("4.Calcular matriz adjunta\n");
    printf("5.Calcular determinante\n");
    printf("6.Calcular inversa, si existe\n");
    printf("0.Salir\n");
    printf("\nElija su opcion: \n\t\t");        //se elije una opcion y se guarda en opcion_elegida
    scanf("%c",&opcion_elegida);

    switch (opcion_elegida)                //segun se haya tocado, pasan los casos
{

    case '1':
        borrar_pantalla();                
        //reserva de memoria manual hasta que la funcion funcione
         //reserva_memoria_para_matriz(matriz,N_COLUMNAS,N_FILAS);

         matriz=(float**)malloc(N_COLUMNAS*sizeof(float*)); //reservo a matriz "numero de columas" columnas en heap
         for (int i=0 ; i<= N_FILAS ; i++)                               //reservo a matriz "numero de filas" filas en heap
         {
         *(matriz+i)=(float*)malloc(N_FILAS*sizeof(float));
         }

        comprobar_reserva_matriz(matriz, N_COLUMNAS, N_FILAS);
        llenar_matriz(matriz,N_COLUMNAS,N_FILAS);
        tecla_para_continuar();         //se espera una tecla para continuar
        borrar_pantalla();                //se borra la pantalla
        break;                          

    case '2':  
        imprimir_matriz(matriz,N_COLUMNAS,N_FILAS);
        tecla_para_continuar();
        borrar_pantalla();
        break;

    case '3': 
        //reserva de memoria manual para la transpuesta
        matrizt=(float**)malloc(N_COLUMNAST*sizeof(float*)); //reservo a matriz "numero de columas" columnas en heap
        for (int i=0 ; i<= N_FILAST ; i++)                               //reservo a matriz "numero de filas" filas en heap
        {
        *(matrizt+i)=(float*)malloc(N_FILAST*sizeof(float));
        }
        comprobar_reserva_matriz(matrizt, N_COLUMNAST, N_FILAST);

    

         transponer_matriz(matriz, matrizt, ORDEN);
         printf ("\n \n");
         imprimir_matriz(matrizt, N_FILAS, N_COLUMNAS);
         printf ("\n");
        tecla_para_continuar();
        borrar_pantalla();
        break;

    case '4': 
        tecla_para_continuar();
        borrar_pantalla();
        break;
    
    case '5':
        tecla_para_continuar();
        borrar_pantalla();
        break;

    case '6':
         if (matriz_cuadrada == 0)
       {
        printf("no puede calcularse la inversa \n");
        printf("no puede calcularse su determinante \n");
       }
        tecla_para_continuar();
        borrar_pantalla();
        break;

     case '0': //caso salir
        printf("seguro que queres salir? (s/n) \n");
        scanf("%c",&confirmacion);
        scanf("%c",&confirmacion);   //no estoy seguro por que pero creo que queda algo en la consola por eso tengo que poner 2
        if (confirmacion=='s' || confirmacion=='S') //si seguro quiere salir, retorno 0, termina el programa
        {
            opcion_elegida=0;
        }
        else
        {
            printf("entonces volvamos al menu\n"); //sino tocaste s es que no estas seguro entonces volvemos
            opcion_elegida=80;   //cambio opcion_elegida a 80 porque el while se va a repetir si es distinto de 5, sino al evaluar terminaria
            tecla_para_continuar();
            borrar_pantalla();
        }
        break;

     default:
        printf("\nEsa opcion no es valida\n");
        printf("Debe ingresar una opcion del 1 al 4 o 0 \n");
        tecla_para_continuar();
        borrar_pantalla();
        break;
} //fin del switch

} //fin del while
    return 0;
}
