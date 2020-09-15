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
 * Version  :   0.1.6.0
 *
 * Copyright (C) Denis Karabadjak <denkar>
 */

#pragma once

#include <stdint.h>
#include <stddef.h>

typedef enum dmem_fmt_e {
    DMEM_FMT_B,
    DMEM_FMT_BT,
    DMEM_FMT_KB,
    DMEM_FMT_MB,
    DMEM_FMT_GB,
    DMEM_FMT_TB,
} dmem_fmt_t;

#define DMEM_SZ_BT 1l
#define DMEM_SZ_KB 1024l
#define DMEM_SZ_MB (1024l * 1024l)
#define DMEM_SZ_GB (1024l * 1024l * 1024l)
#define DMEM_SZ_TB (1024l * 1024l * 1024l * 1024l)

typedef struct dmem_fmt_item_s {
    uint8_t id;
    char    name[5];
    char    title[20];
    int64_t  val;
    uint64_t byte;
} dmem_fmt_item_t;

struct dmem_fmt_item_s dmem_fmt_ls[8];

extern int memconv(char *dest, size_t *src, enum dmem_fmt_e fmt);

#define dmem_tobyte(src, fmtin) (src * fmtin)

#include <stddef.h>

typedef enum memdev_e {
    MEM_DEV_PROCESS,
}                memdev_t;

extern size_t memdev(enum memdev_e dev);

#include <stddef.h>

typedef void *(*dmem_allocate_t)(void *ptr, size_t size);

extern void *dmem_alloc(void *ptr, size_t size);

extern void *dmem_realloc(void *ptr, size_t size);

extern void *dmem_free(void *ptr, size_t size);

extern void* dmem_shared(size_t size);
