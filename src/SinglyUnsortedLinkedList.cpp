#include <iostream>

template<class T> class LinkedList;
template<class T>
    std::ostream& operator<<(std::ostream&, const LinkedList<T>&);

template <class T>
class LinkedList {
    public:
        LinkedList() : m_head(nullptr), m_size(0) {}
        Node* search(const T& key);
        void insert(const T& key);
        Node* delete(const T& key);
    private:
        struct Node;
        Node *m_head;
        size_t m_size;
};

template <class T>
struct LinkedList<T>::Node {
    T m_value;
    Node *m_next;
    Node(const T& value, Node *nextPtr) : m_value(value), m_next(nextPtr) {}
};
