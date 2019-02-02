//
// Created by Ivan on 2019-01-31.
//

#ifndef PAGERANK_UTILITIES_HPP
#define PAGERANK_UTILITIES_HPP

#include <vector>
#include "matrix.hpp"

//if the difference between two doubles is not greater than
//TOLERANCE, then those two doubles are essentially the same.
const double TOLERANCE = 0.0001;
const double P_FACTOR = 0.85;

/**
 * compare double number within a tolerance
 * @param d1
 * @param d2
 * @return true, if |d1-d2| < tolerance, otherwise false
 */
bool isEqual(const double& d1, const double& d2);

/**
 * validate if a number is positive, throw exception if <= 0
 * @param size
 */
void validatePositive(const int size);

/**
 * rank pages
 * @param m , a given connectivity matrix of pages
 * @return a vector containing the rankings of pages
 */
std::vector<double> rank_page(matrix& m);

/**
 * populate a matrix from a file
 * @param filepath
 * @return a matrix. throw exception is file can not be open
 */
matrix read_matrix_file(std::string filepath);

/**
 * calucate the transitive matrix
 * @param s
 * @return
 */
matrix calc_transition(const matrix &s);

/**
 * Markov process
 * @param transite_m
 * @return the rank matrix
 */
matrix markov(matrix& transite_m);

void report_rank(std::vector<double>& rank);

#endif //PAGERANK_UTILITIES_HPP
