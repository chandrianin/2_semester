#pragma once
#include <iostream>

class complex {
private:
    double m_a;
    double m_b;

    friend complex operator + (const complex& left, const complex& right);
//    friend complex operator + (const complex& left, const double& right);
//    friend complex operator + (const double& left, const complex& right);

    friend complex operator * (const complex& left, const complex& right);
//    friend complex operator * (const complex& left, const double& right);
//    friend complex operator * (const double& left, const complex& right);

    friend std::ostream& operator << (std::ostream& output, const complex& number);
    friend std::istream& operator >> (std::istream& in, complex& number);
public:
    complex(double a, double b) : m_a(a), m_b(b){};
    complex(double a) : m_a(a), m_b(0){};
    complex(const std::string& currentString){
        this->m_a = 0;
        this->m_b = 0;
        std::string newA = "";
        std::string newB = "";
        short index = -1;
        for (short i = 0; static_cast<size_t>(i) < currentString.length(); i++){
            if (currentString[i] == '+'){
                index = i;
            }
            else if (currentString[i] >= 48 && currentString[i] <= 57 && index > -1){
                newB += currentString[i];
            }
            else if(currentString[i] >= 48 && currentString[i] <= 57 && index == -1){
                newA += currentString[i];
            }
        }
        for (auto i = static_cast<short>(newA.length() - 1); i >= 0; i--){
            this->m_a += (newA[newA.length() - 1 - i] - '0') * pow(10, i);
        }
        for (auto i = static_cast<short>(newB.length() -1 ); i >= 0; i--){
            this->m_b += (newB[newB.length() - 1 - i] - '0') * pow(10, i);
        }
    };
    complex(const complex& copy) : complex(copy.m_a, copy.m_b){};
    ~complex() = default;
    complex& operator = (const complex& copy);

    complex& operator += (const complex& copy);
    complex& operator *= (const complex& other);
    complex& operator++ (){
        ++m_a;
        return *this;
    };
    complex operator++ (int){
        complex temp = *this;
        ++m_a;
        return temp;
    }
//    complex& operator *= (const double& copy);
};
