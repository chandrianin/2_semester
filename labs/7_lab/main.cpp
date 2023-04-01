#include <iostream>
#include <shape.h>

int main() {
    Circle test("0", 0, 0, 10);
    std::cout << test.getArea() << std::endl;
    Rectangle test2("white", 0, 0, 1, 2);
    std::cout << test2.getArea() << std::endl;
    Triangle test3("1", 0, 0, 10, 20, 30);
    std::cout << test3.getArea() << std::endl;
    return 0;
}
