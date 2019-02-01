#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "utilities.hpp"

using namespace std;


int main() {

    ifstream readMatrix("../connectivity.txt");

    vector<double> dataV;
    cout << "dataV: " << dataV.size() << endl;
    int data;

    while (readMatrix >> data) {
        dataV.push_back(data);
    }

    matrix test(dataV);

    matrix test2(test);

//    cout << test;
    test.set_value(4, 4, 0.01);
    cout << "test 1" << endl << test;

    cout <<"test 2" << endl << test2;

    matrix test3;
    test3 = test;
    cout << "test 3" << endl << test3;

    cout << (test + test2);
    cout << (test - test2);
    cout << (test + test3);

    cout << "test 1" << endl << test;

    cout <<"test 2" << endl << test2;

    cout << "test 3" << endl << test3;

    return 0;
}

