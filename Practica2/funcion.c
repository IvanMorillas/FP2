#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "funcions.h"

//Factorial
unsigned long int recursivitat_factorial(unsigned long int fact){

    if (fact > 0){
        return fact*recursivitat_factorial(fact-1);
    }
    else if(fact == 0){
        return 1;
    }

    return 0;
}

void demana_recursivitat_factorial(){

    unsigned long int fact;

    printf("introdueix un numero: ");
    scanf("%lu",&fact);

    while(fact<0){

        printf("\n\nNo es pot fer el factorial de valors negatius. Torna a introduir el numero: ");
        scanf("%lu",&fact);
    }

    fact = recursivitat_factorial(fact);

    printf("\nEl factorial es: %lu\n\n",fact);
}

//Fibonacci
long fibonacci_recursiu(long num){

    if (num < 2) return num;
    else return (fibonacci_recursiu(num-1) + fibonacci_recursiu(num-2));
}

long fibonacci_iteratiu(long numero){

    long i, x = 0 ,y = 1, z = 1;

    for(i = 1; i < numero; i++){
        z=x+y;
        x=y;
        y=z;
    }
    return z;
}

void demana_fibonacci(){

    long valor;

    printf("Introdueix el valor: ");
    scanf("%li",&valor);
    printf("\nValor   F_r   F_i\n");
    printf("-------------------\n");
    printf("  %li     %li    %li\n\n", valor, fibonacci_recursiu(valor), fibonacci_iteratiu(valor));
}

//Suma Digital
int suma_digital_rec(int v){

    return v > 0 ? v % 10 + suma_digital_rec(v/10) : v;
}

int suma_digital_it(int numero){

    int suma = 0;

    while(numero > 0){
        suma = suma + numero % 10;
        numero = numero / 10;
    }
    return suma;
}

void demana_suma_digital(){

    int valor;

    printf("Introdueix el valor: ");
    scanf("%i",&valor);

    while(valor < 0){
        printf("\n\nNo s'accepten nombres negatius, introdueix el valor: ");
        scanf("%i",&valor);
    }

    printf("\nValor   S_r   S_i\n");
    printf("-------------------\n");
    printf(" %i     %i     %i\n\n", valor, suma_digital_rec(valor), suma_digital_it(valor));

}

//Cerca Dicotomica
bool cerca_dicotomica(int valor,int inferior,int superior,int meitat,int vec[],int moviment, int iteracions){

    bool trobat = false;

    if(moviment >= inferior && moviment <= superior){

        iteracions++;

        if(vec[moviment]==valor){
            trobat=true;
            printf("\nEl nombre de iteracions ha estat: %i", iteracions);
        }
        else if(vec[meitat+1]>valor){
            return cerca_dicotomica(valor,inferior,superior,meitat,vec, moviment-1, iteracions);
        }
        else if(vec[meitat-1]<valor){
            return cerca_dicotomica(valor,inferior,superior,meitat,vec, moviment+1, iteracions);
        }
    }
    return trobat;
}

void demana_cerca_dicotomica(){

    int *vec, valor, i, meitat, superior, inferior = 0, moviment;
    bool cercat;
    FILE *fitxer;

    fitxer = fopen("fitxer.txt", "r");
    //Carrega i comprovacio del fitxer
    if(fitxer == NULL){
        printf("Error. No s'ha detectat cap fitxer\n\n");
        return;
    }
    else{
        fseek( fitxer, 0, SEEK_END );
        if(ftell(fitxer)==0){
            printf("No s'han trobat elements en el fitxer.\n\n");
            return;
        }
        fseek( fitxer, 0, SEEK_SET );
        for(i = 0; !feof(fitxer); i++)fscanf(fitxer,"%d\n",&superior);
        if(i > 100){
            printf("El fitxer supera el nombre màxim de nombres.");
            return;
        }

        vec = (int*)malloc(i * sizeof(int));//Creació del vector
        fseek( fitxer, 0, SEEK_SET );
        for(i = 0; !feof(fitxer); i++) fscanf(fitxer,"%d\n",&vec[i]);

    }
    superior = i;
    fclose(fitxer);

    if(superior != 0){

        meitat = (inferior + superior)/2;
        moviment = meitat;

        for(i = 0; i < superior; i++) printf("%i | ", vec[i]);

        printf("\nEl numero d'elements es: %i\n", superior);
        printf("------------------------------------");

        printf("\n\nIntrodueix un valor del %i al %i per a dur a terme la cerca dicotomica: ", vec[inferior], vec[superior-1]);
        scanf("%i",&valor);
        i = 0;
        cercat = cerca_dicotomica(valor, inferior, superior, meitat, vec, moviment, i);

        if (cercat){
            printf("\n\nS'ha trobat el valor que has introduit\n\n");
        }
        else{
            printf("\n\nNo s'ha trobat res\n\n");
        }
    }
}

//Arrel digital
int arrel_digital(int valor){

    return valor >= 10 ? arrel_digital(valor/10 + valor%10) : valor;
}

void demana_arrel_digital(){

	int valor;

	printf("\nIntrodueix un valor: ");
	scanf("%d%*c",&valor);
	fflush(stdin);


	if(valor<0) printf("\nError: numero negatiu\n");
	else printf("\nL'arrel del valor introduit es: %i\n\n", arrel_digital(valor));
}

//Torres de hanoi
void hanoi(int discs,int t_origen, int t_aux, int t_fin){

    if(discs==1){
		printf("%c->%c",t_origen,t_fin);
	}
	else{
		 hanoi(discs-1,t_origen,t_fin,t_aux);

		 printf("\n%c->%c\n\n",t_origen,t_fin);

		 hanoi(discs-1,t_aux,t_origen,t_fin);
	}
}

void demana_hanoi(){

	char t_origen='A';
	char t_aux='B';
	char t_fin='C';

	int discs;

    printf("\nNombre de discs: ");
    scanf("%d",&discs);
    fflush(stdin);

    while(discs < 3 || discs > 10){
        printf("\n\nNombre de discs incorrecte. Torna a introduir el numero: ");
        scanf("%d",&discs);
        fflush(stdin);
    }

	printf("\n\nEls movimients a realizar son: \n\n");

	hanoi(discs,t_origen,t_aux,t_fin);
	printf("\n\n");
}

//MCD
unsigned int maxim_comu_divisor(unsigned int valor1,unsigned int valor2){
    return valor1 == 0 ? valor2 : maxim_comu_divisor(valor2 % valor1, valor1);
}

void demana_mcd(){

    int v1,v2,mcd;

    printf("Introdueix el primer valor:");
    scanf("%i",&v1); //divisor
    printf("\nIntrodueix el segon valor:");
    scanf("%i",&v2); //dividend
    mcd = maxim_comu_divisor(v1,v2);
    printf("\n\nEl mcd es: %i\n\n",mcd);
}
