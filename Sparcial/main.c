#include <stdio.h>
#include <stdlib.h>
#include "Tramite.h"
#include "ArrayList.h"

int main()
{
    int opcion=0;
    ArrayList* urgentesNoat=NULL;
    ArrayList* urgentesAt=NULL;
    ArrayList* regularesNoat=NULL;
    ArrayList* regularesAt=NULL;
    urgentesNoat=al_newArrayList();
    urgentesAt=al_newArrayList();
    regularesNoat=al_newArrayList();
    regularesAt=al_newArrayList();
    if (urgentesAt!=NULL&&urgentesNoat!=NULL&&regularesNoat!=NULL&&regularesAt!=NULL)
    {
        while(opcion!=6)
        {   system("cls");
            printf("\t MENU\n1.Tramite urgente\n2.Tramite regular\n3.Proximo cliente\n4.Listar\n5.Informar\n6.Salir\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:

                alta(urgentesNoat,urgentesAt);

                break;
            case 2:
                alta(regularesNoat,regularesAt);
                break;
            case 3:
                proximoCliente(regularesNoat,regularesAt,urgentesAt,urgentesNoat);
                break;
            case 4:
                listaAtender(urgentesNoat,regularesNoat);
                system("pause");
                break;
            case 5:
                informeAtendidos(urgentesAt,regularesAt);
            case 6:
                break;

            }

        }
    }
    else
    {
        printf("Algo ha salido mal.");
    }





}
