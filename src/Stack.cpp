#include <iostream>
#include <stdio.h>
#include <stdexcept>

template<class T> class LinkedListStack;
template<class T>
    std::ostream& operator<<(std::ostream&, const LinkedListStack<T>&);

template <class T>
class LinkedListStack {
    friend std::ostream& operator<< <>(std::ostream& out, const LinkedListStack<T>& classObj);
    public:
        LinkedListStack() : m_top(nullptr), m_size(0) {}
        LinkedListStack(const LinkedListStack<T>& src);
        LinkedListStack<T>& operator=(const LinkedListStack<T>& src);
        ~LinkedListStack();
        void push(const T& value);
        const T& pop();
        const T& top() const;
        size_t size() const;
        bool empty() const;
    private:
        struct Node;
        Node *m_top;
        size_t m_size;
        LinkedListStack<T>* deepCopy(const LinkedListStack<T>& src);
};

template <class T>
struct LinkedListStack<T>::Node {
    T m_value;
    Node *m_next;
    Node(const T& value) : m_value(value) {}
    Node(const T& value, Node* nextPtr) : m_value(value), m_next(nextPtr) {}
};


template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedListStack<T>& stack) {
    typename LinkedListStack<T>::Node* curNodePtr = stack.m_top;

    while (curNodePtr != nullptr) {
        out << curNodePtr->m_value << " ";
        curNodePtr = curNodePtr->m_next;
    }

    out << std::endl;

    return out;
}

template<class T>
LinkedListStack<T>* LinkedListStack<T>::deepCopy(const LinkedListStack<T>& src) {
    if (src.empty()) {
        this->m_top = nullptr;
        this->m_size = 0;
    } else {
        Node* iterator = src.m_top;
        Node* newHead = new Node(iterator->m_value, nullptr);
        Node* newIterator = newHead;

        while (iterator->m_next != nullptr) {
            iterator = iterator->m_next;
            Node* newNode = new Node(iterator->m_value, nullptr);
            newIterator->m_next = newNode;
            newIterator = newIterator->m_next;
        }

        this->m_top = newHead;
        this->m_size = src.m_size;
    }
}

template<class T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& src) {
    std::cout << "Assignment operator was called" << std::endl;
    if (this == &src) {
        return *this;
    }
    return *deepCopy(src);
}

template<class T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& src) {
    std::cout << "Copy constructor is called" << std::endl;

    deepCopy(src);
}

template <class T>
LinkedListStack<T>::~LinkedListStack() {
    {
        Node* nextPtr;
        for (Node* curNodePtr = m_top; curNodePtr != nullptr; ) {
            nextPtr = curNodePtr->m_next;
            delete curNodePtr;
            curNodePtr = nextPtr;
        }
    }
}

template <class T>
void LinkedListStack<T>::push(const T& value) {
    Node* newNode = new Node(value, m_top);
    m_top = newNode;
    m_size++;
}

template <class T>
const T& LinkedListStack<T>::pop() {
    const T& top = LinkedListStack<T>::top();
    m_top = m_top->m_next;
    m_size--;
    return top;
}

template <class T>
const T& LinkedListStack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return m_top->m_value;
}

template <class T>
size_t LinkedListStack<T>::size() const {
    return m_size;
}

template<class T>
bool LinkedListStack<T>::empty() const {
    return m_size == 0;
}
