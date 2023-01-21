#include <iostream>

#include <animation.h>

int main() {
    setlocale(LC_ALL, "Rus");
    animatedText test(10, "Hello!");
    test.textOutput();
    return 0;
}
