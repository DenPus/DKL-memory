/*
 * 
 * Author:   denkar
 * Created:  28.08.19 15:04
 */

#pragma once

#include <stdint.h>

typedef uint64_t mem_t;

typedef enum mem_device_e {
    MEM_DEV_PROCESS,
}                mem_device_t;

typedef enum mem_fmt_e {
    MEM_FMT_B,
    MEM_FMT_BT,
    MEM_FMT_KB,
    MEM_FMT_MB,
    MEM_FMT_GB,
    MEM_FMT_TB,
}                mem_fmt_t;

typedef struct mem_fmt_item_s {
    uint8_t id;
    char    name[5];
    char    title[20];
    int64_t val;
}                mem_fmt_item_t;

extern mem_t memnow(enum mem_device_e dev);

char *memconv(char *dest, mem_t *src, enum mem_fmt_e fmt);
