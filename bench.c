// BENCHMARKING

#include <time.h>
#include <inttypes.h>
#include <string.h>
#include "arith.h"
#include "bench.h"


// Returns nanoseconds on the clock
uint64_t cpucycles(void){
    struct timespec time;

    clock_gettime(CLOCK_REALTIME, &time);
    return (int64_t)(time.tv_sec*1e9 + time.tv_nsec);
}


const char* print_num(double a){
    static char t[256], buffer[256];
    memset(t, 0, sizeof(t)); 
    int len;

    snprintf(t, 256, "%" PRIu64, (uint64_t)a);
    len = strlen(t);

    int j = 0;
    for(int i = 0; i < len; i++){
        if( i > 0 && (len - i )% 3 == 0)
            buffer[j++] = '\'';
        buffer[j++] = t[i];
    }
    buffer[j] = '\0';

    return buffer;
}


