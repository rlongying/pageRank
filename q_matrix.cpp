//
// Created by Ivan on 2019-02-01.
//
#include "q_matrix.hpp"

q_matrix::q_matrix(int n) : matrix(n) {
    double value = 1.0 / (double)n;

    for (int i = 0; i < dataMatrix.size(); i++) {
        for (int j = 0; j < dataMatrix[i].size(); j++) {
            dataMatrix[i][j] = value;
        }
    }

}
