//Iván Álvarez Fernández
//Marcos Gómez Tejón

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define UMBRAL 1

double microsegundos();
void inicializar_semilla();
void checkUmbralAl(double *x, double *y, double *z, int t, int n);
void checkUmbralDes(double *x, double *y, double *z, int t, int n);
void checkUmbralAs(double *x, double *y, double *z, int t, int n);
void ord_ins(int v[], int n);
void aleatorio(int v[], int n);
void ascendente(int v[], int n);
void descendente(int v[], int n);
void tiempos_ins_aleatorio();
void tiempos_ins_descendente();
void tiempos_ins_ascendente();
void tiempos_rap_aleatorio();
void tiempos_rap_descendente();
void tiempos_rap_ascendente();
void test_ins();
void test_rap();
bool ordenado(int v[], int n);
void ordenarAux(int v[], int izq, int der);
void intercambiar(int v[], int izq, int der);
void ord_rap(int v[], int n);
void print_v(int v[], int n);
