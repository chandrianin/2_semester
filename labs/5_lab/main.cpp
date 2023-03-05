#include <iostream>
#include <vectorBool.h>

int main() {
    vb::vector<bool> boolVector;
    boolVector.push_back(true);
    boolVector.push_back(false);
    boolVector.push_back(true);
    boolVector.push_back(false);

    // работает
    //boolVector.insert(3, true);

    // работает
    //boolVector.edit(1, true);

    // работает
    //boolVector.erase(3);

    // работает
    //boolVector.erase(1, 4);
    for(int i = 0; i < boolVector.size(); i++){
        std::cout << boolVector[i] << " ";
    }
    return 0;
}
