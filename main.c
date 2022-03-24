#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("%-20s%-10s%-10s%-23s%-15s\n", "Tipo de proceso", "PID ", "PPID", "Fecha y hora", "Padre/Hijo");
    printf("%-10s\n", "--------------------------------------------------------------------------------");

    int fork_result;
    fork_result = fork();
    fork_result = fork();
    fork_result = fork();

    if (fork_result >= 1)
    {
        time_t tiempo = time(NULL);
        struct tm tiempoFormato = *localtime(&tiempo);
        printf("%-20s%-10d%-10d%02d-%02d-%d %02d:%02d:%-5.02d %-25s\n", "Proceso del sistema", getpid(), getppid(), tiempoFormato.tm_mday, tiempoFormato.tm_mon + 1, tiempoFormato.tm_year + 1900, tiempoFormato.tm_hour, tiempoFormato.tm_min, tiempoFormato.tm_sec, "Padre");
    }
    else if (fork_result == 0)
    {
        time_t tiempo = time(NULL);
        struct tm tiempoFormato = *localtime(&tiempo);
        printf("%-20s%-10d%-10d%02d-%02d-%d %02d:%02d:%-5.02d %-25s\n", "Proceso del sistema", getpid(), getppid(), tiempoFormato.tm_mday, tiempoFormato.tm_mon + 1, tiempoFormato.tm_year + 1900, tiempoFormato.tm_hour, tiempoFormato.tm_min, tiempoFormato.tm_sec, "Hijo");
    }
    else
    {
        printf("Error al crear el proceso\n");
    }
    return 0;
}