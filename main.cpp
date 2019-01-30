#include <iostream>
#include "matrix.hpp"

using namespace std;


int main() {
    cout << "Hello, World!" << endl;

    matrix test({2, 1, 3, 4});
    test.print();

//    test.set_value(4, 4, 1.0);
//    test.print();

//    cout << test.get_value(4, 6);

    test.clear();
    test.print();

    return 0;
}

