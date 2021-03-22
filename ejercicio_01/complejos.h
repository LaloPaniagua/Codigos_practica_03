#include <stdio.h>
#include<stdlib.h>

#ifndef COMPLEJOS_H
#define COMPLEJOS_H

struct complejo
{
    double r;
    double i;
};

typedef struct complejo COMP;

void suma(COMP *a, COMP *b, COMP *h);
void mult(COMP *a, COMP *b, COMP *h);
COMP leer();
void imprimir(COMP h);
#endif
