#include <iostream>
#include <matrix.h>

int main() {
    matrix<int, 2, 2> firstMatrix;
    std::cin >> firstMatrix;
    std::cout << firstMatrix.determinant() << std::endl;
    std::cout << firstMatrix;

    matrix<int, 2, 2> secondMatrix = firstMatrix;
    std::cout << secondMatrix;
}
