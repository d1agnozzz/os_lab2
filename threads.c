#include <stdio.h>
#include <pthread.h>
#include "time_funcs.h"

void *thread_func(void *vararg) {
    pthread_t thread_id = pthread_self();

    char curtime[15];
    get_time_with_msecs(&curtime, 15);

    printf("Child Thread Id: %u Parent Thread PID: %u Time: %s.%lld\n", thread_id, getpid(), curtime, todays_msec());
}

int main() {
    int unused_var;
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    char curtime[15];
    get_time_with_msecs(&curtime, 15);

    printf("Main Thread PID: %u Time: %s.%lld\n", getpid(), curtime, todays_msec());

    return 0;
}