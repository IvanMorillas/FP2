#include "funcions.h"

void carrega_vector(int v[]){

    int i;
    srand(time(NULL));

    for (i = 0; i < N; i++){
        v[i] = rand() % 101;
    }

}

void ordenacio_per_seleccio(int v[], int cont){

    int i, j, aux, min;

    for(i = 0; i < N; i++){
        min = i;

        for(j = i + 1; j < N; j++){

            if(v[j] < v[min]){
                min = j;
            }
            cont++;
        }

        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
    printf("\n\nContador: %i\n\n", cont);
}

void ordenacio_per_bombolla(int v[], int cont){

    int i, j, aux;
    /*bool ordenat = false;
    while(!ordenat){
        ordenat = true;
        for(j = 0; j < N-i; j++){
            if(v[j] > v[j+1]){
                ordenat = false;
                swap(v, j, j+1);
                cont++;
            }
        }
        i++;
    }*/

    for(i = 0; i < N; i++){

        for(j = 0; j < N; j++){

            if (v[j] > v[j+1]){

                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                cont++;
            }
        }
    }
    printf("\n\nContador: %i\n\n", cont);
}

void ordenacio_per_insercio(int v[], int cont){

    int i, pos, aux;

    for(i = 0; i < N; i++){
        pos = i;
        aux = v[i];

        while( (pos > 0)&&(v[pos-1] > aux) ){

            v[pos] = v[pos-1];
            pos--;
            cont++;
        }
        v[pos]=aux;
    }
    printf("\n\nContador: %i\n\n", cont);
}


void cerca_dicotomica(int v[], int cont){

    int sup = N, inf = 0, meitat, valor;

    ordenacio_per_seleccio(v, cont);

    visualitzar_vector(v);

    printf("Escriu el valor que vols trobar: ");
    scanf("%i",&valor);
    fflush(stdin);

    meitat = (inf+sup)/2;

    while(inf < sup && v[meitat] != valor){

        if(v[meitat] < valor) inf = meitat + 1;
        else sup = meitat - 1;

        meitat = (inf+sup)/2;
    }

    if(v[meitat] == valor) printf("S'ha trobat el nombre %i a la posicio %i.\n\n", valor, meitat);
    else printf("No s'ha trobat cap coincidencia.\n\n");
}

void visualitzar_vector(int v[]){

    int i;

    for(i = 0; i < N; i++){

        printf("%i", v[i]);
        if(i < N-1) printf(" --> ");
    }
    printf("\n\n");
}

void swap(int taula[],int A, int B){//Inhabilitat

    int aux;
    aux = taula[A];
    taula[A] = taula[B];
    taula[B] = aux;
}
