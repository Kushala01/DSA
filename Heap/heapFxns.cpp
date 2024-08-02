#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int heap[MAX_SIZE];
int heap_size = 0;

void insert(int number) {
    if (heap_size == 0) {
        heap[1] = number;
        heap_size = 1;
    } else {
        heap_size++;
        heap[heap_size] = number;

        int child = heap_size;
        int parent = child / 2;

        while (parent >= 1 && heap[parent] > heap[child]) {
            swap(heap[parent], heap[child]);
            child = parent;
            parent = child / 2;
        }
    }
}

void deleteMin() {
    if (heap_size == 0) {
        cout << "Heap is empty, no more elements can be removed\n";
        return;
    }

    swap(heap[1], heap[heap_size]);
    heap[heap_size] = 0;
    heap_size--;

    int parent = 1;
    int child1 = 2;
    int child2 = 3;

    while ((child1 <= heap_size && heap[parent] > heap[child1]) || 
           (child2 <= heap_size && heap[parent] > heap[child2])) {
        if (child2 > heap_size || heap[child1] < heap[child2]) {
            swap(heap[parent], heap[child1]);
            parent = child1;
        } else {
            swap(heap[parent], heap[child2]);
            parent = child2;
        }
        child1 = 2 * parent;
        child2 = 2 * parent + 1;
    }
}

int main() {
    int operations;
    cin >> operations;

    for (int i = 0; i < operations; ++i) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int number;
            cin >> number;
            insert(number);
        } else if (operation == 2) {
            if (heap_size >= 1) {
                cout << heap[1] << '\n';
            } else {
                cout << "Heap is empty\n";
            }
        } else {
            deleteMin();
        }
    }
    return 0;
}