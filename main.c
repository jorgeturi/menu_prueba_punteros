#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
void borrar_pantalla(void);
void tecla_para_continuar(void);


int main()
{
    char *cadena_a_cargar;
    cadena_a_cargar=NULL;
    
    char opcion_elegida=1; //variable para las opciones del menu
    char confirmacion;       //variable para almacenar la confirmacion de salida

    while (opcion_elegida!=0)             //mientras la opcion elegida sea distinto de 5 imprime el menu, arranca en 0 por eso al menos 1 vez se muestra
{
    printf("\t Arme su menu\n");      //menu
    printf("1~ Agregar opcion\n");
    printf("2~ Quitar opcion\n");
    printf("3~ Ir al menu\n");
    printf("0~ Salir\n");

    printf("\nElija su opcion: \n\t\t");        //se elije una opcion y se guarda en opcion_elegida
    scanf("%c",&opcion_elegida);

    switch (opcion_elegida)                //segun se haya tocado, pasan los casos
{

    case '1':
        borrar_pantalla();                
        printf("ingrese la frase que quiere agregar\n");
        tecla_para_continuar();         //se espera una tecla para continuar
        borrar_pantalla();                //se borra la pantalla
        break;                          

    case '2':  
        tecla_para_continuar();
        borrar_pantalla();
        break;

    case '3': 
        tecla_para_continuar();
        borrar_pantalla();
        break;

    case '4': 
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
