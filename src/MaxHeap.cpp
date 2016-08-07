#include <MaxHeap.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

MaxHeap::MaxHeap()
{
    _heap = {};
    _size = 0;
}

MaxHeap::MaxHeap(std::vector<int>& v) {
    build_max_heap(v);
}

MaxHeap::~MaxHeap()
{
    //dtor
}

int MaxHeap::size(void) {
    return _size;
}

void MaxHeap::build_max_heap(std::vector<int>& v) {
    _size = v.size();
    _heap = v;
    for (int i = floor(_size / 2); i >= 0; i--) {
        max_heapify(i);
    }

}

void MaxHeap::max_heapify(int i) {
    while (true) {
        int left = LEFT(i);
        int right = RIGHT(i);
        int largest;

        if (left < _size && _heap[i] < _heap[left]) {
            largest = left;
        } else {
            largest = i;
        }

        if (right < _size && _heap[largest] < _heap[right]) {
            largest = right;
        }

        if (i == largest) {
            return;
        }

        int tmp = _heap[i];
        _heap[i] = _heap[largest];
        _heap[largest] = tmp;

        i = largest;
    }
}

void MaxHeap::heap_increase_key(int i, int key) {
    if (key < _heap[i]) {
        std::cout << "Error, new key is smaller than current key" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        _heap[i] = key;
        while (i > 0 && _heap[PARENT(i)] < _heap[i]) {
            int tmp = _heap[i];
            _heap[i] = _heap[PARENT(i)];
            _heap[PARENT(i)] = tmp;
            i = PARENT(i);
        }
    }
}

void MaxHeap::heap_decrease_key(int i, int key) {
    if (key > _heap[i]) {
        std::cout << "Error, new key is larger than current key" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        _heap[i] = key;
        max_heapify(i);
    }
}

int MaxHeap::extract_heap_max(void) {
    if (_size < 1) {
        std::cout << "Error, Heap Underflow" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        int maxValue = heap_maximum();
        _heap[0] = _heap[_size - 1];
        _size--;
        max_heapify(0);
        return maxValue;
    }
}

int MaxHeap::heap_maximum(void) {
    return _heap[0];
}

void MaxHeap::heapsort(std::vector<int>& v) {
    build_max_heap(v);
    for (int i = v.size() - 1; i >= 0; i--) {
        // exchange a[0] with a[i]
        int tmp = _heap[0];
        _heap[0] = _heap[i];
        _heap[i] = tmp;
        // decrement heap size by 1
        _size--;
        // maintain the max heap property
        max_heapify(0);
    }

    for (int i = 0; i < v.size(); i++) {
        std::cout << _heap[i] << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::insert(int key) {
    _size++;
    _heap[_size - 1] = std::numeric_limits<int>::min();
    heap_increase_key(_size - 1, key);
}

void MaxHeap::print_heap(void) {
    for (int i = 1; i <= _size; i *= 2) {
        for (int j = i - 1; j < std::min(2 * i - 1, _size - 1) ; j++) {
            std::cout << _heap[j] << " ";
        }
        std::cout << std::endl;
    }
}
