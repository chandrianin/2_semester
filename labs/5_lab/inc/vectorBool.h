//
// Created by TbMA3 on 04.03.2023.
//
#include <iostream>
#pragma once
namespace vb {
    template<typename type>
    class vector {

    };

    template<>
    class vector<bool> {
    private:
        size_t length{0};
        char* boolMas = new char[0];
    public:
        vector<bool>() = default;
        ~vector() {delete[] boolMas;}
        vector(const vector<bool>& copy){
            if (this != &copy){
                vector<bool> temp;
                std::swap(temp.boolMas, boolMas);
                length = temp.length;
            }
        }
        vector<bool>& operator= (const vector<bool>& copy){
            if (this != &copy){
                vector<bool> temp;
                std::swap(temp.boolMas, boolMas);
                length = temp.length;
            }
            return *this;
        }
        bool operator[](unsigned int index) const{
            return static_cast<bool>(((boolMas[index / 8]) >> index) & 0b00000001);
        }
        void edit(size_t index, bool value){
            char degree = 1;
            for (int i = 0; i < index; i++){
                degree *= 2;
            }
            value ? boolMas[index / 8] |= degree : boolMas[index / 8] &= ~degree;
        }
        void push_back(bool value){
            if (length % 8 == 0){
                char* temp = new char[(length / 8) + 1];
                for (int i = 0; i < length; i++){
                    temp[i] = boolMas[i];
                }
                delete[] boolMas;
                boolMas = temp;
                edit(length, value);
            }
            else{
                edit(length, value);
            }
            length++;
        }
        [[nodiscard]] size_t size() const{
            return length;
        }
        void insert(size_t index, bool  value){
            this->push_back(operator[](length - 1));
            for (size_t i = length; i != index; i--)
                edit(i, operator[](i - 1));

            edit(index, value);
        }
        void erase(size_t firstIndex, size_t lastIndex){
            for (size_t i = lastIndex; i < length; i++){
                edit(i - (lastIndex - firstIndex), operator[](i));
//                boolMas[i - (lastIndex - firstIndex)] = boolMas[i];
            }
            length -= lastIndex - firstIndex;
        }
        void erase(size_t index){
            for (size_t i = index; i < length - 1; i++){
                edit(i, operator[](i + 1));
//                boolMas[i] = boolMas[i + 1];
//                for(int j = 0; j < this->length; j++){
//                    std::cout << boolMas[j] << " ";
//                }
            }
            length--;
        }
    };


}