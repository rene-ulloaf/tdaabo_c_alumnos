#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "tda_abo.h"
#include "estructuras.h"

int main(){
    ABO *arbol = CreaABO();
    inicio(arbol);

    return 0;
}

void inicio(ABO *a){
    char sel;

    printf("[1] ingresar datos\n");
    printf("[2] eliminar datos\n");
    printf("[3] ver datos\n");
    printf("[4] Salir");
    printf("\n\nOpcion : ");
    fflush(stdin);
    scanf("%s", &sel);

    if(sel == '1'){
        system("cls");
        Ingresar(a);
    }else if(sel == '2'){
        system("cls");
        Eliminar(a);
    }else if(sel == '3'){
        system("cls");
        Ver(a);
    }else if(sel == '4'){
        //Salir();
    }else{
        system("cls");
        main();
    }
}

void Ingresar(ABO *a){
    int dato;
    char res;
    DatosPrueba dat;

    printf("\nIngrese dato : ");
    fflush(stdin);
    scanf("%i", &dato);

    dat.llave = dato;
    InsertarNodo(&a,dat);

    printf("\n\nAgregar otra? [S/N]");
    fflush(stdin);
    scanf("%c", &res);

    if(res == 'S' || res == 's'){
        Ingresar(a);
    }else{
        main(a);
    }
}

void Eliminar(ABO *a){
    int dato;
    char res;
    DatosPrueba dat;

    printf("\nIngrese dato : ");
    fflush(stdin);
    scanf("%i", &dato);

    dat.llave = dato;
    InsertarNodo(&a,dat);

    printf("\n\nEliminar otra? [S/N]");
    fflush(stdin);
    scanf("%c", &res);

    if(res == 'S' || res == 's'){
        Eliminar(a);
    }else{
        main(a);
    }
}

void Ver(ABO *a){

}
