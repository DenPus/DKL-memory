/*
 * 
 * Author:   denkar
 * Created:  28.09.19 9:23
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

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


char *memconv(char *dest, size_t *src, enum mem_fmt_e fmt);
