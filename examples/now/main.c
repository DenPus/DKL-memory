/*
 * 
 * Author:   denkar
 * Created:  28.08.19 16:03
 */

#include <dkl-memory.h>
#include <stdio.h>

int main(void) {
    mem_t mem;
    char mem_str[40];
    char conv_str[50];

    mem = memnow(MEM_DEV_PROCESS);
    memconv(mem_str, &mem, 0);
    printf("-- MEM_DEV_PROCESS -> %lu\n   %s -> %s\n", mem, mem_str, conv_str);

    return 0;
}
