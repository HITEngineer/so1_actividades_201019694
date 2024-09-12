#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Proceso padre: duerme 60 segundos
        sleep(60);
        // Espera al proceso hijo para que salga del estado zombie
        wait(NULL);
    } else if (pid == 0) {
        // Proceso hijo: termina inmediatamente
        exit(0);
    } else {
        // Error al crear el proceso
        perror("fork");
        return 1;
    }

    return 0;
}
