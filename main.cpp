#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "utilities.hpp"
#include "q_matrix.hpp"
#include "rank_matrix.hpp"

using namespace std;


int main() {

    ifstream readMatrix("../connectivity.txt");

    vector<double> dataV;
    cout << "dataV: " << dataV.size() << endl;
    int data;

    while (readMatrix >> data) {
        dataV.push_back(data);
    }

//    std::vector<std::vector<double>> v1({{1, 2, 3}, {4, 5, 6}});
//    std::vector<std::vector<double>> v2({{7, 8}, {9, 10},{11, 12}});
//
//    matrix test1(2,3);
//
//    for(int i= 0; i < v1.size(); i++){
//        for (int j = 0; j < v1[0].size(); j++){
//            test1.set_value(i+1, j+1, v1[i][j]);
//        }
//    }
//    cout << test1;
//
//    matrix test2(3, 2);
//    for(int i= 0; i < v2.size(); i++){
//        for (int j = 0; j < v2[0].size(); j++){
//            test2.set_value(i+1, j+1, v2[i][j]);
//        }
//    }
//    cout << test2;
//
//    matrix test3;
//    test3 = test1 * test2;
//    cout << (test3);

//    for(int v1)
//    matrix test(dataV);
//
//    matrix test2(test);
////
//////    cout << test;
//    test.set_value(4, 4, 0.01);
//    cout << "test 1" << endl << test;
//
//    cout <<"test 2" << endl << test2;
//
//    matrix test3;
//    test3 = test;
//    cout << "test 3" << endl << test3;
//
//    cout << (test + test2);
//    cout << (test - test2);
//    cout << (test + test3);
//
//    cout << "test 1" << endl << test;
//
//    cout <<"test 2" << endl << test2;
//
//    cout << "test 3" << endl << test3;
//

//    cout << isEqual(0.0, 0.1) << endl;
//    cout << isEqual(0.01, 0.01) << endl;
//    cout << isEqual(0.001, 0.0001) << endl;
//    cout << isEqual(0.0000001, 0.00001) << endl;
//    cout << isEqual(0.000001, 0.0000021) << endl;

    rank_matrix q_test(4);

    cout << q_test << endl;

    return 0;
}

