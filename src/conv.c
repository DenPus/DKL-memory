/*
 * conv.c
 *
 * Convert size
 * ============
 * Convert size by format to string
 *
 * Author     :   denkar
 * Created    :   29.08.19 15:25 (base 24.05.19 15:50)
 *
 * Copyright (c) 2019 DenKar <denkar@mail.ru>
 */

#include "conv.h"
#include <stdio.h>

struct dmem_fmt_item_s dmem_fmt_ls[8] = {
        {
                .id = DMEM_FMT_B,
                .name = "b",
                .title = "bite",
                .val = 0l,
                .byte = 0l,
        },
        {
                .id = DMEM_FMT_BT,
                .name = "bt",
                .title = "byte",
                .val = 8l,
                .byte = DMEM_SZ_BT,
        },
        {
                .id = DMEM_FMT_KB,
                .name = "kb",
                .title = "Kbyte",
                .val = 8l * 1024,
                .byte = DMEM_SZ_KB,
        },
        {
                .id = DMEM_FMT_MB,
                .name = "mb",
                .title = "Mbyte",
                .val = 8192l * 1024,
                .byte = DMEM_SZ_MB,
        },
        {
                .id = DMEM_FMT_GB,
                .name = "gb",
                .title = "Gbyte",
                .val = 8192l * 1024 * 1024,
                .byte = DMEM_SZ_GB,
        },
        {
                .id = DMEM_FMT_TB,
                .name = "tb",
                .title = "Tbyte",
                .val = 8192l * 1024 * 1024 * 1024,
                .byte = DMEM_SZ_TB,
        },
};

dmem_fmt_item_t *mem_get_fmt_item(size_t mem, enum dmem_fmt_e fmt) {
    int i;
    dmem_fmt_item_t *mem_fmt_item = NULL;

    if (!fmt) {
        for (i = 0; i < 8; i++) {
            dmem_fmt_item_t *_mem_fmt_item = &dmem_fmt_ls[i];

            if (mem < _mem_fmt_item->val) {
                mem_fmt_item = &dmem_fmt_ls[i - 1];

                break;
            }
        }
    }

    return mem_fmt_item;
}

int memconv(char *dest, size_t *src, enum dmem_fmt_e fmt) {
    double         val;
    dmem_fmt_item_t *mem_fmt_item = mem_get_fmt_item(*src, fmt);

    if (mem_fmt_item->val > 0) {
        val = (double) *src / mem_fmt_item->val;
    } else {
        val = *src;
    }

    int size = sprintf(dest, "%.2f %s", val, mem_fmt_item->name);

    return size;
}
