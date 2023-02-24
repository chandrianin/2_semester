#pragma once

template<typename type, unsigned short N, unsigned short M>

class matrix {
private:
    type m_matrix[N][M];
public:
    explicit matrix(type* mas) : m_matrix(mas){};
    matrix();

};


