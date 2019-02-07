//
// Created by Ivan on 2019-01-29.
//

#include <cmath>
#include <iomanip>
#include <stddef.h>
#include <math.h>
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

void matrix::set_value(const int row, const int col, const double newVal) {
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

matrix::~matrix() {

}

std::ostream &operator<<(std::ostream &os, const matrix &data) {


    for (int i = 0; i < data.dataMatrix.size(); i++) {
        for (int j = 0; j < data.dataMatrix[i].size(); j++) {
            os << std::setw(4) << std::left << data.dataMatrix[i][j] << " ";
        }
        os << std::endl;
    }
    os << std::endl;

    return os;
}


bool operator==(const matrix &lhm, const matrix &rhm) {

    if (lhm.dataMatrix.size() != rhm.dataMatrix.size()) {
        return false;
    }

    for (int i = 0; i < lhm.dataMatrix.size(); i++) {
        if (lhm.dataMatrix[i].size() != rhm.dataMatrix[i].size()) {
            return false;
        }

        for (int j = 0; j < lhm.dataMatrix[i].size(); j++) {

            if (!isEqual(lhm.dataMatrix[i][j], rhm.dataMatrix[i][j])) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const matrix &lhm, const matrix &rhm) {
    return !(lhm == rhm);
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

matrix operator+(matrix lhm, const matrix &rhm) {
    lhm += rhm;
    return lhm;
}

matrix operator-(matrix lhm, const matrix &rhm) {
    lhm -= rhm;
    return lhm;
}

matrix &matrix::operator*=(const matrix &rhm) {
    if (rhm.dataMatrix.empty() || dataMatrix.empty()) {
        throw std::invalid_argument("matrix can not be empty");
    }

    //columns # of first operand should be equal to rows # of second operand
    if((dataMatrix[0].size() != rhm.dataMatrix.size())){

        throw std::invalid_argument
        ("number of columns of first operand should be equal to number of rows of second operand!");
    }

    std::vector<std::vector<double>> temp;

    //row numbers
    for(int i = 0; i < dataMatrix.size(); i++){

        std::vector<double> tempRow;
        //column numbers
        for(int j = 0; j < rhm.dataMatrix[0].size(); j++){

            double tempValue = 0.0;
            for(int k = 0; k < dataMatrix[i].size(); k++){
                tempValue += dataMatrix[i][k] * rhm.dataMatrix[k][j];
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

matrix operator*(matrix lhm, const matrix &rhm) {
    lhm *= rhm;
    return lhm;
}

double matrix::sumColumn(int col) const {
    validatePositive(col);

    if(!dataMatrix.empty()){
        if(dataMatrix[0].size() < col){
            throw std::invalid_argument("the input column number if too large when sum the column!");
        }
    }

    double sum = 0.0;

    for(int i = 0; i < dataMatrix.size(); i++){
        sum += dataMatrix[i][col-1];
    }

    return sum;
}

matrix &matrix::calc_probability() {
    if(!dataMatrix.empty()){

        //columns
        for(int i = 0; i < dataMatrix[0].size(); i++){
            double sum = sumColumn(i+1);

            //rows
            double rows = dataMatrix.size();
            double zero_replacement = 1.0 / rows;
            for(int j = 0; j < rows; j++){
                if(isEqual(0.0, sum)){
                    dataMatrix[j][i] = zero_replacement;
                }else{
                    dataMatrix[j][i] /= sum;
                }
            }
        }
    }

    return *this;
}

matrix operator*(const double& lhs, matrix rhm) {
    return operator*(rhm, lhs);
}

matrix operator*(matrix lhm, const double &rhs) {
    lhm *= rhs;
    return lhm;
}

matrix &matrix::operator*=(const double &rhs) {

    if(isEqual(0.0, rhs)){
        (*this).clear();
        return *this;
    }

    for (int i = 0; i < dataMatrix.size(); i++) {
        for(int j = 0; j < dataMatrix[i].size(); j++){
            dataMatrix[i][j] *= rhs;
        }
    }
    return *this;
}

size_t matrix::get_col() const {
    return dataMatrix[0].size();
}

std::vector<double> matrix::vectorize() const {
    std::vector<double> temp;

    for(std::vector<double> v:dataMatrix){
        for (double d:v) {
            temp.push_back(d);
        }
    }

    return temp;
}


