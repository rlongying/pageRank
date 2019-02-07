#include <iostream>
//#include <fstream>
//#include "matrix.hpp"
#include "utilities.hpp"
//#include "q_matrix.hpp"
//#include "rank_matrix.hpp"

using namespace std;


int main() {

    matrix conn_matrix = read_matrix_file("../connectivity.txt"); // if you want see 4 rows matrix, uncomment this
//    matrix conn_matrix = read_matrix_file("../c2");  //file than contain 5 rows matrix

    vector<double> rank = rank_page(conn_matrix);

    report_rank(rank);

    return 0;
}

