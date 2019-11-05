/*
 * 
 * Author:   denkar
 * Created:  28.08.19 16:03
 */

#include <dkl-memory.h>
#include <stdio.h>

int main(void) {
    size_t mem;
    char   mem_str[40];
    char   conv_str[50];

    mem = memdev(MEM_DEV_PROCESS) * 8;
    int nconv_str = memconv(mem_str, &mem, 0);

    printf(
            "-- MEM_DEV_PROCESS -> %lu\n   %s -> %.*s\n", mem, mem_str,
            nconv_str, conv_str
    );

    return 0;
}
