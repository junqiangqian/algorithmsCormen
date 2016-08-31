#include <iostream>
#include <stdio.h>
#include <stdexcept>

template<class T> class LinkedListQueue;
template<class T>
    std::ostream& operator<<(std::ostream&, const LinkedListQueue<T>&);

template <class T>
class LinkedListQueue {
    friend std::ostream& operator<< <>(std::ostream& out, const LinkedListQueue<T>& classObj);
    public:
        LinkedListQueue() : m_front(nullptr), m_back(nullptr), m_size(0) {}
        LinkedListQueue(const LinkedListQueue<T>& src);
        LinkedListQueue<T>& operator=(const LinkedListQueue<T>& src);
        ~LinkedListQueue();
        void enqueue(const T& value);
        const T& dequeue();
        const T& front() const;
        size_t size() const;
        bool empty() const;
    private:
        struct Node;
        Node *m_front;
        Node *m_back;
        size_t m_size;
        LinkedListQueue<T>* deepCopy(const LinkedListQueue<T>& src);
};

template <class T>
struct LinkedListQueue<T>::Node {
    T m_value;
    Node *m_next;
    Node(const T& value) : m_value(value) {}
    Node(const T& value, Node* nextPtr) : m_value(value), m_next(nextPtr) {}
};


template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedListQueue<T>& queue) {
    typename LinkedListQueue<T>::Node* curNodePtr = queue.m_front;

    while (curNodePtr != nullptr) {
        out << curNodePtr->m_value << " ";
        curNodePtr = curNodePtr->m_next;
    }

    out << std::endl;

    return out;
}

template<class T>
LinkedListQueue<T>* LinkedListQueue<T>::deepCopy(const LinkedListQueue<T>& src) {
    if (src.empty()) {
        this->m_front = nullptr;
        this->m_back = nullptr;
        this->m_size = 0;
    } else {
        Node* iterator = src.m_front;
        Node* newFront = new Node(iterator->m_value, nullptr);
        Node* newIterator = newFront;

        this->m_front = newFront;
        this->m_back = newFront;

        while (iterator->m_next != nullptr) {
            iterator = iterator->m_next;
            Node* newNode = new Node(iterator->m_value, nullptr);
            newIterator->m_next = newNode;
            newIterator = newIterator->m_next;
            this->m_back = newIterator;
        }

        this->m_size = src.m_size;
    }
}

template<class T>
LinkedListQueue<T>& LinkedListQueue<T>::operator=(const LinkedListQueue<T>& src) {
    std::cout << "Assignment operator was called" << std::endl;
    if (this == &src) {
        return *this;
    }
    return *deepCopy(src);
}

template<class T>
LinkedListQueue<T>::LinkedListQueue(const LinkedListQueue<T>& src) {
    std::cout << "Copy constructor is called" << std::endl;

    deepCopy(src);
}

template <class T>
LinkedListQueue<T>::~LinkedListQueue() {
    std::cout << "Destructor called" << std::endl;
    Node* nextPtr;
    for (Node* curNodePtr = m_front; curNodePtr != nullptr; ) {
        nextPtr = curNodePtr->m_next;
        delete curNodePtr;
        curNodePtr = nextPtr;
    }
}

template <class T>
void LinkedListQueue<T>::enqueue(const T& value) {
    Node * newNode = new Node(value);
    // If the queue is empty upon insertion of the new node, the front of the
    // queue is the same as the back
    if (empty()) {
        m_front = newNode;
        m_back = newNode;
    } else {
        m_back->m_next = newNode;
        m_back = m_back->m_next;
    }
    m_size++;
}

template <class T>
const T& LinkedListQueue<T>::dequeue() {
    const T& front = LinkedListQueue<T>::front();
    m_front = m_front->m_next;
    m_size--;
    return front;
}

template <class T>
const T& LinkedListQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return m_front->m_value;
}

template <class T>
size_t LinkedListQueue<T>::size() const {
    return m_size;
}

template<class T>
bool LinkedListQueue<T>::empty() const {
    return m_size == 0;
}
