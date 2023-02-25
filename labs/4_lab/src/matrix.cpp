#pragma once

#include <matrix.h>
#include <iostream>

template<typename type, unsigned short N, unsigned short M>
matrix<type, N, M>& matrix<type, N, M>::operator= (const matrix<type, N, M>& current){
    if (this != &current){
        matrix temp = current;
        std::swap(m_matrix, current.m_matrix);
        std::swap(m_row, current.m_row);
        std::swap(m_column, current.m_column);
    }
    return *this;
}
template<typename type, unsigned short N, unsigned short M>
std::ostream  matrix<type, N, M>::operator<<(std::ostream& out, const matrix<type, N, M> &current) {
    //TODO ошибка
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            os << m_matrix[i][j];
        }
    }
    return out;
}
