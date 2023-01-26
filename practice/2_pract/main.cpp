#include <iostream>
int main() {
    const int N = 20;
    char* firstMas = new char[N] {1, 2, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5};
    char* secondMas = new char[N];


    const int n = 10;
    //int p = n;
    auto* newFirstMas = reinterpret_cast<int*>(&n);
    auto* newSecondMas = (size_t*)secondMas;

    for (int i = 0; i < (int)(N / sizeof(size_t)); i++){
        newSecondMas[i] = newFirstMas[i];
    }

    firstMas = (char*)newFirstMas;
    secondMas = (char*)newSecondMas;

    for (int i = (int)(N / sizeof(size_t)); i < N; i++){
        secondMas[i] = firstMas[i];
    }
    for (int i = 0; i < N; i++){
        std::cout << (int)(secondMas[i]) << " ";
    }
}
