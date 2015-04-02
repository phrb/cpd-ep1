#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void nowait_example(int n, int m, float *a, float *b, float *y, float *z){
    int i;
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (i = 0; i < m; i++)
            y[i] = z[i] + b[i];

        #pragma omp for nowait
        for (i = 1; i < n; i++)
            b[i] = (a[i] + a[i-1]) / 2.0;
    }
}

int main(){
    int n =200;
    int m = 200;
    float a[n], b[n];
    float y[m], z[m];

    int i;
    for (i = 0; i < n; i++){
        a[i] = i;
    }
    for (i = 0; i < m; i++){
        z[i] = 2 * i;
    }
    nowait_example(n, m, a, b, y, z);
//    for (i = 1; i < n; i++){
//        assert(b[i] == (a[i] + a[i-1]) / 2.0);
//    }
    for (i = 0; i < n; i++){
      printf("y[%d]=%f ", i, y[i]);
      printf("y=z+b[%d]=%f\n", i, z[i] + b[i]);
      printf("z[%d]=%f ", i, z[i]);
      printf("b[%d]=%f\n", i, b[i]);
    }
//    for (i = 0; i < m; i++){
//        assert(b[i] == z[i] * 3);
//    }
    return 0;
}
