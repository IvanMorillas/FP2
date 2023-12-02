#ifndef FUNCIONS_H_INCLUDED
#define FUNCIONS_H_INCLUDED

#define LONGITUD 100

//Factorial
void demana_recursivitat_factorial();
unsigned long int recursivitat_factorial(unsigned long int fact);

//Fibonacci
void demana_fibonacci();
long fibonacci_recursiu(long num);
long fibonacci_iteratiu(long numero);

//Suma Digital
void demana_suma_digital();
int suma_digital_rec(int v);
int suma_digital_it(int numero);

//Arrel digital
void demana_arrel_digital();
int arrel_digital(int valor);

//Cerca Dicotomica
bool cerca_dicotomica(int valor,int inferior,int superior,int meitat,int vec[],int moviment, int iteracions);
void demana_cerca_dicotomica();

//Torres de Hanoi
void demana_hanoi();
void hanoi(int discs,int t_origen, int t_aux, int t_fin);

//MCD
void demana_mcd();
unsigned int maxim_comu_divisor(unsigned int valor1,unsigned int valor2);

#endif // FUNCIONS_H_INCLUDED
