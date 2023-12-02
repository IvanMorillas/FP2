#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcions.h"

int main(){

    int op;
    bool sortida;
    sortida = false;


    while(!sortida){

        printf("Benvingut/da a a la calculadora especial!");
        printf("\n------------------------");
        printf("\n(1) Per fer el factorial");
        printf("\n(2) Per fer fibonacci");
        printf("\n(3) Per fer maxim comu divisor");
        printf("\n(4) Per fer moviments de les Torres de Hanoi");
        printf("\n(5) Per fer la cerca dicotomica");
        printf("\n(6) Per fer la suma digital");
        printf("\n(7) Per fer l'arrel digital");
        printf("\n\n\n(0) Per sortir del programa\n\n");

        printf(" - Que desitges fer? ");
        scanf("%i", &op);
        fflush(stdin);

        while(op < 0 || op > 7){
            printf("\n - Opcio incorrecta.Que desitges fer? ");
            scanf("%i", &op);
            fflush(stdin);
        }

        switch(op){
            case 1:
                system("cls");
                demana_recursivitat_factorial();
                sortida=false;
                system("pause");
                break;

            case 2:
                system("cls");
                demana_fibonacci();
                sortida=false;
                system("pause");
                break;

            case 3:
                system("cls");
                demana_mcd();
                sortida=false;
                system("pause");
                break;

            case 4:
                system("cls");
                demana_hanoi();
                sortida=false;
                system("pause");
                break;

            case 5:
                system("cls");
                demana_cerca_dicotomica();
                sortida=false;
                system("pause");
                break;

            case 6:
                system("cls");
                demana_suma_digital();
                sortida=false;
                system("pause");
                break;

            case 7:
                system("cls");
                demana_arrel_digital();
                sortida=false;
                system("pause");
                break;

            case 0:
                sortida = true;
                break;

            default:
                 sortida=false;
                 break;

        }

        system("cls");

    }

    printf("\nFins aviat!\n");
    return 0;
}
