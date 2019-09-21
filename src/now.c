/*
 * 
 * Author:   denkar
 * Created:  29.08.19 16:06 (base 31.05.19 13:26)
 *
 * Get current memory from devices
 */

#include "main.h"

/* static */

static uint8_t mem_devices[7] = {
        /*CLOCK_MONOTONIC_ACTIVE*/
};

/* public */

size_t memnow(enum mem_device_e dev) {
    if (dev > 6) {
        dev = 0;
    }

    struct rusage ys;

    getrusage(1, &ys);

    size_t dest = (size_t )ys.ru_maxrss;

    return dest;
}
