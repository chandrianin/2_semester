#include <iostream>
#include <logger.h>

int main() {
    setlocale(LC_ALL, "rus");
    utils::logger::setFile("test.txt");
    utils::logger::setLevel(utils::LEVELS::DEBUG);
    utils::logger::write("пример");
    system("pause");
}
