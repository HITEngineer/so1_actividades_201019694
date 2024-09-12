
# Actividad 6 – Procesos e Hilos

## Problema 1: ¿Cuántos procesos son creados?

### Pregunta
¿Cuántos procesos son creados, incluyendo el proceso inicial, por el siguiente programa?

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
```

### Respuesta y Razonamiento

Este programa contiene tres llamadas a la función `fork()`. Cada llamada a `fork()` crea un nuevo proceso hijo. 
El número de procesos totales es 2^n, donde n es el número de veces que se llama a `fork()`.

- **Primera llamada a `fork()`**: se crean 2 procesos (proceso padre y proceso hijo).
- **Segunda llamada a `fork()`**: se crean 4 procesos.
- **Tercera llamada a `fork()`**: se crean 8 procesos.

En total, el número de procesos creados, incluyendo el proceso inicial, es 8. Cada uno de estos procesos imprime "Proceso creado".

![Captura del proceso](./home/ubuntu/Pictures/Screenshots/E1.png)



## Problema 2: Proceso Zombie

### Descripción del Código

El siguiente programa en C crea un proceso hijo que se convierte en un proceso zombie por un tiempo determinado (60 segundos):

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Proceso padre: duerme por 60 segundos
        sleep(60);
        // Espera al proceso hijo
        wait(NULL);
    } else if (pid == 0) {
        // Proceso hijo: termina inmediatamente
        exit(0);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
```

### Comando `ps -l` para visualizar el proceso zombie:

```bash
ps -l
```

Este comando muestra la lista de procesos, incluyendo el proceso zombie con el estado `Z`.

![Captura del proceso zombie](./home/ubuntu/Pictures/Screenshots/E2.png)



## Problema 3: Procesos e Hilos

### Pregunta
¿Cuántos procesos y cuántos hilos son creados por el siguiente programa?

### Código

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Hilo ejecutándose en el proceso %d\n", getpid());
    return NULL;
}

int main() {
    pthread_t thread;
    pid_t pid = fork();

    if (pid == 0) {
        // Proceso hijo
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL);
    } else if (pid > 0) {
        // Proceso padre
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL);
    } else {
        perror("fork");
    }

    return 0;
}
```

### Respuesta

- **Procesos creados**: Este programa crea 2 procesos únicos (el proceso padre y el proceso hijo).
- **Hilos creados**: Cada proceso (padre e hijo) crea un hilo, por lo tanto, se crean 2 hilos únicos.

![Captura del hilo](./home/ubuntu/Pictures/Screenshots/E3.png)


git clone https://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@github.com/HITEngineer/so1_actividades_201019694.git
