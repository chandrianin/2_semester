#include <iostream>
#include <vector>
int main() {
    const int N = 1000;
    int firstMas[N] = {1, 2 , 3, 4, 5};
    int secondMas[N] = {};
    if (sizeof(firstMas[0]) <= 8){
        for (int i = 0; i < N; i++){
            secondMas[i] = firstMas[i];
        }
    }
    else{
        secondMas[0] = static_cast<int*>(firstMas);
    }
}
