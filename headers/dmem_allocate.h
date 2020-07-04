/*
 * dmem_allocate.h
 *
 * dmem_allocate()
 * ==========
 *
 * Author   :  denkar
 * Created  :  Sat Jul  4 10:44:16 2020)
 *
 * Copyright (C) Denis Karabadjak <denkar_mail.ru>
 *
 * Used for general interface API
 */

#pragma once

#include <stddef.h>

typedef void *(*dmem_allocate_t)(void *ptr, size_t size);

void *dmem_alloc(void *ptr, size_t size);

void *dmem_realloc(void *ptr, size_t size);

void *dmem_free(void *ptr, size_t size);
