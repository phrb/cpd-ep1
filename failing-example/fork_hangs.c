#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void a(){
    #pragma omp parallel num_threads(2)
    {
        puts("para_a");
    }
    puts("a ended");
}
void b(){
    #pragma omp parallel num_threads(2)
    {
        puts("para_b");
    }
    puts("b ended");
}
int main(){
    a(); //Inicializa uma thread pool no processo pai.
    int p = fork();
    if(!p){
        printf("id=%d\n", p);
        b(); // Inicializa uma thread pool no processo filho.
        _exit(0);
    }
    else{
        printf("id=%d\n", p); // Dentro do processo pai.
    }
    wait(NULL); // Espera que b() retorne o controle.
    return 0;
}
