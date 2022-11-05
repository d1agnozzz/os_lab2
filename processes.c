#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "time_funcs.h"


int main(){
    pid_t pid1;
    pid_t pid2;
    int status;

    pid1 = fork();
    // wait(&status);

    if (pid1 != 0) {
        pid2 = fork();
        // wait(&status);
    }

    if (pid1 == -1 || pid2 == -1) {
        printf("Ошибка вызова fork\n");
    } else if (pid1 == 0 || pid2 == 0) {
        printf("Это дочерний процесс\tpid = %d\tродительский pid = %d ", getpid(), getppid());
    } else {
        printf("Это родительский процес\tpid = %d ", getpid());

        // printf("> ps -x\n");
        char buffer[50];
        snprintf(buffer, sizeof buffer, "ps -x | grep -e %d -e %d", pid1, pid2);
        system(buffer);
    }

    char time_with_msecs[25];
    get_time_with_msecs(time_with_msecs, 25);

    printf("время: %s.%lld\n", time_with_msecs, todays_msec());
    return 0;
}