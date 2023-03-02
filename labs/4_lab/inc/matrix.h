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
    matrix() { std::cout << "constructor" << std::endl; };

    matrix(const matrix &current) {
        std::cout << "--- copy constructor" << std::endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                m_matrix[i][j] = current.m_matrix[i][j];
            }
        }
    }

    matrix& operator= (const matrix<type, N, M>& current){
        std::cout << "=== assignment constructor" << std::endl;
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

        if (N == M && M == 2){
            return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] - m_matrix[1][0] * m_matrix[0][1]);
        }
        else if (N == M && M == 3){
            return static_cast<type>(m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] + m_matrix[1][0] * m_matrix[0][2] * m_matrix[2][1] + m_matrix[0][1] * m_matrix[2][0] * m_matrix[1][2] - m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0] - m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1] - m_matrix[2][2] * m_matrix[0][1] * m_matrix[1][0]);
        }
        else if (N == M && M == 1){
            return static_cast<type>(m_matrix[0][0]);
        }
    }

    matrix& operator+= (const matrix<type, N, M>& rightMatrix){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    m_matrix[i][j] += rightMatrix.m_matrix[i][j];
                }
            }
        return *this;
    }
    matrix operator+ (const matrix<type, N, M>& rightMatrix){
        matrix<type, N, M> tempMatrix = *this;
        tempMatrix += rightMatrix;
        return tempMatrix;
    }

    matrix& operator*= (const matrix<type, M, N>& rightMatrix){
        matrix<type, N, M> tempMatrix = *this;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                m_matrix[i][j] = 0;
                for (int u = 0; u < M; u++){
                    m_matrix[i][j] += tempMatrix[i][u] * rightMatrix[u][j];
                }
            }
        }
        return *this;
    }
    matrix operator* (const matrix<type, M, N>& rightMatrix){
        matrix<type, N, M> tempMatrix = *this;
        tempMatrix *= rightMatrix;
        return tempMatrix;
    }

    matrix& operator++ (){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                m_matrix[i][j]++;
            }
        }
    }

    type& at(unsigned int firstIndex, unsigned int secondIndex){
        if (firstIndex < N && secondIndex < M){
            return m_matrix[firstIndex][secondIndex];
        }
        std::abort();

    }
    ~matrix() {std::cout << "destructor" << std::endl;};
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




