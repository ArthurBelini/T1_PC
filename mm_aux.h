#ifndef MM_AUX
#define MM_AUX

#include <stdio.h>
#include <stdlib.h>

void fill_matrix(float **m, int tam_m) {
    m = (float**) calloc(tam_m, sizeof(float*));

    for(int i = 0; i < tam_m; i++) {
        m[i] = (float*) calloc(tam_m, sizeof(float));
        for(int j = 0; j < tam_m; j++) {
            m[i][j] = (float)rand()/(float)RAND_MAX * 1000;
            // printf("%f\n", m[i][j]);
        }
    }
}

#endif