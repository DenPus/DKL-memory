/*
 * dkl-mem.h
 *
 * Headers dkl-mem
 * =============
 * DKL library get memory size form devices
 *
 * Author   :   denkar
 * Created  :   05.09.19 11:17
 * Homepage :   https://github.com/Denpus/DKL-memory
 * License  :   GPL-2.0
 * Version  :   0.1.5.0
 *
 * Copyright (C) Denis Karabadjak <denkar>
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


extern int memconv(char *dest, size_t *src, enum mem_fmt_e fmt);

#include <stddef.h>

typedef enum memdev_e {
    MEM_DEV_PROCESS,
}                memdev_t;

extern size_t memdev(enum memdev_e dev);


