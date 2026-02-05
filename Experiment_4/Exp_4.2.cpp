#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            std::swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int n = heap.size();

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteAtIndex(int index) {
        int n = heap.size();
        if (index < 0 || index >= n) {
            std::cout << "Index out of range!" << std::endl;
            return;
        }

        heap[index] = heap.back();
        heap.pop_back();

        if (index < heap.size()) {
            heapifyDown(index);
            heapifyUp(index);
        }
    }

    void printHeap() {
        for (int i : heap) std::cout << i << " ";
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap mh;
    int values[] = {50, 30, 40, 10, 20, 35};
    for (int v : values) mh.insert(v);

    std::cout << "Initial Heap: ";
    mh.printHeap();

    std::cout << "Deleting element at index 1... " << std::endl;
    mh.deleteAtIndex(1);

    std::cout << "Resulting Heap: ";
    mh.printHeap();

    return 0;
}