#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#ifndef PRAC3P2_H
#define PRAC3P2_H

//Estructura del término del polinomio que consiste de un coeficiente y un exponente
struct _termino{
    int exponente;
    double coeficiente;
};
typedef struct _termino TERMINO;
/*Estructura del polinomio compuesta por un campo con la cantidad 
de términos del polinomio y un apuntador que contendrá a loos términos*/
struct _polinomio{
    int terminos;
    TERMINO* P;
};
typedef struct _polinomio POLI;
//Prototipos de las funciones
POLI crearpolinomio();
POLI* resta(POLI* a, POLI* b);
POLI* suma(POLI* a, POLI* b);
void imprimir(POLI* a);
void liberar(POLI* a);
#endif
