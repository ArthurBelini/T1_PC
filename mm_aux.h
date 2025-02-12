#include <stdio.h>
#include <stdlib.h>

#ifndef MM_AUX_H
#define MM_AUX_H

void allocate_matrix(float ***m, int tam_m) {
    *m = (float**) calloc(tam_m, sizeof(float*));

    for(int i = 0; i < tam_m; i++) {
        (*m)[i] = (float*) calloc(tam_m, sizeof(float));
    }
}

void fill_matrix(float ***m, int tam_m) {
    *m = (float**) calloc(tam_m, sizeof(float*));

    for(int i = 0; i < tam_m; i++) {
        (*m)[i] = (float*) calloc(tam_m, sizeof(float));
        // printf("\n");
        for(int j = 0; j < tam_m; j++) {
            (*m)[i][j] = (float)rand()/(float)RAND_MAX * 1000;
            // printf("%f ", (*m)[i][j]);
        }
    }
    // printf("\n");
}

void free_matrix(float **m, int tam_m) {
    for(int i = 0; i < tam_m; i++) {
        free(m[i]);
    }

    free(m);
}

#endif
