#include <iostream>

template<class T> class LinkedList;
template<class T>
    std::ostream& operator<<(std::ostream&, const LinkedList<T>&);

template <class T>
class LinkedList {
        friend std::ostream& operator<< <>(std::ostream& out, const LinkedList<T>& classObj);
    private:
        struct Node;
        Node *m_head;
        size_t m_size;
    public:
        LinkedList() : m_head(nullptr), m_size(0) {}
        Node* search(const T& key);
        void insertHead(const T& key);
        void deleteNodeWithKey(const T& key);
};

template <class T>
struct LinkedList<T>::Node {
    T m_value;
    Node *m_next;
    Node(const T& value, Node *nextPtr) : m_value(value), m_next(nextPtr) {}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    typename LinkedList<T>::Node *iterator = list.m_head;
    while (iterator != nullptr) {
        os << iterator->m_value << " ";
        iterator = iterator->m_next;
    }
    os << std::endl;
    return os;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::search(const T& key) {
    Node *iterator = m_head;
    while (iterator != nullptr && iterator->m_value != key) {
        iterator = iterator->m_next;
    }
    return iterator;
}

template <class T>
void LinkedList<T>::insertHead(const T& key) {
    Node *newNode = new Node(key, m_head);
    if (!m_head) {
        m_head = newNode;
    } else {
        newNode->m_next = m_head;
        m_head = newNode;
    }
    m_size++;
}

template <class T>
void LinkedList<T>::deleteNodeWithKey(const T& key) {
    /* If the node we wish to delete is the head */
    if (m_head->m_value == key) {
        Node *newHead = m_head->m_next;
        delete m_head; /* Deallocate memory for the deleted node */
        m_head = newHead;
        m_size--;
    }
    /* Find the node before the node we wish to delete */
    Node *iterator = m_head;
    while (iterator != nullptr && iterator->m_next->m_value != key) {
        iterator = iterator->m_next;
    }

    if (iterator->m_next != nullptr) {
        Node *toDelete = iterator->m_next;
        iterator->m_next = iterator->m_next->m_next;
        delete toDelete;
        m_size--;
    }
}
