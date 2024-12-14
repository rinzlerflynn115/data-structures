#include <iostream>
#include "queue.h"

int main() {
    Queue<int> q{};
    q.push(1);
    q.push(2);
    q.push(3);
    int x = q.pop();
    std::cout << "Called pop(), got " << x << std::endl;
    q.push(4);
    q.push(5);
    q.dump();
    return 0;
}