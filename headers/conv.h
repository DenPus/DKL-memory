/*
 * 
 * Author:   denkar
 * Created:  28.09.19 9:23
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
