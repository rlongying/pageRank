//
// Created by Ivan on 2019-01-31.
//

#ifndef PAGERANK_UTILITIES_HPP
#define PAGERANK_UTILITIES_HPP
//if the difference between two doubles is not greater than
//TOLERANCE, then those two doubles are essentially the same.
const double TOLERANCE = 0.000001;
const int TOLERANCE_FACTOR = 1000000;

bool isEqual(const double& d1, const double& d2);
#endif //PAGERANK_UTILITIES_HPP
