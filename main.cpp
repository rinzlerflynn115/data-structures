#include <cassert>
#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"

void queueTests() {
    std::cout << "//-- testing queue functions --//" << std::endl;
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
    std::cout << "//-- testing stack functions. --//" << std::endl;
    Stack<int> s {};
    s.push(1);
    s.push(2);
    s.push(3);
    s.dump();
    s.pop();
    s.dump();
    s.pop();
    s.pop();
    try {
        s.pop();
    } catch(std::runtime_error &e) {
        assert(std::string(e.what()) == "Attempted to pop empty stack.");
    }
    if(s.empty()) {
        std::cout << "Stack is empty." << std::endl;
    }
    s.push(1);
    s.push(2);
    Stack<int> s2 {s};
    s.dump();
    s2.dump();
    s.push(3);
    s2.push(4);
    s.pop();
    s.pop();
    s.dump();
    s2.dump();
}

int main() {
    stackTests();
    return 0;
}