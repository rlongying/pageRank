//
// Created by Ivan on 2019-01-29.
//

#include <cmath>
#include "matrix.hpp"

matrix::matrix() : dataMatrix({{0.0}}) {

}

matrix::matrix(const std::vector<double> &input) {
    if (input.size() == 0) {
        throw std::invalid_argument("input vector can not be empty!");
    }

    size_t inputSize = input.size();

    int squareRoot = sqrt(inputSize);

    if (inputSize != (squareRoot * squareRoot)) {
        throw std::invalid_argument("input vector size should has a integer square root, like size = n*n");
    }

    for (int i = 0; i < squareRoot; i++) {
        //initialize each row from the input
        //rowData(input.begin() + i * squareRoot: is the begin place, included
        //input.begin() + (i + 1) * squareRoot: is the end place, not included
        std::vector<double>
                rowData(input.begin() + i * squareRoot, input.begin() + (i + 1) * squareRoot);

        dataMatrix.push_back(rowData);
    }
}

void matrix::clear() {
    size_t rows = dataMatrix.size();

    if (rows > 0) {
        for (int i = 0; i < rows; i++) {

            size_t cols = dataMatrix[i].size();
            for (int j = 0; j < cols; j++) {
                dataMatrix[i][j] = 0.0;
            }
        }
    }
}

matrix::matrix(int n) {

    validatePositive(n);

    for (int i = 0; i < n; i++) {
        dataMatrix.push_back(std::vector<double>(n, 0.0));
    }

}

matrix::matrix(int r, int c) {

    validatePositive(r);
    validatePositive(c);


    for (int i = 0; i < r; i++) {
        dataMatrix.push_back(std::vector<double>(c, 0.0));
    }
}

void matrix::set_value(const int row, const int col, double newVal) {
    validatePositive(row);
    validatePositive(col);

    if (!dataMatrix.empty()) {
        if (row >= dataMatrix.size()) {
            throw std::out_of_range("input row is out of the range of this matrix(start with 1)");
        }

        if (col >= dataMatrix[row - 1].size()) {
            throw std::out_of_range("input column is out of the range of this matrix(start with 1)");
        }

        dataMatrix[row - 1][col - 1] = newVal;
    } else {
        throw std::invalid_argument("empty matrix!");
    };

}

double matrix::get_value(int row, int col) const {

    validatePositive(row);
    validatePositive(col);

    if (!dataMatrix.empty()) {
        if (row >= dataMatrix.size()) {
            throw std::out_of_range("input row is out of the range of this matrix(start with 1)");
        }

        if (col >= dataMatrix[row - 1].size()) {
            throw std::out_of_range("input column is out of the range of this matrix(start with 1)");
        }

        return dataMatrix[row - 1][col - 1];
    } else {
        throw std::invalid_argument("empty matrix!");
    };

}

void matrix::validatePositive(int size) const{
    if (size <= 0) {
        throw std::invalid_argument("the number of rows and columns should be greate than 0!");
    }

}

matrix::~matrix() {

}

void matrix::print() const {


    for (int i = 0; i < dataMatrix.size(); i++) {
        for (int j = 0; j < dataMatrix[i].size(); j++) {
            std::cout << dataMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "=====================" << std::endl;
}



