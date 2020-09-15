/*
 * dmem_shared.h
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

#include <unistd.h>
#include <sys/mman.h>

extern void* dmem_shared(size_t size);
