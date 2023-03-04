//
// Created by TbMA3 on 04.03.2023.
//

#pragma once
namespace vb {
    template<typename type>
    class vector {

    };

    template<>
    class vector<bool> {
    private:
        unsigned short length{0};
        char* boolMas = new char[0];
    public:
        vector<bool>(){}
        bool operator[](unsigned int index) const{
            return static_cast<bool>(((boolMas[index / 8]) >> index) & 0b00000001);
        }
        void edit(int index, bool value){
            char degree = 1;
            for (int i = 0; i < index; i++){
                degree *= 2;
            }
            value ? boolMas[index / 8] |= degree : boolMas[index / 8] &= ~degree;
        }
        void push_back(bool value){
            //TODO доделать
//            length += 1;
//            char* temp;
//            length % 8 == 0 ? temp = new char[1 + (length / 8)] : temp = boolMas;

        }
    };


}