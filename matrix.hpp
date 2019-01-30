//
// Created by Ivan on 2019-01-29.
//

#ifndef PAGERANK_MATRIX_HPP
#define PAGERANK_MATRIX_HPP

#include <iostream>
#include <vector>

class matrix {

    std::vector<std::vector<double>> value;

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

    /**
     * populate a r*c matrix, and initilize each element with value 0.0
     * throw exception if r <= 0 or c <= 0
     * @param r row
     * @param c column
     */
    matrix(int r, int c);

    /**
     * populate a n*n matrix by a given array
     * throw exception if the size of input array does not have a square root
     */
    matrix(double input[]);

    /**
     * set the value of specified (row, col) to a new value
     * @param row :the row of the target
     * @param col :the column of the target
     * @param newVal :new value
     */
    void set_value(int row, int col, double newVal);

    /**
     * get the value from specified location (row, col)
     * @param row :target row
     * @param col :target col
     * @return
     */
    double get_value(int row, int col);

    /**
     * set all values in the matrix to 0.0
     */
    void clear();
    ~matrix();

private:

};


#endif //PAGERANK_MATRIX_HPP
