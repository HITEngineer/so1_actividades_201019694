# Actividad 6 - 



## Código del programa

Ejercicio 1: 

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("Proceso creado\n");
    return 0;
}


       Proceso inicial
              |
          fork()
              |
       Proceso P1 -------- Proceso H1
              |                  |
          fork()             fork()
              |                  |
       P1----H2           H1----H3
              |                  |
          fork()             fork()
              |                  |
 P1-H4   H2----H5     H1-H6  H3----H7



-------------------se crean 8 procesos.


# Actividad 6 - Ejercicio 2: 


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


ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    6680    4657  0  80   0 -  2848 do_wai pts/3    00:00:00 bash
4 R  1000    6906    6680 99  80   0 -  3446 -      pts/3    00:00:00 ps




# Actividad 6 - Ejercicio 3: 
