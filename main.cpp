#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "utilities.hpp"

using namespace std;


int main() {

    ifstream readMatrix("../connectivity.txt");

    vector<double> dataV;
    int data;

    while (readMatrix >> data) {
        dataV.push_back(data);
    }

    matrix test(dataV);

//    matrix test2(test);
//
//    cout << test;
//    test.set_value(4, 4, 0.01);
//    cout << test;
//
//    cout << test2;
////
////    test.set_value(4, 4, 1.523);
////    cout << test;
//
//
//    cout << "compare matrix: " << (test == test2) << endl;
    cout << test++;
    cout << test;
    cout << ++test;
    cout << --test;
    cout << test;
    cout << test--;
    cout << test;

    return 0;
}

