#include <iostream>
#include <complex.h>

int main() {
    complex first(10, 15);
    std::cout << first << std::endl;
    first = first + complex("10+5i");
    std::cout << first << std::endl;
    first += 1;
    std::cout << first << std::endl;
    first *= 5;
    std::cout << first << std::endl;
    complex second = ++first;
//    std::cout << second << std::endl;
//    second = first++;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    complex third = first * second;
    std::cout << third << std::endl;
    first *= second;
    std::cout << first << std::endl;

    return 0;
}
