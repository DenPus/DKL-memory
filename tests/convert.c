/*
 * 
 * Author:   denkar
 * Created:  21.09.19 15:22
 */

#include "dtest.h"
#include "../src/convert.c"

CASE(kb) {
    char dst[100];
    size_t i = 1024 * 8;

    assert_eq("1.00 kb", memconv(dst, &i, 0));
    assert_eq(8192, i);
}

CASE(kb2) {
    char dst[100];
    size_t i = 1536 * 8;

    assert_eq("1.50 kb", memconv(dst, &i, 0));
    assert_eq(12288, i);
}


CASE(mb) {
    char dst[100];
    size_t i = 1024 * 8 * 1024;

    assert_eq("1.00 mb", memconv(dst, &i, 0));
    assert_eq(8388608, i);
}

CASE(mb2) {
    char dst[100];
    size_t i = 1536 * 8 * 1024;

    assert_eq("1.50 mb", memconv(dst, &i, 0));
    assert_eq(12582912, i);
}

SUITE(kb, kb2, mb, mb2);
