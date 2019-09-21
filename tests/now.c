/*
 * 
 * Author:   denkar
 * Created:  21.09.19 16:21
 */

#include "dtest.h"
#include "../src/now.c"

CASE(kb) {
        assert_le(1, memnow(0));
}

SUITE(kb);

