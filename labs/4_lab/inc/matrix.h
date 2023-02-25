#pragma once

#include <iostream>
#include <vector>

template<typename type, unsigned short N, unsigned short M>

class matrix {
private:
    std::vector<std::vector<type>> m_matrix;
    type m_row = N;
    type m_column = M;
    friend std::ostream& operator << (std::ostream& out, const matrix<type, N, M>& current);
public:
    explicit matrix(const std::vector<std::vector<type>>& mas) : m_matrix(mas){};
//    matrix();
    matrix(const matrix& copy) : matrix(copy.m_matrix){};
    matrix& operator= (const matrix& current);
};



