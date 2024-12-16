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
    Stack() : elements(0), currentSize(defaultSize) {
        data = std::make_unique<T[]>(this->currentSize);
    }

    Stack(const Stack<T>& other) : elements(other.elements), currentSize(other.currentSize) {
        this->data = std::make_unique<T[]>(this->currentSize);
        for(int i = 0; i < this->currentSize; ++i) {
            this->data[i] = other.data[i];
        }
    }

    const Stack<T>& operator=(const Stack<T>& other) {
        this->elements = other.elements;
        this->currentSize = other.currentSize;
        this->data = std::make_unique<T[]>(this->currentSize);
        for(int i = 0; i < this->currentSize; ++i) {
            this->data[i] = other.data[i];
        }
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
        throw std::runtime_error("Attempted to pop empty stack.");
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