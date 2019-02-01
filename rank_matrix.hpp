//
// Created by Ivan on 2019-02-01.
//

#ifndef PAGERANK_RAND_MATRIX_HPP
#define PAGERANK_RAND_MATRIX_HPP

#include "matrix.hpp"

class rank_matrix : public matrix {
    const double ELEMENT_VALUE = 1.0;

public:
    rank_matrix(int n);
};

#endif //PAGERANK_RAND_MATRIX_HPP
