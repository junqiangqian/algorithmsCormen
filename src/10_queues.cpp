#include <iostream>
#include "Queue.cpp"

int main() {
    LinkedListQueue<int> q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(4);
    LinkedListQueue<int> q2(q);
    q.dequeue();
    std::cout << q;
    std::cout << q2;
    q2 = q;
    q.dequeue();
    std::cout << q;
    std::cout << q2;
    return 0;
}
