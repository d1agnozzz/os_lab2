#include <time.h>
#include <stdlib.h>

long long current_timestamp_msec() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

long long todays_msec() {
    return current_timestamp_msec() % 31540000000 % 86400000 % 3600000 % 60000 % 1000;
}

void get_time_with_msecs(char *buffer, size_t length) {
    struct tm *curtime_struct;
    time_t curtime;
    time(&curtime);

    curtime_struct = localtime(&curtime);

    strftime(buffer, length, "%H:%M:%S", curtime_struct);
}