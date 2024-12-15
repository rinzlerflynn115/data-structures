#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Stack {
private:
    std::unique_ptr<T[]> data;
    int defaultSize {4};
    int elements;
    int currentSize;

    void grow() {
        std::unique_ptr<T[]> newArray = std::make_unique<T[]>(currentSize * 2);
        for(int i = 0; i < currentSize; ++i) {
            newArray[i] = data[i];
        }
        data = std::move(newArray);
    }
public:
    Stack() : elements(0), currentSize(0) {
        data = std::make_unique<T[]>(defaultSize);
    }

    void push(T elem) {
        data[elements++] = elem;
        if(elements == currentSize) {
            grow();
        }
    }

    T pop() {
        if(elements > 0) {
            return data[elements--];
        }
        return nullptr;
    }

    int size() { return elements; }

    bool empty() { return elements == 0; }

    void dump() {
        for(int i = 0; i < elements; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};