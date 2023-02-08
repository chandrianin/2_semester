#include <complex.h>
#include <iostream>
complex& complex::operator = (const complex& copy){
    if (this != &copy){
        m_a = copy.m_a;
        m_b = copy.m_b;
    }
    return *this;
}

complex& complex::operator += (const complex &copy) {
    m_a += copy.m_a;
    m_b += copy.m_b;
    return *this;
}

complex& complex::operator *= (const complex &other) {
    double temp_a = m_a * other.m_a - m_b * other.m_b;
    m_b = m_a * other.m_b + m_b * other.m_a;
    m_a = temp_a;
    return *this;
}

complex operator + (const complex& left, const complex& right){
    complex temp(left.m_a + right.m_a, left.m_b + right.m_b);
    return temp;
}

complex operator * (const complex& left, const complex& right){
    double temp_a = left.m_a * right.m_a - left.m_b * right.m_b;
    double temp_b = left.m_a * right.m_b + left.m_b * right.m_a;
    complex temp(temp_a, temp_b);
    return temp;
}

std::ostream& operator << (std::ostream& output, const complex& number){
    output << number.m_a << ' ' << '+' << ' ' << number.m_b << 'i';
    return output;
}
std::istream& operator >> (std::istream& input, complex& number){
    std::string temp;
    input >> temp;
    number.m_a = 0;
    number.m_b = 0;
    std::string newA = "";
    std::string newB = "";
    short index = -1;
    for (short i = 0; static_cast<size_t>(i) < temp.length(); i++){
        if (temp[i] == '+'){
            index = i;
        }
        else if (temp[i] >= 48 && temp[i] <= 57 && index > -1){
            newB += temp[i];
        }
        else if(temp[i] >= 48 && temp[i] <= 57 && index == -1){
            newA += temp[i];
        }
    }
    for (auto i = static_cast<short>(newA.length() - 1); i >= 0; i--){
        number.m_a += (newA[newA.length() - 1 - i] - '0') * pow(10, i);
    }
    for (auto i = static_cast<short>(newB.length() -1 ); i >= 0; i--){
        number.m_b += (newB[newB.length() - 1 - i] - '0') * pow(10, i);
    }
    return input;
}