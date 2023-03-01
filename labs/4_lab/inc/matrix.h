#pragma once

#include <iostream>
#include <istream>
#include <vector>

template<typename type, unsigned short N, unsigned short M>



class matrix {
private:
    type m_matrix[N][M];
    template<typename type, unsigned short N, unsigned short M>
    friend std::ostream& operator<<(std::ostream& out, const matrix<type, N, M> &current);
    template<typename type, unsigned short N, unsigned short M>
    friend std::istream& operator>> (std::istream& in, matrix<type, N, M>& current);
public:
    matrix() = default;
    matrix(const matrix &current) {
        std::cout << 2 << std::endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                m_matrix[i][j] = current.m_matrix[i][j];
            }
        }
    }
    matrix& operator= (const matrix<type, N, M>& current){
        std::cout << 3 << std::endl;
        if (this != &current){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    m_matrix[i][j] = current.m_matrix[i][j];
                }
            }
        }
        return *this;
    }
    type determinant(){
        if (N == M == 2){
            return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1]);
        }
        else if (N == M == 3){
            return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] + m_matrix[1][0] * m_matrix[0][2] * m_matrix[2][1] + m_matrix[0][1] * m_matrix[2][0] * m_matrix[1][2] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1] - m_matrix[2][2] * m_matrix[0][1] * m_matrix[1][0]);
        }
        else if (N == M == 1){
            return static_cast<type>(m_matrix[0][0]);
        }
    }
    ~matrix()= default;
};

template<typename type, unsigned short N, unsigned short M>
std::istream& operator>>(std::istream& in, matrix<type, N, M> &current) {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            in >> current.m_matrix[i][j];
        }
    }
    return in;
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




