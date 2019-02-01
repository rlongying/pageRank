//
// Created by Ivan on 2019-01-31.
//
#include <cmath>
#include "utilities.hpp"

bool isEqual(const double &d1, const double &d2){

    // round difference to the precision of TOLERANCE
    double diff = round((d1 - d2) * TOLERANCE_FACTOR) / TOLERANCE_FACTOR;
    return ((0 - TOLERANCE) <= diff && diff <= TOLERANCE);
}