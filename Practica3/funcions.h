#ifndef FUNCIONS_H_INCLUDED
#define FUNCIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 100

void carrega_vector(int v[]);
void visualitzar_vector(int v[]);

void ordenacio_per_seleccio(int v[], int cont);
void ordenacio_per_bombolla(int v[], int cont);
void ordenacio_per_insercio(int v[], int cont);

void cerca_dicotomica(int v[], int cont);
void swap(int taula[],int A, int B);

#endif // FUNCIONS_H_INCLUDED
