#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "mm_aux.h"

// m3 = m1*m2
float **m1;
float **m2;
float **m3;
int tam_m;
int qtd_t;

void *mm(void *t_id);
void start_threads();
   
int main(int argc, char *argv[]) {
    pthread_t *ts;
    int *ts_ids;
    struct timespec begin;
    struct timespec end;
    double exe_time;
    FILE *fp = fopen("resultados.txt","a");

    if(fp == NULL) {
        printf("Erro ao escrever em arquivo!\n");
        exit(1);
    }

    if(argc != 3) {  // tam matriz - qtd threads
        printf("Quantidade de argumentos em linha de comando inválida!\n");
        exit(1);
    }

    tam_m = strtol(argv[1], NULL, 10);
    qtd_t = strtol(argv[2], NULL, 10);

    // printf("%d", tam_m);
    if(tam_m <= 0 || qtd_t <= 0) {
        printf("Valores de argumentos em linha de comando inválidos!\n");
        exit(1);
    }

    alocate_matrix(&m3, tam_m);
    fill_matrix(&m1, tam_m);
    fill_matrix(&m2, tam_m);

    // printf("\n");

    timespec_get(&begin, TIME_UTC);
    ts = (pthread_t*) calloc(qtd_t, sizeof(pthread_t));
    ts_ids = (int*) calloc(qtd_t, sizeof(int));
    for(int i = 0; i < qtd_t; i++) {
        ts_ids[i] = i;

        pthread_create(&(ts[i]), NULL, &mm, &ts_ids[i]);
    }
    for(int i = 0; i < qtd_t; i++) {
        pthread_join(ts[i], NULL);
    }
    timespec_get(&end, TIME_UTC);

    exe_time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    // printf("Tempo de execução: %lf\n", exe_time);

    fprintf(fp, "%d %d %lf\n", tam_m, qtd_t, exe_time);

    fclose(fp);

    exit(0);
}

void *mm(void *t_id) {
    for(int i = *(int*)t_id; i < tam_m; i+=qtd_t) {  // Linha
        for(int j = 0; j < tam_m; j++) {  // Coluna
            for(int k = 0; k < tam_m; k++) {  // Elementos
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            // printf("%f ", m3[i][j]);
        }
        // printf("\n");
    }
}
