//
// Created by Ivan on 2019-01-29.
//

#include "matrix.hpp"

matrix::matrix():value({{0.0}}) {

}

matrix::matrix(double *input) {

}

void matrix::clear() {
    size_t rows = value.size();

    if(rows > 0){
        for(int i = 0; i < rows; i++){

            size_t cols = value[i].size();
            for(int j = 0; j < cols; j++){
                value[i][j] = 0.0;
            }
        }

    }

}

matrix::matrix(int n) {

}

matrix::matrix(int r, int c) {

}

void matrix::set_value(int row, int col, double newVal) {

}

double matrix::get_value(int row, int col) {
    return 0;
}


