#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct str_prueba{
    int llave;
} DatosPrueba;

typedef struct str_nodo{
    DatosPrueba elem;
    struct str_nodo *izq;
    struct str_nodo *der;
} Nodo;

typedef Nodo *ABO;

#endif // ESTRUCTURAS_H_INCLUDED
