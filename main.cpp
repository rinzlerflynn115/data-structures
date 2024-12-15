#include <iostream>
#include "queue.h"
#include "stack.h"

void queueTests() {
    //test basic queue stuff
    Queue<int> q{};
    q.push(1);
    q.push(2);
    q.push(3);
    int x = q.pop();
    std::cout << "Called pop(), got " << x << std::endl;
    q.push(4);
    //queue is set to default internal array size 4, this push forces it to resize
    q.push(5);
    q.dump();
    //test copy ctor
    
    Queue<int> q2{q};
    std::cout << "q: ";
    q.dump();
    std::cout << "q2: ";
    q2.dump();
    //make sure there's no weird shallow copy errors
    q.push(6);
    q.push(7);
    q.pop();
    std::cout << "q: ";
    q.dump();
    std::cout << "q2: ";
    q2.dump();

    Queue<int> q3 = q2;
    std::cout << "----------" << std::endl;
    std::cout << "q2: ";
    q2.dump();
    std::cout << "q3: ";
    q3.dump();
    q3.push(6);
    q3.push(7);
    q3.pop();
    std::cout << "q2: ";
    q2.dump();
    std::cout << "q3: ";
    q3.dump();
}

void stackTests() {
    Stack<int> s {};
}

int main() {
    
    return 0;
}