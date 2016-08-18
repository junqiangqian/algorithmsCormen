#include <iostream>
#include <MaxHeap.h>

using namespace std;

int main() {
    vector<int> v = {-1, -3, 5, 1, 9, -1, 56, 60, 51, 66, 78, 1, 0};
    MaxHeap heap(v);
    heap.print_heap();
    heap.insert(123);
    heap.print_heap();
    return 0;
}
