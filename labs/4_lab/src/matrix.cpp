#pragma once

#include <matrix.h>
#include <iostream>

template<typename type, unsigned short N, unsigned short M>
matrix<type, N, M>::matrix() {
    //TODO сделать ввод матрицы с консоли
    for (int i = 0; i < N ; i++){
        for (int j = 0; j < M; j++){
            std::cout >> m_matrix[i][j];
        }
    }
}
