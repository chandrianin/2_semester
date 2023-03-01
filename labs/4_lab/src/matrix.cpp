#pragma once

#include <matrix.h>
//#include <iostream>

/*template<typename type, unsigned short N, unsigned short M>
matrix<type, N, M>::matrix() {
    m_matrix = new type *[N];
    for (int i = 0; i < N; i++){
        m_matrix[i] = new type[M];
    }
}*/

/*template<typename type, unsigned short N, unsigned short M>
matrix<type, N, M>::matrix(const matrix &current) {
    m_matrix = new type**[current.N];
    for (int i = 0; i < N; i++){
        m_matrix[i] = new type[M];
        std::copy(current.m_matrix[i][0], current.m_matrix[i][M], m_matrix[i][0]);
    }
    return *this;
}

template<typename type, unsigned short N, unsigned short M>
matrix<type, N, M>& matrix<type, N, M>::operator= (const matrix<type, N, M>& current){
    if (this != &current){
        m_matrix = new type**[current.N];
        for (int i = 0; i < N; i++){
            m_matrix[i] = new type[M];
            std::copy(current.m_matrix[i][0], current.m_matrix[i][M], m_matrix[i][0]);
        }
    }
    return *this;
}

template<typename type, unsigned short N, unsigned short M>
std::ostream& operator<<(std::ostream& out, const matrix<type, N, M> &current) {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            out << current.m_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return out;
}

template<typename type, unsigned short N, unsigned short M>
std::istream& operator>>(std::istream& in, const matrix<type, N, M> &current) {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            in >> current.m_matrix[i][j] >> " ";
        }
        std::cout << std::endl;
    }
    return in;
}

template<typename type, unsigned short N, unsigned short M>
type matrix<type, N, M>::determinant(){
    if (N == M == 2){
        return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1]);
    }
    else if (N == M == 3){
        return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] + m_matrix[1][0] * m_matrix[0][2] * m_matrix[2][1] + m_matrix[0][1] * m_matrix[2][0] * m_matrix[1][2] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1] - m_matrix[2][2] * m_matrix[0][1] * m_matrix[1][0]);
    }
    else if (N == M == 1){
        return static_cast<type>(m_matrix[0][0]);
    }
}*/

/*template<typename type, unsigned short N, unsigned short M>
matrix<type, N, M>::~matrix() {
    for (int i = 0; i < N; i++){
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}*/