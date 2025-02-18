#include <point.h>

#pragma once

const double D_EPSILON = 0.00000000000001;

const point dirs[] = {
    /*0: left*/ {-1, 0},
    /*1: right*/{1, 0},
    /*2: up*/   {0, -1},
    /*3: down*/ {0, 1},
};