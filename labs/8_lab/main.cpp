#include <iostream>
#include "stack.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Stack<int> first(1);
//    first.push(1);
//    first.push(2);
    try {
        first.pop();
    }
    catch (const std::out_of_range& currentError) {
        std::cerr << "Ошибка: ";
        std::cerr << currentError.what() << std::endl;
    }
    catch ( const std::bad_alloc& currentError){
        std::cerr << "Превышено количество допустимых элементов:" << std::endl;
    }
    system("pause");
}
