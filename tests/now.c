/*
 * 
 * Author:   denkar
 * Created:  21.09.19 16:21
 */

#include "dtest.h"
#include "../src/dev.c"

CASE(kb) {
        assert_le(1, memdev(0));
}

SUITE(kb);

