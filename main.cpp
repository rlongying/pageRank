#include <iostream>
#include <fstream>
#include "matrix.hpp"

using namespace std;


int main() {

    ifstream readMatrix("../connectivity.txt");

    vector<double> dataV;
    int data;

    while(readMatrix >> data){
        dataV.push_back(data);
    }

    matrix test(dataV);
    test.print();

//    test.set_value(4, 4, 1.0);
//    test.print();

//    cout << test.get_value(4, 6);

    test.clear();
    test.print();

    return 0;
}

