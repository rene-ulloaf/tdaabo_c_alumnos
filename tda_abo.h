#ifndef TDA_ABO_H_INCLUDED
#define TDA_ABO_H_INCLUDED

#include "estructuras.h"

ABO *CreaABO();
int ABOVacio(ABO *);
Nodo * BuscarNodo(Nodo *, DatosPrueba);
void InsertarNodo(Nodo **, DatosPrueba);
Nodo * creaNodo(DatosPrueba);
void EliminarNodo(Nodo *, DatosPrueba);
void Reemplazar(Nodo *);

#endif // TDA_ABO_H_INCLUDED
