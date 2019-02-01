//
// Created by Ivan on 2019-01-29.
//

#include <cmath>
#include <iomanip>
#include "matrix.hpp"
#include "utilities.hpp"

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
        if (row > dataMatrix.size()) {
            throw std::out_of_range("input row is out of the range of this matrix(start with 1)");
        }

        if (col > dataMatrix[row - 1].size()) {
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
        if (row > dataMatrix.size()) {
            throw std::out_of_range("input row is out of the range of this matrix(start with 1)");
        }

        if (col > dataMatrix[row - 1].size()) {
            throw std::out_of_range("input column is out of the range of this matrix(start with 1)");
        }

        return dataMatrix[row - 1][col - 1];
    } else {
        throw std::invalid_argument("empty matrix!");
    };

}

void matrix::validatePositive(int size) const {
    if (size <= 0) {
        throw std::invalid_argument("the number of rows and columns should be greate than 0!");
    }

}

matrix::~matrix() {

}

std::ostream &operator<<(std::ostream &os, const matrix &data) {


    for (int i = 0; i < data.dataMatrix.size(); i++) {
        for (int j = 0; j < data.dataMatrix[i].size(); j++) {
            std::cout << std::setw(4) << std::left << data.dataMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return os;
}


bool operator==(const matrix &lhs, const matrix &rhs) {

    if (lhs.dataMatrix.size() != rhs.dataMatrix.size()) {
        return false;
    }

    for (int i = 0; i < lhs.dataMatrix.size(); i++) {
        if (lhs.dataMatrix[i].size() != rhs.dataMatrix[i].size()) {
            return false;
        }

        for (int j = 0; j < lhs.dataMatrix[i].size(); j++) {
            double d1 = lhs.dataMatrix[i][j];
            double d2 = rhs.dataMatrix[i][j];
            if (!isEqual(lhs.dataMatrix[i][j], rhs.dataMatrix[i][j])) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const matrix &lhs, const matrix &rhs) {
    return !(lhs == rhs);
}

matrix &matrix::operator++() {

    for (int i = 0; i < dataMatrix.size(); i++) {
        for (int j = 0; j < dataMatrix[i].size(); j++) {
            dataMatrix[i][j] += 1.0;
        }
    }


    return *this;
}

matrix matrix::operator++(int) {
    matrix temp(*this);
    operator++();
    return temp;
}

matrix &matrix::operator--() {

    for (int i = 0; i < dataMatrix.size(); i++) {
        for (int j = 0; j < dataMatrix[i].size(); j++) {
            dataMatrix[i][j] -= 1.0;
        }
    }


    return *this;
}

matrix matrix::operator--(int) {
    matrix temp(*this);
    operator--();
    return temp;
}

matrix &matrix::operator=(matrix other) {
    mySwap(*this, other);

    return *this;
}

void mySwap(matrix &first, matrix &second) {
    std::swap(first.dataMatrix, second.dataMatrix);
}

matrix &matrix::operator+=(const matrix &rhs) {
    if (rhs.dataMatrix.empty() || dataMatrix.empty()) {
        throw std::invalid_argument("matrix can not be empty");
    }

    //compare rows
    if((dataMatrix.size() != rhs.dataMatrix.size()) ||
            //compare columns
                (dataMatrix[0].size() != rhs.dataMatrix[0].size())){

        throw std::invalid_argument("two matrix are not of the same size!");
    }

    for(int i = 0; i < dataMatrix.size(); i++){
        for(int j = 0; j < dataMatrix[i].size(); j++){
            dataMatrix[i][j] += rhs.dataMatrix[i][j];
        }
    }

    return *this;
}

matrix &matrix::operator-=(const matrix &rhs) {
    if (rhs.dataMatrix.empty() || dataMatrix.empty()) {
        throw std::invalid_argument("matrix can not be empty");
    }

    //compare rows
    if((dataMatrix.size() != rhs.dataMatrix.size()) ||
       //compare columns
       (dataMatrix[0].size() != rhs.dataMatrix[0].size())){

        throw std::invalid_argument("two matrix are not of the same size!");
    }

    for(int i = 0; i < dataMatrix.size(); i++){
        for(int j = 0; j < dataMatrix[i].size(); j++){
            dataMatrix[i][j] -= rhs.dataMatrix[i][j];
        }
    }

    return *this;
}

matrix operator+(matrix lhs, const matrix &rhs) {
    lhs += rhs;
    return lhs;
}

matrix operator-(matrix lhs, const matrix &rhs) {
    lhs -= rhs;
    return lhs;
}

matrix &matrix::operator*=(const matrix &rhs) {
    if (rhs.dataMatrix.empty() || dataMatrix.empty()) {
        throw std::invalid_argument("matrix can not be empty");
    }

    //columns # of first operand should be equal to rows # of second operand
    if((dataMatrix[0].size() != rhs.dataMatrix.size())){

        throw std::invalid_argument
        ("number of columns of first operand should be equal to number of rows of second operand!");
    }

    std::vector<std::vector<double>> temp;

    for(int i = 0; i < dataMatrix.size(); i++){

        std::vector<double> tempRow;
        for(int j = 0; j < dataMatrix.size(); j++){

            double tempValue = 0.0;
            for(int k = 0; k < dataMatrix[0].size(); k++){
                tempValue += dataMatrix[i][k] * rhs.dataMatrix[k][j];
            }
            //store every element of new matrix
            tempRow.push_back(tempValue);
        }
        //store a row of new matrix
        temp.push_back(tempRow);
    }

    dataMatrix = temp;
    return *this;
}

matrix operator*(matrix lhs, const matrix &rhs) {
    lhs *= rhs;
    return lhs;
}



