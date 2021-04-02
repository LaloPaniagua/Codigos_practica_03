#include "complejos.h"
#include <stdio.h>
int main()
{

    int x;
    COMP *val1, *val2, *h;
    val1 = (COMP *)malloc(sizeof(COMP));
    val2 = (COMP *)malloc(sizeof(COMP));
    h = (COMP *)malloc(sizeof(COMP));
    printf("Seleccione la operación a realizar: \n1)Suma\n2)Multiplicación\n");
    scanf("%i", &x);
	if (x == 1)
    {
        *val1=leer();
    	*val2=leer();
		suma(val1, val2, h);
    }
    else if (x == 2)
    {
        *val1=leer();
    	*val2=leer();
		mult(val1, val2, h);
    }
    else
    {
    	printf("No se ha ingresado una operación válida");
		return 0;
	}
    getchar();
    printf("\nEl resultado es \n");
    imprimir(*h);
    free(val1);
    free(val2);
    free(h);
    getchar();
    return 0;
}

COMP leer()
{
    COMP h;
    printf("Ingrese la parte real del numero complejo: ");
    scanf("%lf", &h.r);
    printf("Ingrese la parte imaginaria del numero complejo: ");
    scanf("%lf", &h.i);
    return h;
}

void suma(COMP *a, COMP *b, COMP *h)
{
    h->r = a->r + b->r;
    h->i = a->i + b->i;
}
void mult(COMP *a, COMP *b, COMP *h)
{
    h->r = (a->r * b->r) - (a->i * b->i);
    h->i = (a->r * b->i) + (a->i * b->r);
}
void imprimir(COMP h)
{
	printf("%lf", h.r);
    if (h.i > 0)
        printf(" + %lf i", h.i);
    else if (h.i < 0)
        printf(" %lf i", h.i);
}
