#include "SinglyUnsortedLinkedList.cpp"
#include <iostream>

int main() {
    LinkedList<int> s;
    s.insertHead(10);
    s.insertHead(7);
    s.insertHead(9);
    s.insertHead(17);
    s.insertHead(15);
    LinkedList<int> t(s);
    s.deleteNodeWithKey(9);
    std::cout << s << t << std::endl;
    t = s;
    std::cout << s << t << std::endl;
}
