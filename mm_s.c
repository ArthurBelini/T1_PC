#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "mm_aux.h"

float **m1;
float **m2;
float **m3;
int tam_m;
int qtd_t;
   
int main(int argc, char *argv[]) {
    if(argc != 3) {  // tam matriz - qtd threads
        exit(1);
    }

    tam_m = strtol(argv[1], NULL, 10);
    qtd_t = strtol(argv[2], NULL, 10);

    if(tam_m <= 0 || qtd_t <= 0) {
        exit(1);
    }

    fill_matrix(m1, tam_m);
    // fill_matrix(m2, tam_m);

    // printf("%d\n", m1[0][0]);
    // printf("%d %d\n", tam_m, qtd_t);

    exit(0);
}