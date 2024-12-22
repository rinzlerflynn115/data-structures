#include <cassert>
#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
#include "set.h"

void br(std::string msg) {
    std::cout << "//----- " << msg << " -----//" << std::endl;
}

void queueTests() {
    br("testing queue functions");
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
    br("test copy constructor");
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
    br("test assignment");
    Queue<int> q3 = q2;
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
    br("testing stack functions");
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
    // Copy constructor
    br("test copy constructor");
    Stack<int> s2 {s};
    s.dump();
    s2.dump();
    s.push(3);
    s2.push(4);
    s.pop();
    s.pop();
    s.dump();
    s2.dump();
    // Assignment
    br("test assignment");
    Stack<int> s3 = s2;
    s2.dump();
    s3.dump();
    s3.pop();
    s3.push(5);
    s3.push(6);
    s2.pop();
    s2.pop();
    s2.dump();
    s3.dump();
}

void setTests() {
    Set<int> set {};
    set.insert(5);
    set.insert(4);
    set.insert(6);
    set.insert(5);
    set.insert(10);
    set.insert(2);
    set.insert(3);
    set.insert(1);
    set.insert(10);
    set.dump();
}

int main() {
    //queueTests();
    //stackTests();
    setTests();
    return 0;
}