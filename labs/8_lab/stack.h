#include <iostream>
#pragma once

template<typename type>
class Stack {
private:
    char* Data;
    unsigned int CurrentCount = 0;
    unsigned int ElementsCount;
public:
    explicit Stack(unsigned int size) : ElementsCount(size), Data(new char[ElementsCount * sizeof(type)]){}

    Stack(const Stack<type>& copy) {
        Data = new char[copy.ElementsCount * sizeof(type)];
        CurrentCount = copy.CurrentCount;
        ElementsCount = copy.ElementsCount;
    }
    Stack operator=(const Stack& copy) {
        delete[] Data;
        Data = new char[copy.ElementsCount * sizeof(type)];
        CurrentCount = copy.CurrentCount;
        ElementsCount = copy.ElementsCount;
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
        throw ;
    }
    type top(){
        if (CurrentCount != 0) {
            return Data[CurrentCount];
        }
    }
    ~Stack() {
        delete[] Data;
    }
};