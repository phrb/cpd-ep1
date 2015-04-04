#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void a()
{
    #pragma omp parallel num_threads(2)
    {
        puts("para_a"); // output twice
    }
    puts("a ended"); // output once
}

void b()
{
    #pragma omp parallel num_threads(2)
    {
        puts("para_b");
    }
    puts("b ended");
}

int main()
{
    int p = fork(); // Cria o processo filho antes de incializar o OpenMP.
    if(!p)
    {
        printf("id=%d\n", p);
        b(); // Cria uma thread pool no processo filho.
        _exit(0);
    }
    else
    {
        printf("id=%d\n", p);
        a(); // Cria uma thread pool no processo pai.
    }
    wait(NULL); // Espera que b() retorne o controle.
    return 0;
}
