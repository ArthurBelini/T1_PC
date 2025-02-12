#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mm_aux.h"

// m3 = m1*m2
float **m1;
float **m2;
float **m3;
int tam_m;

void mm();
   
int main(int argc, char *argv[]) {
    struct timespec begin;
    struct timespec end;
    double exe_time;

    FILE *fp = fopen("resultados.txt","a");

    if(argc != 2) {  // tam matriz
        printf("Quantidade de argumentos em linha de comando inválida!\n");
        exit(1);
    }

    tam_m = strtol(argv[1], NULL, 10);

    if(tam_m <= 0) {
        printf("Valor de argumento em linha de comando inválido!\n");
        exit(1);
    }

    allocate_matrix(&m3, tam_m);
    srand(time(NULL));
    fill_matrix(&m1, tam_m);
    fill_matrix(&m2, tam_m);

    // printf("\n");

    timespec_get(&begin, TIME_UTC);
    mm();
    timespec_get(&end, TIME_UTC);

    free_matrix(m1, tam_m);
    free_matrix(m2, tam_m);
    free_matrix(m3, tam_m);

    exe_time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    // printf("\n");
    // printf("Tempo de execução: %lf\n", exe_time);

    fprintf(fp, "%d %lf\n", tam_m, exe_time);
    fclose(fp);

    exit(0);
}

void mm() {
    for(int i = 0; i < tam_m; i++) {  // Linha
        for(int j = 0; j < tam_m; j++) {  // Coluna
            for(int k = 0; k < tam_m; k++) {  // Elementos
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            // printf("%f ", m3[i][j]);
        }
        // printf("\n");
    }
}
