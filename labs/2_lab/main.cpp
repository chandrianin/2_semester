#include <iostream>

class String{
private:
    unsigned int m_size;
    char* m_str;
public:
    // explicit запрещает неявное преобразование
    explicit String(char* str) : m_size(strlen(str)), m_str(new char[m_size + 1]){
        std::cout << "Constructor 1 work" << std::endl;
        std::copy(str, str + m_size, m_str);
        m_str[m_size] = '\0';
    }

    // в данном случае explicit запрещает неявно подложить конструктору вместо char'a число
    explicit String(char symbol, unsigned int count) : m_size(count), m_str(new char[m_size + 1]){
        std::cout << "Constructor 2 work" << std::endl;
        std::fill(m_str, m_str + m_size, symbol);
        m_str[m_size] = '\0';
    }

    // Конструктор копирования
    String(const String& copy) : String(copy.m_str){
        std::cout << "Copy constructor work!" << std::endl;
    }

    // Конструктор присваивания копированием
    String& operator=(String currentString){
        if (this != &currentString){
            m_size = currentString.m_size;
            m_str = currentString.m_str;
        }
        return *this;
    }
    String operator + (const String& right){
        char* temp = new char[m_size + right.m_size];
        std::copy(temp, temp + m_size, m_str);
        std::copy(temp + m_size, temp + m_size + right.m_size, right.m_str);
        return String::String(temp);
    }

//    char* getStr() {
//        return m_str;
//    }

    ~String(){
        delete[] m_str;
    }
};

int main() {

//    String first("hello");
//
//    String second = first;
//
//    std::cout << second.getStr()<< std::endl;

    return 0;
}
