//
// Created by Ivan on 2019-01-29.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <iostream>
#include <vector>

class matrix {

protected:
    std::vector<std::vector<double>> dataMatrix;

    /**
     * sum of the value of a given column
     * @param col  column number, start from 1
     * @return the sum of the column
     */
    double sumColumn(int col) const;

public:

    /**
     * populate a matrix of size 1 with value 0.0
     */
    matrix();

    /**
     * populate a matrix of given size n, and initilize each element with value 0.0
     * @param n size of matrix
     */
    matrix(int n);

    //copy constructor
    matrix(const matrix &other) : dataMatrix(other.dataMatrix) {

    }

    /**
     * populate a r*c matrix, and initilize each element with value 0.0
     * throw exception if r <= 0 or c <= 0
     * @param r row
     * @param c column
     */
    matrix(int r, int c);

    /**
     * populate a n*n matrix by a given vector
     * throw exception if the size of input vector does not have a square root
     * @param input : input vector
     */
    matrix(const std::vector<double> &input);

    /**
     * set the value of specified (row, col) to a new value
     * @param row :the row of the target, start from 1
     * @param col :the column of the target, start from 1
     * @param newVal :new value
     */
    void set_value(const int row, const int col, const double newVal);

    /**
     * get the value from specified location (row, col)
     * @param row :target row, start from 1
     * @param col :target col, start from 1
     * @return
     */
    double get_value(int row, int col) const;

    size_t get_col() const;

    /**
     * set all values in the matrix to 0.0
     */
    void clear();

    /**
     * increment every element of matrix by 1.0
     * @return itself
     */
    matrix &operator++();

    matrix operator++(int);

    /**
     * decrement every element of matrix by 1.0
     * @return itself
     */
    matrix &operator--();

    matrix operator--(int);

    matrix &operator=(matrix other);

    matrix &operator+=(const matrix &rhm);

    matrix &operator-=(const matrix &rhm);

    /**
     * overload *=, multiply a matrix by a matrix
     * @param rhm
     * @return
     */
    matrix &operator*=(const matrix &rhm);

    /**
     * scale a matrix
     * @param rhs scaler
     * @return
     */
    matrix &operator*=(const double &rhs);

    ~matrix();

    /**
     * convert this matrix to a probability matrix
     * @return itself
     */
    matrix &calc_probability();

    /**
     * convert matrix to a one dimension vector
     * @return a one dimension vector contains all values in matrix
     */
    std::vector<double> vectorize() const;

private:

    /**
     * output the matrix in a square format
     * @param os  output stream
     * @param data matrix to be output
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const matrix &data);

    //compare two matrix
    friend bool operator==(const matrix &lhm, const matrix &rhm);

    friend bool operator!=(const matrix &lhm, const matrix &rhm);

    friend void mySwap(matrix &first, matrix &second);

    friend matrix operator+(matrix lhm, const matrix &rhm);

    friend matrix operator-(matrix lhm, const matrix &rhm);

    friend matrix operator*(matrix lhm, const matrix &rhm);

    //overload * to scale the matrix
    friend matrix operator*(const double &lhs, matrix rhm);

    friend matrix operator*(matrix lhm, const double &rhs);

};


#endif //PAGERANK_MATRIX_HPP
