#include "funcions.h"

int main(){

    int v[N], num;
    char op;
    bool fi = false;


    do{
        carrega_vector(v);

        num = 0;

        printf("Benvingut a cerca i ordenacio. Tria una opcio:\n\n1.Ordenacio per seleccio\n2.Ordenacio per bombolla\n3.Ordenacio per insercio\n4.Cerca dicotomica\n");
        printf("\n0.Sortir");
        printf("\n\n\nQuina opcio tries? ");
        scanf("%c", &op);
        fflush(stdin);

        switch(op){
            case '1':
                system("cls");
                visualitzar_vector(v);
                ordenacio_per_seleccio(v, num);
                visualitzar_vector(v);
                system("pause");
                break;
            case '2':
                system("cls");
                visualitzar_vector(v);
                ordenacio_per_bombolla(v, num);
                visualitzar_vector(v);
                system("pause");
                break;
            case '3':
                system("cls");
                visualitzar_vector(v);
                ordenacio_per_insercio(v, num);
                visualitzar_vector(v);
                system("pause");
                break;
            case '4':
                system("cls");
                visualitzar_vector(v);
                cerca_dicotomica(v, num);
                system("pause");
                break;
            case '0':
                fi = true;
                break;
            default:
                system("cls");
                printf("Ets mes curt que una escala de collir pataques");
                system("pause");
                break;
        }

        system("cls");

    }while(!fi);
    printf("\n\n\n        Fins aviat!\n\n\n\n");
    return 0;
}
