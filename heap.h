//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        if (size == 0) {
            return -1;
        }
        int root = data[0];
        data[0] = data[size - 1];
        size--;
        // Replace root with last element, then call downheap()
        if (size > 0) {
            downheap(0, weightArr);
        }
        return root; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] >= weightArr[data[parent]]) {
                pos = 0;
            }
            else {
                std::swap(data[pos], data[parent]);
                pos = parent;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        bool moved = true;
        while (moved) {
            moved = false;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }
            if (smallest != pos) {
                std::swap(data[pos], data[smallest]);
                pos = smallest;
                moved = true;
            }
        }
    }
};

#endif