#include <iostream>
//#include <fstream>
//#include "matrix.hpp"
#include "utilities.hpp"
//#include "q_matrix.hpp"
//#include "rank_matrix.hpp"

using namespace std;


int main() {

//    matrix conn_matrix = read_matrix_file("../connectivity.txt"); // if you want see 4 rows matrix, uncomment this
    matrix conn_matrix = read_matrix_file("../c2");  //file than contain 5 rows matrix

    vector<double> rank = rank_page(conn_matrix);

    report_rank(rank);

//    for (double d : rank) {
//        cout << d << endl;
//    }

//    ifstream readMatrix("../connectivity.txt");
//    ifstream readMatrix("../c2");
//
//    vector<double> dataV;
//    cout << "dataV: " << dataV.size() << endl;
//    int data;
//
//    while (readMatrix >> data) {
//        dataV.push_back(data);
//    }
//
//    matrix test(dataV);
//    cout << test;
//    test.calc_probability();
//
//    q_matrix q_test(5);
//
//    matrix m;
//    m = 0.85 * test + (1- 0.85)* q_test;
//
//    cout << " m : " << endl << m;
//
//    rank_matrix r(5);
//
//    cout << " r : " << endl << r;
//
//    matrix temp(m);
//
//    matrix pre_temp;
//
//    temp = m * r;
//    cout << "temp before:" << endl << temp;
//    while(temp != pre_temp){
//        pre_temp = temp;
//        temp = m * temp;
//
//    }
//
//    cout << temp;
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

//    test.calc_probability();
//    cout << test;
//
//    cout << ( 0.8 * test);
//    cout << ( test * 0.8);
//    cout << ( test);
//    cout << ( test *= 0.8);
//    cout << " final test" << endl << test;
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

//    cout << isEqual(0.0, 0.1) << endl; //0
//    cout << isEqual(0.01, 0.01) << endl; //1
//    cout << isEqual(0.001, 0.0001) << endl;//0
//    cout << isEqual(1.2698, 1.2698) << endl;//1
//    cout << isEqual(1.2698, 1.2699) << endl;//0
//    cout << isEqual(1.2698, 1.2697) << endl;//0
//    cout << isEqual(1.269, 1.2699) << endl;//0
//    cout << isEqual(1.2698, 1.26985) << endl;//1
//    cout << isEqual(1.2698, 1.26983) << endl;//1
//    cout << isEqual(1.2698, 1.26988) << endl;//0

//    rank_matrix q_test(4);
//
//    cout << q_test << endl;

    return 0;
}

