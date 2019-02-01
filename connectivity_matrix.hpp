//
// Created by Ivan on 2019-02-01.
//

#ifndef PAGERANK_CONNECTIVITY_MATRIX_HPP
#define PAGERANK_CONNECTIVITY_MATRIX_HPP

#include "matrix.hpp"

class connectivity_matrix : public matrix {
    const double P_FACTOR = 0.85;

public:
    matrix& calc_importance();

private:
    /**
     * sum the values of a given column number 'col'
     * @param col  column number, start from 1
     * @return double value, the sum of the given column
     */
    double sumColumn(int col) const;
};
#endif //PAGERANK_CONNECTIVITY_MATRIX_HPP
