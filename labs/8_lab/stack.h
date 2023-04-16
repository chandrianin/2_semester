#include <iostream>
#pragma once

template<typename type>
class Stack {
private:
    char* Data = nullptr;
    unsigned int CurrentCount = 0;
    unsigned int ElementsCount;
public:
    explicit Stack(unsigned int size) : ElementsCount(size), Data(new char[size * sizeof(type)]){}

    Stack(const Stack<type>& copy) {
        Data = new char[copy.ElementsCount * sizeof(type)];
        CurrentCount = copy.CurrentCount;
        ElementsCount = copy.ElementsCount;
    }
    Stack& operator= (Stack<type>& copy) {
        if (this != &copy){
            Stack temp = copy;
            std::swap(Data, copy.Data);
            std::swap(CurrentCount, copy.CurrentCount);
            std::swap(ElementsCount, copy.ElementsCount);
        }
        return *this;
    }

    [[nodiscard]] unsigned int size() const {
        return CurrentCount;
    }

    [[nodiscard]] bool empty() const {
        if (CurrentCount == 0){
            return true;
        }
        return false;
    }

    void push(const type& newElement) {
        if (CurrentCount < ElementsCount){
            Data[CurrentCount] = newElement;
            CurrentCount++;
        }
        else {
            throw std::bad_alloc();
        }
    }

    type pop(){
        if (CurrentCount != 0) {
            CurrentCount--;
            return Data[CurrentCount];
        }
        throw std::out_of_range("Empty stack");
    }
    type top(){
        if (CurrentCount != 0) {
            return Data[CurrentCount];
        }
        throw std::out_of_range("Empty stack");
    }
    ~Stack() {
        delete[] Data;
    }
};