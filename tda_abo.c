#include <stdlib.h>
#include "tda_abo.h"

ABO *CreaABO(){
    ABO *arbol = malloc(sizeof(ABO));
    arbol = NULL;

    return arbol;
}

int ABOVacio(ABO *arbol){
    if(arbol == NULL){
        return 1;
    }else{
        return 0;
    }
}

Nodo * BuscarNodo(Nodo *n, DatosPrueba d){
    if(n != NULL){
        if(d.llave == n->elem.llave){
            return n;
        }else if(d.llave < n->elem.llave){
            return BuscarNodo(n->izq, d);
        }else if(d.llave > n->elem.llave){
            return BuscarNodo(n->der, d);
        }
    }else{
        return 0;
    }
}

void InsertarNodo(Nodo **n, DatosPrueba d){
    if(*n == NULL){
        *n = creaNodo(d);
    }else{
        if(d.llave < (*n)->elem.llave){
            if((*n)->izq == NULL){
                (*n)->izq = creaNodo(d);
            }else{
                InsertarNodo(&((*n)->izq), d);
            }
        }else{/*(d.llave > n->elem.llave)*/
            if((*n)->der == NULL){
                (*n)->der = creaNodo(d);
            }else{
                InsertarNodo(&((*n)->der), d);
            }
        }
    }
}

Nodo * creaNodo(DatosPrueba d){
   Nodo *nuevo = (ABO) malloc(sizeof(Nodo));

    if(nuevo != NULL){
        nuevo->izq = NULL;
        nuevo->der = NULL;
        nuevo->elem.llave = d.llave;
    }

   return nuevo;
}

void EliminarNodo(Nodo *n, DatosPrueba d){
    Nodo *eli = NULL;

    if(d.llave < n->elem.llave){
        EliminarNodo(n->izq, d);
    }else if(d.llave > n->elem.llave){
        EliminarNodo(n->der, d);
    }else{
        eli = n;

        if(n->izq == NULL){
            n = n->der;
        }else if(n->der == NULL){
            n = n->izq;
        }else{
            Reemplazar(eli);
        }

        free(eli);
    }
}

void Reemplazar(Nodo *n){
    Nodo *a,*p;

    p = n;
    a = n->izq;

    while(a->der){
        p = a;
        a = a->der;
    }

    n->elem = a->elem;

    if(p == n){
        p->izq = a->izq;
    }else{
        p->der = a->izq;
    }

    n = a;
}
