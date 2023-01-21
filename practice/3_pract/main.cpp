#include <iostream>
#include <kinematicSolver.h>

int main() {
    float L1, L2, x, y;
    std::cout << "Enter L1\n>>> ";
    std::cin >> L1;
    std::cout << "Enter L2\n>>> ";
    std::cin >> L2;
    std::cout << "Enter x\n>>> ";
    std::cin >> x;
    std::cout << "Enter y\n>>> ";
    std::cin >> y;
    kinematicSolver first(L1, L2, x, y);
    first.solve();
    system("pause");
    return 0;
}
