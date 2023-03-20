//Iván Álvarez Fernández
//Marcos Gómez Tejón

#include "p2.h"


void checkUmbralAl(double *x, double *y, double *z, int t, int n){
    switch(UMBRAL){
        case 1:
            *x=t/pow(n,1.05);
            *y=t/pow(n,1.1);
            *z=t/pow(n,1.25);
            break;
        case 10:
            *x=t/pow(n,0.99);
            *y=t/(n*log10(n));
            *z=t/pow(n,1.24);
            break;
        case 100:
            *x=t/pow(n,1.06);
            *y=t/pow(n,1.1);
            *z=t/pow(n,1.15);
            break;
    } 
    return;   
}

void checkUmbralDes(double *x, double *y, double *z, int t, int n){
    switch(UMBRAL){
        case 1:
            *x=t/pow(n,0.95);
            *y=t/pow(n,1.07);
            *z=t/pow(n,1.2);
            break;
        case 10:
            *x=t/pow(n,0.98);
            *y=t/pow(n,1.11);
            *z=t/pow(n,1.25);
            break;
        case 100:
            *x=t/pow(n,1.12);
            *y=t/pow(n,1.145);
            *z=t/pow(n,1.25);
            break;
    }
}

void checkUmbralAs(double *x, double *y, double *z, int t, int n){
    switch(UMBRAL){
        case 1:
            *x=t/pow(n,1.05);
            *y=t/pow(n,1.1);
            *z=t/pow(n,1.2);
            break;
        case 10:
            *x=t/pow(n,0.98);
            *y=t/pow(n,1.1);
            *z=t/pow(n,1.25);
            break;
        case 100:
            *x=t/pow(n,1.1);
            *y=t/pow(n,1.2);
            *z=t/pow(n,1.28);
            break;
    }
}

void ord_ins(int v[], int n){
    int i,x,j;
    for(i=1;i<n;i++){
        x=v[i];
        j=i-1;
        while(j>=0 && v[j]>x){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=x;
    }
}

double microsegundos(){
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void inicializar_semilla() {
    srand(time(NULL));
}

void aleatorio(int v[], int n){
    int i, m=2*n+1;
    for(i=0;i<n;i++){
        v[i]=(rand()%m)-n;
    }
}

void ascendente(int v[], int n){
    int i;
    for (i=0; i<n; i++){
        v[i]=i;
    }
}

void descendente(int v[], int n){
    int i,j;
    for(i=0, j=n; i<n; i++, j--){
        v[i]=j;
    }
}

void tiempos_ins_aleatorio(){
    double t1, t2,t,ta,tb,x,y,z;
    int i, n, *v;
    for(n=500;n<=32000;n=n*2){
        v=malloc(sizeof(n));
        aleatorio(v,n);
        ta=microsegundos();
        ord_ins(v,n);
        tb=microsegundos();
        t=tb-ta;
        if(t<500){
            ta=microsegundos();
            for(i=0;i<1000;i++){
                aleatorio(v,n);
                ord_ins(v,n);
            }
            tb=microsegundos();
            t1=tb-ta;
            ta=microsegundos();
            for(i=0;i<1000;i++){
                aleatorio(v,n);
            }
            tb=microsegundos();
            t2=tb-ta;
            t=(t1-t2)/1000;
            printf("*");
        } else{           
            printf(" ");
        }
        x=t/pow(n,1.9);
        y=t/pow(n,1.98);
        z=t/pow(n,2.1); 
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n", n, t, x, y, z);
        free(v);
    }
    printf("\n");
}

void tiempos_ins_descendente(){
    double t1, t2,t,ta,tb,x,y,z;
    int i,n, *v;
    for(n=500;n<=32000;n=n*2){
        v=malloc(sizeof(n));
        descendente(v,n);
        ta=microsegundos();
        ord_ins(v,n);
        tb=microsegundos();
        t=tb-ta; 
        if(t<500){
            ta=microsegundos();
            for(i=0;i<1000;i++){
                descendente(v,n);
                ord_ins(v,n);
            }
            tb=microsegundos();
            t1=tb-ta;
            ta=microsegundos();
            for(i=0;i<1000;i++){
                descendente(v,n);
            }
            tb=microsegundos();
            t2=tb-ta;
            t=(t1-t2)/1000;
            printf("*");
        } else{   
            printf(" ");
        }
        x=t/pow(n,1.9);
        y=t/pow(n,2);
        z=t/pow(n,2.1);           
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n", n, t, x, y, z);
        free(v);
    }
    printf("\n");
}

void tiempos_ins_ascendente(){
    double t1, t2,t,ta,tb,x,y,z;
    int i,n, *v;
    for(n=500;n<=32000;n=n*2){
        v=malloc(sizeof(n));
        ascendente(v,n);
        ta=microsegundos();
        ord_ins(v,n);
        tb=microsegundos();
        t=tb-ta;
        if(t<500){
            ta=microsegundos();
            for(i=0;i<1000;i++){
                ascendente(v,n);
                ord_ins(v,n);
            }
            tb=microsegundos();
            t1=tb-ta;
            ta=microsegundos();
            for(i=0;i<1000;i++){
                ascendente(v,n);
            }
            tb=microsegundos();
            t2=tb-ta;
            t=(t1-t2)/1000;
            printf("*");
        } else{ 
            printf(" ");
        }
        x=t/pow(n,0.9);
        y=t/(double)n;
        z=t/pow(n,1.1);
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n", n, t, x, y, z);
        free(v);
    }
    printf("\n");
}

void tiempos_rap_aleatorio(){
    double t1, t2,t,ta,tb,x,y,z;
    int i,n, *v;
    for(n=500;n<=32000;n=n*2){
        v=malloc(sizeof(n));
        aleatorio(v,n);
        ta=microsegundos();
        ord_rap(v,n);
        tb=microsegundos();
        t=tb-ta;
        if(t<500){
            ta=microsegundos();
            for(i=0;i<1000;i++){
                aleatorio(v,n);
                ord_rap(v,n);
            }
            tb=microsegundos();
            t1=tb-ta;
            ta=microsegundos();
            for(i=0;i<1000;i++){
                aleatorio(v,n);
            }
            tb=microsegundos();
            t2=tb-ta;
            t=(t1-t2)/1000;
            printf("*");
        } else{       
            printf(" ");
        }
        checkUmbralAl(&x,&y,&z, t, n);      
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n", n, t, x, y, z);
        free(v);
    }
    printf("\n");
}

void tiempos_rap_descendente(){
    double t1, t2,t,ta,tb,x,y,z;
    int i,n, *v;
    for(n=500;n<=32000;n=n*2){
        v=malloc(sizeof(n));
        descendente(v,n);
        ta=microsegundos();
        ord_rap(v,n);
        tb=microsegundos();
        t=tb-ta;
        if(t<500){
            ta=microsegundos();
            for(i=0;i<1000;i++){
                descendente(v,n);
                ord_rap(v,n);
            }
            tb=microsegundos();
            t1=tb-ta;
            ta=microsegundos();
            for(i=0;i<1000;i++){
                descendente(v,n);
            }
            tb=microsegundos();
            t2=tb-ta;
            t=(t1-t2)/1000;
            printf("*");
        } else{
            printf(" ");
        }
        checkUmbralDes(&x,&y,&z, t, n);         
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n", n, t, x, y, z);
        free(v);
    }
    printf("\n");
}

void tiempos_rap_ascendente(){
    double t1, t2,t,ta,tb,x,y,z;
    int i,n, *v;
    for(n=500;n<=32000;n=n*2){
        v=malloc(sizeof(n));
        ascendente(v,n);
        ta=microsegundos();
        ord_rap(v,n);
        tb=microsegundos();
        t=tb-ta;
        if(t<500){
            ta=microsegundos();
            for(i=0;i<1000;i++){
                ascendente(v,n);
                ord_rap(v,n);
            }
            tb=microsegundos();
            t1=tb-ta;
            ta=microsegundos();
            for(i=0;i<1000;i++){
                ascendente(v,n);
            }
            tb=microsegundos();
            t2=tb-ta;
            t=(t1-t2)/1000;
            printf("*");
        } else{
            printf(" ");
        }
        checkUmbralAs(&x,&y,&z, t, n);       
        printf("%5d%15.5lf\t%15.7lf\t%15.7lf\t%15.7lf\n", n, t, x, y, z);
        free(v);
    }
    printf("\n");
}

void test_ins(){
    int n=10;
    int v[n];
    printf("Ordenación por inserción aleatoria\n");
    aleatorio(v, n);
    print_v(v,n);
    ord_ins(v,n);
    print_v(v,n);
    if(ordenado(v,n)) printf("Ordenado\n");
    else printf("No ordenado\n");
    printf("Ordenación por inserción ascendente\n");
    ascendente(v, n);
    print_v(v,n);
    ord_ins(v,n);
    print_v(v,n);
    if(ordenado(v,n)) printf("Ordenado\n");
    else printf("No ordenado\n");
    printf("Ordenación por inserción descendente\n");
    descendente(v, n);
    print_v(v,n);    
    ord_ins(v,n);
    print_v(v,n);    
    if(ordenado(v,n)) printf("Ordenado\n");
    else printf("No ordenado\n");
}

void test_rap(){
    int n=10;
    int v[n];
    printf("Ordenación por quicksort aleatoria\n");
    aleatorio(v, n);
    print_v(v,n);
    ord_rap(v,n);
    print_v(v,n);
    if(ordenado(v,n)) printf("Ordenado\n");
    else printf("No ordenado\n");
    printf("Ordenación por quicksort ascendente\n");
    ascendente(v, n);
    print_v(v,n);
    ord_rap(v,n);
    print_v(v,n);
    if(ordenado(v,n)) printf("Ordenado\n");
    else printf("No ordenado\n");
    printf("Ordenación por quicksort descendente\n");
    descendente(v, n);
    print_v(v,n);    
    ord_rap(v,n);
    print_v(v,n);    
    if(ordenado(v,n)) printf("Ordenado\n");
    else printf("No ordenado\n");
}

bool ordenado(int v[], int n){
    int i, cnt=0;
    for(i=0;i<n-1;i++){
        if(v[i+1]<v[i]){
            cnt++;
        }
    }
    return cnt==0;
}

void ordenarAux(int v[], int izq, int der){
    int x, pivote,i,j;
    if(izq+UMBRAL<=der){
        x=rand()%(der-izq+1)+izq;
        pivote=v[x];
        intercambiar(v, izq, x);
        i=izq+1;
        j=der;
        while(i<=j){
            while(i<=der && v[i]<pivote){
                i=i+1;
            }
            while(v[j]>pivote){
                j=j-1;
            }
            if(i<=j){
                intercambiar(v,i,j);
                i=i+1;
                j=j-1;
            }
        }
        intercambiar(v,izq,j);
        ordenarAux(v, izq, j-1);
        ordenarAux(v, j+1, der);
    }
}

void ord_rap(int v[], int n){
    ordenarAux(v,0,n-1);
    if(UMBRAL>1){
        ord_ins(v, n);
    }
}

void intercambiar(int v[], int izq, int der){
    int i;
    i=v[izq];
    v[izq]=v[der];
    v[der]=i;
}

void print_v(int v[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int n=0;
    int v[n];
    inicializar_semilla();
    test_ins();
    test_rap();
    printf("Algoritmo de inserción: aleatorio\n");
    tiempos_ins_aleatorio(v,n);
    printf("Algoritmo de inserción: ascendente\n");
    tiempos_ins_ascendente(v,n);
    printf("Algoritmo de inserción: descendente\n");
    tiempos_ins_descendente(v,n);
    printf("UMBRAL=%d\n", UMBRAL);
    printf("Algoritmo quicksort: aleatorio\n");
    tiempos_rap_aleatorio(v,n);
    printf("Algoritmo quicksort: ascendente\n");    
    tiempos_rap_ascendente(v,n);
    printf("Algoritmo quicksort: descendente\n");
    tiempos_rap_descendente(v,n);
    return 0;
}
