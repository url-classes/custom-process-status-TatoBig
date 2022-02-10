#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fork_result;
    fork_result = fork();
    if (fork_result >= 1)
    {
        printf("Soy el proceso padre\n");
    }
    else if (fork_result == 0)
    {
        printf("Soy el proceso hijo\n");
    }
    else
    {
        printf("Error al crear el proceso\n");
    }
    return 0;
}