#include <iostream>
#include <matrix.h>

int main() {
    matrix<int, 2, 2> firstMatrix{};
    std::cin >> firstMatrix;

    matrix<int, 2, 4> secondMatrix{};
    std::cin >> secondMatrix;

    std::cout << firstMatrix << std::endl;
    std::cout << secondMatrix << std::endl;
    std::cout << (firstMatrix * secondMatrix) << std::endl;

}
