#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

class MaxHeap {

    private:
        std::vector<int> _heap;
        int _size;
        void build_max_heap(std::vector<int>& v);
        void max_heapify(int i);
    public:
        MaxHeap();
        MaxHeap(std::vector<int>&);
        ~MaxHeap();
        int size(void);
        int extract_heap_max(void);
        int heap_maximum(void);
        void heap_increase_key(int i, int key);
        void heap_decrease_key(int i, int key);
        void heapsort(std::vector<int>& v);
        void insert(int key);
        void print_heap(void);


};

#endif // MAXHEAP_H
