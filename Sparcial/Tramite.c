#include <stdio.h>
#include <stdlib.h>
#include "Tramite.h"
#include "ArrayList.h"

eTramite* new_eTramite(eTramite* this)
{

  this=(eTramite*)malloc(sizeof(eTramite));
  return this;
}



int alta(void*this,void*this2)
{
    eTramite * tramite=NULL;
    tramite=new_eTramite(tramite);
    printf("Ingrese el numero de dni:\n");
    scanf("%d",&(tramite->dni));
    tramite->numero=proximoTurno(this,this2);
    printf("\nSu numero de turno es %d\n",tramite->numero);
    system("pause");
    if(this!=NULL&&tramite!=NULL)
    {
        al_add(this,tramite);
    }

}

int proximoTurno(void*this,void*this2)
{   int i;

    eTramite * tramite;
    int aux=0;
    tramite=new_eTramite(tramite);

    if(this!=NULL&&this2!=NULL)
    {   if (al_len(this)!=0||al_len(this2)!=0)
        {

            for (i=0;i<al_len(this2);i++)
            {
                tramite=al_get(this2,i);
                if(tramite->numero > aux)
                {
                    aux=tramite->numero;

                }

            }
            for (i=0;i<al_len(this);i++)
            {
                tramite=al_get(this,i);
                if(tramite->numero > aux)
                {
                    aux=tramite->numero;

                }

            }
        }
    }
    return aux+1;
}


int proximoCliente(void* regularesNoat,void*regularesAt,void*urgentesAt,void*urgentesNoat)
{

    eTramite * tramite;
    int opcion=0;
    tramite=al_get(urgentesNoat,0);
    if(tramite==NULL)
    {
        tramite=al_get(regularesNoat,0);
        if(tramite==NULL)
        {
            printf("NO HAY CLIENTES");
            system("pause");
        }
        else
        {
           printf("El proximo cliente es el numero: %d. DNI: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->numero,tramite->dni);
        scanf("%d",&opcion);
        while(opcion!=1&&opcion!=2)
        {
            printf("El proximo cliente es el numero: %d. DNI: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->numero,tramite->dni);
            scanf("%d",&opcion);
        }
        if(opcion==1)
        {
        tramite=al_pop(regularesNoat,0);
        al_add(regularesAt,tramite);
        }
        }
    }
    else
    {
        printf("El proximo cliente es el numero: %d. DNI: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->numero,tramite->dni);
        scanf("%d",&opcion);
        while(opcion!=1&&opcion!=2)
        {
            printf("El proximo cliente es el numero: %d. DNI: %d\nDesea Atenderlo?\1-Si\n2-No",tramite->numero,tramite->dni);
            scanf("%d",&opcion);
        }
        if(opcion==1)
        {
        tramite=al_pop(urgentesNoat,0);
        al_add(urgentesAt,tramite);
        }
    }

}



void listaAtender(void*this,void*this2)
{   eTramite *tramite=NULL;
    int i;
    system("cls");
    if(al_len(this)>0)
    {
    printf("Clientes urgentes\n\n");
    for( i=0;i<al_len(this);i++)
    {
        tramite=al_get(this,i);
        listaUno(tramite);
    }
    }
    if(al_len(this2)!=0)
    {
    printf("\n\nClientes regulares\n\n");
    for( i=0;i<al_len(this2);i++)
    {
        tramite=al_get(this2,i);
        listaUno(tramite);
    }
    }
    printf("\n\n");

}
void listaUno(eTramite*this)
{
    printf("Turno:%d   Dni: %d\n",this->numero,this->dni);

}
void informeAtendidos(void*this,void*this2)
{
    int i;
    al_sort(this,comparacionDni,0);
    eTramite*tramite;
    system("cls");


    if(al_len(this)>0 || al_len(this2)>0)
    {

        if (al_len(this)>0)
        {
        printf("Clientes urgentes\n\n");
        for( i=0;i<al_len(this);i++)
        {
            tramite=al_get(this,i);
            listaUno(tramite);
        }
        }
        if(al_len(this2)!=0)
        {
        printf("\n\nClientes regulares\n\n");
        for( i=0;i<al_len(this2);i++)
        {
            tramite=al_get(this2,i);
            listaUno(tramite);
        }
        }
    }
    printf("\n\n");
    system("pause");


}

void comparacionDni(void* this,void* this2)
{
    eTramite *tramite1=(eTramite*)this;
    eTramite *tramite2=(eTramite*)this2;
    if(tramite1->dni>tramite2->dni)
    {
        return 1;
    }
    else if(tramite1->dni<tramite2->dni)
    {
        return -1;
    }

    return 0;


}
