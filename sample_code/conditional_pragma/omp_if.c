#include <stdio.h>
#include <omp.h>

void test(int val){
    #pragma omp parallel num_threads(val) if (val)
    if (omp_in_parallel()){
        #pragma omp single
        printf("val = %d, parallelized with %d threads\n",
                 val, omp_get_num_threads());
    }
    else{
        printf("val = %d, serialized, threads = %d\n", val, omp_get_num_threads());
    }
}

int main(){
    //omp_set_num_threads(2);
    test(0);
    test(2);
    test(3);
    test(6);
    return 0;
}
