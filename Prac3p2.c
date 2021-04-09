#include <stdio.h>
#include "pruebadef.h"
//Funci?n para crear un polinomio
POLI crearpolinomio(){
    int i=0;
    POLI p;//Variable de tipo POLI que ser? retornada tras ejecutarse la funci?n.
    p.P=NULL;
    printf("Ingrese el n?mero de t?rminos que tendr? el polinomio\n");
    scanf("%d",&p.terminos);//El usuario ingresa el n?mero de t?rminos
    while (p.terminos<=1)//Se asegura que haya por lo menos 2 t?rminos
    {
        puts("El polinomio no puede tener menos de dos t?rminos, ingrese un valor distinto");
        scanf("%d",&p.terminos);
    }
    
//Se reserva la memoria necesaria para almacenar un polinomio del tama?o especificado
    p.P=malloc(sizeof(TERMINO)*p.terminos);
	//Se asignan los coeficientes de cada t?rmino
    for(i;i<p.terminos;i++){
        printf("Ingrese el valor del coeficiente correspondiente al t?rmino de grado %d :",i);
        scanf("%lf",&p.P[i].coeficiente);
        p.P[i].exponente=i;
    }
    return p;
}

POLI* resta(POLI* a, POLI* b){
    int i=0;
//Apuntador que ser? retornado tras ejecutarse la funci?n
    POLI* respuesta;
//Se reserva la memoria necesaria para almacenar al polinomio resultante
    respuesta=malloc(sizeof(POLI));
    if(a->terminos>=b->terminos)
        respuesta->terminos=a->terminos;
    else
//Al polinomio respuesta se le asigna el tama?o del polinomio m?s grande
        respuesta->terminos=b->terminos;
//Se reserva la memoria necesaria para almacenar loos t?rminos del polinomio resultante
    respuesta->P=malloc(sizeof(TERMINO)*respuesta->terminos);
    while(i<a->terminos && i<b->terminos){//Se realiza la resta de polinomios
        respuesta->P[i].coeficiente=a->P[i].coeficiente-b->P[i].coeficiente;
        respuesta->P[i].exponente=i;
        i++;
    }
//Se llenan los t?rminos restantes con los coeficientes del polinomio de mayor grado
    if(respuesta->terminos>=i){
        if(a->terminos>b->terminos){
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=a->P[i].coeficiente;
                respuesta->P[i].exponente=a->P[i].exponente;
            }
        }
        else{
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=b->P[i].coeficiente;
                respuesta->P[i].exponente=b->P[i].exponente * -1;
            }
        }
    }
    return respuesta;
}

/*La funci?n suma es igual a la funci?n resta,
solo cambiando la operaci?n realizada entre los coeficientes*/
POLI* suma(POLI* a, POLI* b){
    int i=0;
    POLI* respuesta;
    respuesta=malloc(sizeof(POLI));
    if(a->terminos>=b->terminos)
        respuesta->terminos=a->terminos;
    else
        respuesta->terminos=b->terminos;
    respuesta->P=malloc(sizeof(TERMINO)*respuesta->terminos);
    while(i<a->terminos && i<b->terminos){
        respuesta->P[i].coeficiente=a->P[i].coeficiente+b->P[i].coeficiente;
        respuesta->P[i].exponente=i;
        i++;
    }
   if(respuesta->terminos>=i){
        if(a->terminos>b->terminos){
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=a->P[i].coeficiente;
                respuesta->P[i].exponente=a->P[i].exponente;
            }
        }
        else{
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=b->P[i].coeficiente;
                respuesta->P[i].exponente=b->P[i].exponente;
            }
        }
    }
    return respuesta;
}
//Funci?n para imprimir los polinomios
void imprimir(POLI* a){
//Variable con la posici?n de cada elemento del arreglo
    int i=a->terminos-1;
//Ciclo para imprimir cada elemento del arreglo de grado superior a 2
    for(i;i>1;i--){
        printf("%lf x^%d ",a->P[i].coeficiente,a->P[i].exponente);
        if(a->P[i-1].coeficiente>=0)
            printf("+ ");
    }
    printf("%lf x ",a->P[i].coeficiente);//Impresi?n del t?rmino lineal
        if(a->P[0].coeficiente>=0)
            printf("+ ");
    printf("%lf\n",a->P[0].coeficiente);//Impresi?n del t?rmino independiente
}

void liberar(POLI* a){
    free(a->P);
    a->terminos=0;
}

int main(){
	int i=0,o=0;
    puts("Primer polinomio:");
    POLI p1=crearpolinomio();
    puts("Segundo polinomio:");
    POLI p2=crearpolinomio();
    POLI *r=NULL;
    printf("Seleccione la operaci?n a realizar\n1)Suma\n2)Resta\n");
    scanf("%d",&o);
    while(o<1||o>2){
        puts("No se ha seleccionado una operaci?n v?lida");
        scanf("%d",&o);
    }
    if(o==1)
        r=suma(&p1,&p2);
    else
        r=resta(&p1,&p2);
    puts("Resultado:");
    imprimir(r);
    liberar(&p1);
    liberar(&p2);
    liberar(r);
    return 1;
}
//Hecho por Eduardo Paniagua, Diego Barragan y Alejandra Avila en 18/03/2021
