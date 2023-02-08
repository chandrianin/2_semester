#include <iostream>

class String{
private:
    unsigned int m_size;
    char* m_str;
    friend std::ostream& operator << (std::ostream& os, const String& currentString);
    friend std::istream& operator >> (std::istream& is, String& currentString);
    friend String operator + (const String& left ,const String& right);
public:
    // Базовый конструктор 1, принимает на ввод динамический массив char'ов
    String(char* str) : m_size(strlen(str)), m_str(new char[m_size + 1]){
        std::copy(str, str + m_size + 1, m_str);
    }

    // Базовый конструктор 2, принимает на вход один char и их количество
    // в данном случае explicit запрещает неявно подложить конструктору вместо char'a число
    explicit String(char symbol, unsigned int count) : m_size(count), m_str(new char[m_size + 1]){
        std::fill(m_str, m_str + m_size, symbol);
        m_str[m_size] = '\0';
    }

    // Базовый конструктор 3, принимает на вход char
    explicit String(char str) : m_size(1), m_str(new char[2]){
        m_str[0] = str;
        m_str[m_size] = '\0';
    }

    // Конструктор копирования
    String(const String& copy) : String(copy.m_str){}

    // Оператор присваивания копированием
    String& operator = (const String& currentString){
        if (this != &currentString){
            String temp = currentString;
            std::swap(m_size, temp.m_size);
            std::swap(m_str, temp.m_str);
        }
        return *this;
    }


    String& operator += (const String& right){
        char* temp = new char[m_size + right.m_size + 1];
        std::copy(m_str, m_str + m_size, temp);
        std::copy(right.m_str, right.m_str + right.m_size + 1, temp + m_size);

        delete[] m_str;
        m_str = temp;
        m_size += right.m_size;
        return *this;
    }

    char& operator[](unsigned int index) const{
        return m_str[index];
    }

    bool operator == (const String& right) const{
        if (strlen(m_str) == (strlen(right.m_str))){
            for (int i = 0; i < strlen(m_str); i++){
                if (m_str[i] != right.m_str[i]){
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }

    bool operator > (const String& right) const{
        if (m_size == right.m_size){
            for (int i = 0; i < m_size; i++){
                if ((int)(m_str[i] > (int)(right.m_str[i]))){
                    return true;
                }
                else if((int)(m_str[i] < (int)(right.m_str[i]))){
                    return false;
                }
            }
            return false;
        }
        else if(m_size > right.m_size){ return true; }
        else { return false; }
    }

    bool operator < (const String& right) const{
        if (m_size == right.m_size){
            for (int i = 0; i < m_size; i++){
                if ((int)(m_str[i] > (int)(right.m_str[i]))){
                    return false;
                }
                else if((int)(m_str[i] < (int)(right.m_str[i]))){
                    return true;
                }
            }
            return false;
        }
        else if(m_size > right.m_size){ return false; }
        else { return true; }
    }

    [[nodiscard]] int find(char element) const{
        for (int i = 0; i < m_size; i++){
            if (element == m_str[i]){
                return i;
            }
        }
        return -1;
    }

    [[nodiscard]] unsigned int length() const{ return m_size; }

    [[nodiscard]] char* c_str() const{ return m_str; }

    char& at(int index) {
        if (0 <= index && index < static_cast<int>(m_size)){
            return m_str[index];
        }
        else{
            std::cout << "String out of range" << std::endl;
            std::abort();
        }
    }

    ~String(){
        delete[] m_str;
    }

};

String operator + (const String& left ,const String& right){
    String temp = left;
    temp += right;
    temp.m_str[temp.m_size] = '\0';
    return temp;
}

std::ostream& operator << (std::ostream& os, const String& currentString){
    for (int i = 0; i < currentString.m_size; i++){
        os << currentString.m_str[i];
    }
    currentString.m_str[currentString.m_size] = '\0';
    return os;
}

std::istream& operator >> (std::istream& is, String& currentString){
    char* temp = new char[10000];
    is >> temp;
    unsigned int index = -1;
    for (unsigned int i = 0; i < 10000; i++){
        if (temp[i] == '\0'){
            index = i;
            break;
        }
    }
    currentString.m_size = index + 1;
    delete[] currentString.m_str;
    currentString.m_str = new char[currentString.m_size + 1];
    std::copy(temp, temp + index + 1, currentString.m_str);
    delete[] temp;
    return is;
}


int main() {;

    String test = "Apple";
    std::cout << test << std::endl;
    test[0] = 'p';
    std::cout << test << std::endl;
    system("pause");
    return 0;
    //    std::cin >> test;
    String qwer = "qwerty";
    if (test > qwer){
        std::cout << 1 << std::endl;
    }
    if (test < qwer){
        std::cout << 2 << std::endl;
    }
    if (test == static_cast<String>("Apple")){
        std::cout << 3 << std::endl;
    }
    test += qwer;
    std::cout << test << std::endl;
    test[0] = 'w';
    test.at(100) = 'v';
    std::cout << test + String('v') <<std::endl;
    std::cout << test << std::endl;
    system("pause");
    return 0;
}
