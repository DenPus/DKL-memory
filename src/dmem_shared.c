/*
 * dmem_shared.c
 *
 * dmem_shared()
 * ==========
 * Make memory shared
 *
 * Author   :  denkar
 * Created  :  14.09.20 15:38
 *
 * Copyright (C) Denis Karabadjak <denkar@mail.ru>
 */

#include <sys/mman.h>

void* dmem_shared(size_t size) {
    int protection = PROT_READ | PROT_WRITE,
        visibility = MAP_SHARED | MAP_ANONYMOUS;
    char *ptr     = mmap(0, size, protection, visibility, -1, 0);

    return ptr;
}
