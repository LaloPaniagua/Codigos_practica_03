#include "prac3p2.h"
//Función para crear un polinomio
POLI crearpolinomio(){
    int i=0;
    POLI p;//Variable de tipo POLI que será retornada tras ejecutarse la función.
    p.P=NULL;
    printf("Ingrese el número de términos que tendrá el polinomio\n");
    scanf("%d",&p.terminos);//El usuario ingresa el número de términos
    while (p.terminos<=1)//Se asegura que haya por lo menos 2 términos
    {
        puts("El polinomio no puede tener menos de dos términos, ingrese un valor distinto");
        scanf("%d",&p.terminos);
    }
    
    p.P=malloc(sizeof(TERMINO)*p.terminos);//Se reserva la memoria necesaria para almacenar un polinomio del tamaño especificado
    for(i;i<p.terminos;i++){//Se asignan los coeficientes de cada término
        printf("Ingrese el valor del coeficiente correspondiente al término de grado %d :",i);
        scanf("%lf",&p.P[i].coeficiente);
        p.P[i].exponente=i;
    }
    return p;
}

POLI* resta(POLI a, POLI b){
    int i=0;
    POLI* respuesta;//Apuntador que será retornado tras ejecutarse la función
    respuesta=malloc(sizeof(POLI));//Se reserva la memoria necesaria para almacenar al polinomio resultante
    if(a.terminos>=b.terminos)
        respuesta->terminos=a.terminos;
    else
        respuesta->terminos=b.terminos;//Al polinomio respuesta se le asigna el tamaño del polinomio más grande
    respuesta->P=malloc(sizeof(TERMINO)*respuesta->terminos);//Se reserva la memoria necesaria para almacenar loos términos del polinomio resultante
    while(i<a.terminos && i<b.terminos){//Se realiza la resta de polinomios
        respuesta->P[i].coeficiente=a.P[i].coeficiente-b.P[i].coeficiente;
        respuesta->P[i].exponente=i;
        i++;
    }
    if(respuesta->terminos>=i){//Se llenan los términos restantes con los coeficientes del polinomio de mayor grado
        if(a.terminos>b.terminos){
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=a.P[i].coeficiente;
                respuesta->P[i].exponente=a.P[i].exponente;
            }
        }
        else{
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=b.P[i].coeficiente;
                respuesta->P[i].exponente=b.P[i].exponente * -1;
            }
        }
    }
    return respuesta;
}

//La función suma es igual a la función resta, solo cambiando la operación realizada entre los coeficientes
POLI* suma(POLI a, POLI b){
    int i=0;
    POLI* respuesta;
    respuesta=malloc(sizeof(POLI));
    if(a.terminos>=b.terminos)
        respuesta->terminos=a.terminos;
    else
        respuesta->terminos=b.terminos;
    respuesta->P=malloc(sizeof(TERMINO)*respuesta->terminos);
    while(i<a.terminos && i<b.terminos){
        respuesta->P[i].coeficiente=a.P[i].coeficiente+b.P[i].coeficiente;
        respuesta->P[i].exponente=i;
        i++;
    }
   if(respuesta->terminos>=i){
        if(a.terminos>b.terminos){
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=a.P[i].coeficiente;
                respuesta->P[i].exponente=a.P[i].exponente;
            }
        }
        else{
            for(i;i<respuesta->terminos;i++){
                respuesta->P[i].coeficiente=b.P[i].coeficiente;
                respuesta->P[i].exponente=b.P[i].exponente;
            }
        }
    }
    return respuesta;
}
//Función para imprimir los polinomios
void imprimir(POLI a){
    int i=a.terminos-1;//Variable con la posición de cada elemento del arreglo
    for(i;i>1;i--){//Ciclo para imprimir cada elemento del arreglo de grado superior a 2
        printf("%lf x^%d ",a.P[i].coeficiente,a.P[i].exponente);
        if(a.P[i-1].coeficiente>=0)
            printf("+ ");
    }
    printf("%lf x ",a.P[i].coeficiente);//Impresión del término lineal
        if(a.P[0].coeficiente>=0)
            printf("+ ");
    printf("%lf\n",a.P[0].coeficiente);//Impresión del término independiente
}

void liberar(POLI a){
    free(a.P);
    a.terminos=0;
}

int main(){
	int i=0,o=0;
    puts("Primer polinomio:");
    POLI p1=crearpolinomio();
    puts("Segundo polinomio:");
    POLI p2=crearpolinomio();
    POLI* r=NULL;
    printf("Seleccione la operación a realizar\n1)Suma\n2)Resta\n");
    scanf("%d",&o);
    while(o<1||o>2){
        puts("No se ha seleccionado una operación válida");
        scanf("%d",&o);
    }
    if(o==1)
        r=suma(p1,p2);
    else
        r=resta(p1,p2);
    puts("Resultado:");
    imprimir(*r);
    liberar(p1);
    liberar(p2);
    liberar(*r);
    free(r);
    return 1;
}
