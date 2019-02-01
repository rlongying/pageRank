//
// Created by Ivan on 2019-01-31.
//
#include <cmath>
#include <stdexcept>
#include "utilities.hpp"

bool isEqual(const double &d1, const double &d2){

    // round difference to the precision of TOLERANCE
    double diff = ceil(fabs(d1 - d2) / TOLERANCE) * TOLERANCE;
    return (diff <= TOLERANCE);
}

void validatePositive(const int size) {
    if (size <= 0) {
        throw std::invalid_argument("the number of rows and columns should be greate than 0!");
    }

}