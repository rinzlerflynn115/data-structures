#pragma once
#include <memory>
#include <iostream>

template <typename T>
class Queue {
private:
    std::unique_ptr<T[]> data;
    int defaultSize {4};
    int currentSize;
    int entries;
    int nextInsertIndex;
    int headIndex;

    void grow() {
        std::cout << "Resizing internal array from " << this->currentSize << " to " << this->currentSize * 2 << std::endl;
        std::unique_ptr<T[]> newArray = std::make_unique<T[]>(this->currentSize * 2);
        int ptr = this->headIndex;
        int count = 0;
        while(count < this->entries) {
            newArray[count++] = this->data[ptr++];
            if(ptr >= this->currentSize) {
                ptr = 0;
            }
        }
        this->headIndex = 0;
        this->currentSize *= 2;
        this->nextInsertIndex = this->entries;
        this->data = std::move(newArray);
    }
public:
    Queue() : currentSize(defaultSize), entries(0), nextInsertIndex(0), headIndex(0), data(std::make_unique<T[]>(currentSize)) {}

    void push(T item) {
        this->data[this->nextInsertIndex++] = item;
        this->entries += 1;
        if(this->entries == this->currentSize) {
            this->grow();
        }
        if(this->nextInsertIndex  >= this->currentSize) {
            this->nextInsertIndex = 0;
        }
        std::cout << "HEAD: " << this->headIndex << " NEXT: " << this->nextInsertIndex << std::endl;
    }

    T pop() {
        this->headIndex++;
        this->entries--;
        if(this->headIndex >= this->currentSize) {
            this->headIndex = 0;
            std::cout << "HEAD: " << this->headIndex << " NEXT: " << this->nextInsertIndex << std::endl;
            return this->data[this->currentSize - 1];
        }
        std::cout << "HEAD: " << this->headIndex<< " NEXT: " << this->nextInsertIndex << std::endl;
        return this->data[this->headIndex -1];
    }

    int size() { return this->entries; }

    bool empty() { return this->entries == 0;}

    void dump() {
        int ptr = this->headIndex;
        int count = 0;
        while(count < this->entries) {
            std::cout << this->data[ptr++] << " ";
            count += 1;
            if(ptr >= this->currentSize) {
                ptr = 0;
            }
        }
        std::cout << std::endl;
    }
};