#include <iostream>
#include "Stack.cpp"

int main() {
    LinkedListStack<int> stack;
    stack.push(5);
    stack.push(67);
    stack.push(99);
    std::cout << stack.top() << std::endl;
    std::cout << stack.size() << std::endl;
    LinkedListStack<int> stack2(stack);
    LinkedListStack<int> stack3;
    stack2.push(56);
    stack3 = stack2;
    std::cout << stack;
    std::cout << stack2;
    std::cout << stack3;
    return 0;
}
