#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Prac3p2.h"
/* NOTAS GENERALES PA LOS PANAS
    Actualmente no puedo correr el programa porque me da error con todo el rollo de POLI y los asteriscos usados para los apuntadores. 
    Trtaen de correrlo en sus compus y me dicen que les sale.
    No se porque no esta identificando el struc del .h
*/


/*
Para crear el poli se debe saber primero el grado, el cual se almacena dentro del struc como un int
De acuerdo al grado se va almacenando memoria para eso.
El ciclo for es para almacenar los datos de cada temino.
*/
POLI* crearpoli(){
        POLI nuevo;
        printf("Cual es el grado del polinomio?\n");
        scanf("%d",&nuevo->grado);
        nuevo = (POLI*)malloc(nuevo->grado*sizeof(POLI));
        printf("Ingrese los valores de su polinomio, empezando por el termino independiente\n");
        for(int i = 0; i <= nuevo->grado; i++){
        printf("Valor del coeficiente grado %i: ", i);
        scanf("%f", &nuevo->p[i]);
        }
        imprimir(POLI *nuevo);//Puede haver problemas con la invocacion de esta funcion
        return *nuevo;
}
/*
El if sirve para primero identificar si el grado del polinomio 1 es mayor al del 2 para usarlo como la base para la suma.
si a no es mayor, entonces b es mayor. En caso de que b=a o a=b, no importa cual de los polinomiosse use como base.
Por eso solo hay un if y else.
Lo mismo pasa con la resta pero negativo
*/
void suma(POLI *a, POLI *b){
    if (a->grado > b->grado){  
    for(int i=0;i<=b->grado;i++)
        a->p[i] = a->p[i] + b->p[i];
    imprimir(POLI *a);
    }else{
     for(int i=0;i<=a->grado;i++)
        b->p[i] = b->p[i] + a->p[i];
    imprimir(POLI *b);
    }
}
void resta(POLI *a, POLI *b){
if (a->grado > b->grado){  
    for(int i=0;i<=b->grado;i++)
        a->p[i] = a->p[i] - b->p[i];
    imprimir(POLI *a);
    }else{
     for(int i=0;i<=a->grado;i++)
        b->p[i] = b->p[i] - a->p[i];
    imprimir(POLI *b);
    }
}
/*
Para imprimir empezamos por el grado mas alto y vamos al mas pequeño
El if else if sirve para que se imprima de esta forma: "9x^4+9x^3+6x^2+5x+6"
*/
void imprimir(*a){
    printf("Su polinomio es: ");
    for(int i = a->grado; i >= 0; i--)
    {
        if(i == 0)
        {
            printf("%0.2lf",  a->p[i]);
        }
        else if(i == 1)
        {
            printf("%0.2lfx + ",  a->p[i]);
        }
        else
        {
            printf("%0.2lfx^%i + ", a->p[i], i);
        }
    }
}
int main(){
    int x;
    //Se declaran los 2 polis a crear
    POLI *a,*b;
    *a=crearpoli();
    *b=crearpoli();
    printf("Que operacion desea realizar?\n 1-suma \n 2-resta");
    scanf("&d",&x);
    //La neta no me acordaba como se usa el switch, espero que esto sea lo correcto.
    switch (x)
    {
    case 1:
        suma(POLI *a, POLI *b);
        break;
    case 2:
        resta(POLI *a, POLI *b);
        break;
    default:
        printf("\nOpcion no valida");
        break;
    return 0xF;
    }
    
    
   
    
    
    
    
    
    
    
    
    
}