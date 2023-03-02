#include <iostream>
#include <matrix.h>

int main() {
    matrix<int, 2, 2> firstMatrix{};
    std::cin >> firstMatrix;
    std::cout << "Determinant = " << firstMatrix.determinant() << std::endl;
    std::cout << firstMatrix;

    matrix<int, 2, 2> secondMatrix{};
    secondMatrix = firstMatrix;
    std::cout << firstMatrix.at(0, 0) << std::endl;
    std::cout << firstMatrix + secondMatrix << std::endl;

}
