/*
 * 
 * Author:   denkar
 * Created:  28.09.19 9:20
 */

#pragma once

#include <stddef.h>

typedef enum memdev_e {
    MEM_DEV_PROCESS,
}                memdev_t;

extern size_t memdev(enum memdev_e dev);
