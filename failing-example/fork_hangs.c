#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void a()
{
    #pragma omp parallel num_threads(2)
    {
        puts("para_a");
    }
    puts("a ended");
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
    a();
    int p = fork();
    if(!p)
    {
        printf("id=%d\n", p);
        b();
        _exit(0);
    }
    else
    {
        printf("id=%d\n", p);
    }
    wait(NULL);
    return 0;
}
