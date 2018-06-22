#ifndef TRAMITE_H_INCLUDED
#define TRAMITE_H_INCLUDED

typedef struct{
    int dni;
    int numero;
} eTramite;

int alta(void*,void*);
int atendidoUrgente(void*,void*);
int atendidoRegular(void*,void*);
eTramite* new_eTramite(eTramite*);
int proximoTurno(void*this,void*this2);
int proximoCliente(void* regularesNoat,void*regularesAt,void*urgentesAt,void*urgentesNoat);
void listaAtender(void*this,void*this2);
void listaUno(eTramite*this);
void informeAtendidos(void*this,void*this2);
void comparacionDni(void* this,void* this2);
#endif // TRAMITE_H_INCLUDED
