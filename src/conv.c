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

#include <stdio.h>
#include <dkl-memory/conv.h>

struct mem_fmt_item_s mem_fmt_item_ls[8] = {
        {
                .id = MEM_FMT_B,
                .name = "b",
                .title = "bite",
                .val = 0l,
        },
        {
                .id = MEM_FMT_BT,
                .name = "bt",
                .title = "byte",
                .val = 8l
        },
        {
                .id = MEM_FMT_KB,
                .name = "kb",
                .title = "Kbyte",
                .val = 8l * 1024
        },
        {
                .id = MEM_FMT_MB,
                .name = "mb",
                .title = "Mbyte",
                .val = 8192l * 1024
        },
        {
                .id = MEM_FMT_GB,
                .name = "gb",
                .title = "Gbyte",
                .val = 8192l * 1024 * 1024
        },
        {
                .id = MEM_FMT_TB,
                .name = "tb",
                .title = "Tbyte",
                .val = 8192l * 1024 * 1024 * 1024
        },
};

mem_fmt_item_t *mem_get_fmt_item(size_t mem, enum mem_fmt_e fmt) {
    mem_fmt_item_t *mem_fmt_item = NULL;

    if (!fmt) {
        for (uint8_t i = 0; i < 8; ++i) {
            mem_fmt_item_t *_mem_fmt_item = &mem_fmt_item_ls[i];

            if (mem < _mem_fmt_item->val) {
                mem_fmt_item = &mem_fmt_item_ls[i - 1];

                break;
            }
        }
    }

    return mem_fmt_item;
}

char *memconv(char *dest, size_t *src, enum mem_fmt_e fmt) {
    double         val;
    mem_fmt_item_t *mem_fmt_item = mem_get_fmt_item(*src, fmt);

    if (mem_fmt_item->val > 0) {
        val = (double) *src / mem_fmt_item->val;
    } else {
        val = *src;
    }

    sprintf(dest, "%.2f %s", val, mem_fmt_item->name);

    return dest;
}
