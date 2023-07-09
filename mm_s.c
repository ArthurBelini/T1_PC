#include <stdio.h>
#include <stdlib.h>

#include "mm_aux.h"

// m3 = m1*m2
float **m1;
float **m2;
float **m3;
int tam_m;

void mm();
   
int main(int argc, char *argv[]) {
    if(argc != 2) {  // tam matriz - qtd threads
        printf("Quantidade de argumentos em linha de comando inválida!\n");
        exit(1);
    }

    tam_m = strtol(argv[1], NULL, 10);

    // printf("%d", tam_m);
    if(tam_m <= 0) {
        printf("Valor de argumento em linha de comando inválido!\n");
        exit(1);
    }

    alocate_matrix(&m3, tam_m);
    fill_matrix(&m1, tam_m);
    fill_matrix(&m2, tam_m);

    mm();

    exit(0);
}

void mm() {
    float x;

    for(int i = 0; i < tam_m; i++) {  // Linha
        printf("\n");
        for(int j = 0; j < tam_m; j++) {  // Coluna
            for(int k = 0; k < tam_m; k++) {  // Elementos
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%f ", m3[i][j]);
        }
    }
    printf("\n");
}