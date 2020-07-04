/*
 * dmem_allocate.c
 *
 * dmem_allocate()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Sat Jul  4 10:44:16 2020
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 */

#include "dmem_allocate.h"
#include <stdlib.h>

void *dmem_realloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}

void *dmem_alloc(void *ptr, size_t size) {
    return malloc(size);
}

void *dmem_free(void *ptr, size_t size) {
    free(ptr);
    return 0;
}
