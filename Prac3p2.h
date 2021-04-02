#include<stdbool.h>
#include<stdlib.h>
#ifdef COMPLEJOS_H
#define COMPLEJOS_H

struct _polinomio{
    double *p;
    int grado;
};
typedef struct _polinomio POLI;
POLI* crearpoli();
void resta(POLI *a, POLI *b);
void suma(POLI *a, POLI *b);
void imprimir(POLI *a)
void liberar(POLI *a);
#endif