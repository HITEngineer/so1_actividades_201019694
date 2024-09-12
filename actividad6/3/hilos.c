#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Hilos in process %d\n", getpid());
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
