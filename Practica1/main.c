#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUMNO 2
struct ficha_alumno
{
    char nombre[30];
    int numero_DNI;
    char letra_DNI;
    char correo_electronico[30];
    float nota;
    char sexo;
    int dia;
    int mes;
    int ano;

}alumnos[MAX_ALUMNO];

void Introducir_alumnos()
{
    int i;
    for(i = 0; i < MAX_ALUMNO; i++)
    {
        printf("Introduce el nombre\n");
        fflush(stdin);
        gets(alumnos[i].nombre);
        fflush(stdin);

        printf("Introduce el numero del DNI\n");
        scanf("%d", &alumnos[i].numero_DNI);
        fflush(stdin);

        printf("Introduce la letra del DNI\n");
        scanf("%c", &alumnos[i].letra_DNI);
        fflush(stdin);

        printf("Introduce el correo electronico\n");
        scanf("%s", alumnos[i].correo_electronico);
        fflush(stdin);

        printf("Introduce la nota\n");
        scanf("%f", &alumnos[i].nota);
        fflush(stdin);

        printf("Introduce el dia de nacimiento\n");
        scanf("%d", &alumnos[i].dia);
        fflush(stdin);

        printf("Introduce el mes de nacimiento\n");
        scanf("%d", &alumnos[i].mes);
        fflush(stdin);

        printf("Introduce el ano de nacimiento\n");
        scanf("%d", &alumnos[i].ano);
        fflush(stdin);

        printf("Introduce el sexo H o M\n");
        scanf("%c", &alumnos[i].sexo);
        fflush(stdin);
    }
}

void mostrarAlumnos()
{
    int i;

    printf("Todos los alumnos\n");

    for(i = 0; i < MAX_ALUMNO; i++)
    {
        printf("----------------------------\n");
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("DNI: %d-%c\n", alumnos[i].numero_DNI, alumnos[i].letra_DNI);
        printf("Correo electronico: %s\n", alumnos[i].correo_electronico);
        printf("Nota: %.2f\n", alumnos[i].nota);
        printf("Fecha de nacimiento: %d/%d/%d\n", alumnos[i].dia, alumnos[i].mes, alumnos[i].ano);
        if(alumnos[i].sexo == 'H')
        {
            printf("Sexo: Hombre\n");
        }
        else if(alumnos[i].sexo == 'M')
        {
            printf("Sexo: Mujer\n");
        }
        else
        {
            printf("Sexo: Genero no binario\n");
        }
    }
}

void ordenar_DNI()
{
    int aux, i, j;
    i = 0;
    int vector[MAX_ALUMNO] = {};

    for(i = 0; i < MAX_ALUMNO; i++)
    {
        for(j = 0; j < MAX_ALUMNO; j++)
        {
            if(vector[j] > vector[j+1])
            {
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }

    for(i = 0; i < MAX_ALUMNO; i++)
    {
        printf("%d\n", vector[i]);
    }
}

void salir()
{
    printf("Fin del programa");
}

void menu()
{
    int opcion;

    do
    {
        printf("\n\tMenu de opciones\n\n");
        printf("1. Introducir alumno\n");
        printf("2. Buscar por DNI\n");
        printf("3. Buscar por Nombre\n");
        printf("4. Ver ultimo alumno buscado\n");
        printf("5. Eliminar ultimo alumno buscado\n");
        printf("0. Salir\n\n");

        printf("Elige una opcion\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
            {
                Introducir_alumnos();
            }
            break;

            case 2:
            {
                printf("2");
            }
            break;

            case 3:
            {
                printf("3");
            }
            break;

            case 4:
            {
                printf("4");
            }
            break;

            case 5:
            {
                printf("5");
            }
            break;

            case 0:
            {
                salir();
            }
            break;

            default:
            {
                printf("Opcion incorrecta\n");
            }

        }
    }while(opcion != 0);

}

int main()
{
    menu();
    return 0;
}
