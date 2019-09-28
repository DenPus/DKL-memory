/*
 * now.c
 *
 * Memory from device
 * ===================
 * Get current memory size from device
 *
 * Author     :   denkar
 * Created    :   29.08.19 16:06 (base 31.05.19 13:26)
 *
 * Copyright (c) 2019 DenKar <denkar@mail.ru>
 */

#include <sys/resource.h>
#include <dkl-memory/dev.h>

/* static */

static char mem_devices[7] = {
        MEM_DEV_PROCESS
};

/* public */

size_t memdev(enum memdev_e dev) {
    if (dev > 6) {
        dev = 0;
    }

    struct rusage ys;

    getrusage(1, &ys);

    size_t dest = (size_t) ys.ru_maxrss;

    return dest;
}
