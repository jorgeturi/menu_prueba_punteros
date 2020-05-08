
#include <stdio.h>

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