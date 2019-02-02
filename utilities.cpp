//
// Created by Ivan on 2019-01-31.
//
#include <cmath>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include "utilities.hpp"
#include "q_matrix.hpp"
#include "rank_matrix.hpp"

bool isEqual(const double &d1, const double &d2) {

    double diff = round(fabs(d1 - d2) / TOLERANCE) * TOLERANCE;
    return (diff < TOLERANCE);
}

void validatePositive(const int size) {
    if (size <= 0) {
        throw std::invalid_argument("the number of rows and columns should be greate than 0!");
    }

}

matrix read_matrix_file(std::string filepath) {
    std::ifstream readMatrix(filepath);

    if(!readMatrix.is_open()){
        throw std::invalid_argument(filepath + " can not be open!");
    }

    std::vector<double> dataV;
    int data;

    while (readMatrix >> data) {
        dataV.push_back(data);
    }

    return matrix(dataV);
}

std::vector<double> rank_page(matrix &m) {

    m.calc_probability();

    matrix trans_m = calc_transition(m);

    matrix final_rank = markov(trans_m);

    final_rank.calc_probability();

    return final_rank.vectorize();
}

matrix calc_transition(const matrix &s) {

    q_matrix q(s.get_col());

    return (P_FACTOR * s + (1 - P_FACTOR) * q);
}

matrix markov(matrix &transite_m) {

    //initial rank matrix, one column 1s
    rank_matrix rank(transite_m.get_col());
    matrix cur_rank;
    matrix pre_rank = cur_rank;

    cur_rank = transite_m * rank;

    while(pre_rank != cur_rank){
        pre_rank = cur_rank;
        cur_rank = transite_m * cur_rank;

    }

    return cur_rank;
}

void report_rank(std::vector<double> &rank) {

    char page_name = 'A';

    std::cout << std::fixed << std::setprecision(2);

    for(double r : rank){

        double percent = r * 100;
        std::cout << "Page " << page_name++ << ": "
        << std::setw(6) << percent << "%" << std::endl;
    }
}
