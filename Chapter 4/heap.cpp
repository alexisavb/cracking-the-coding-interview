#include <bits/stdc++.h>

using namespace std;

class Heap{
    private:
        int size = 0;
        vector<int> items;
        void heapifyUp();
        void heapifyDown();
        int getLeftChildrenIndex(int index){ return 2 * index - 1;}
        int getRightChildrenIndex(int index){ return 2 * index - 2;}
        int getParentIndex(int index){ return (index - 1) / 2;}
        bool hasLeftChildren(int index) { return getLeftChildrenIndex(index) < size; }
        bool hasRightChildren(int index){ return getRightChildrenIndex(index) < size; }
        bool hasParent(int index) { return getParentIndex(index) >= 0; }
        int leftChildren(int index) { return items[getLeftChildrenIndex(index)]; }
        int rightChildren(int index) { return items[getRightChildrenIndex(index)]; }
        int parent(int index){ return items[getParentIndex(index)];}
    public:
        int peek(){ return size != 0 ? items[0] : throw "Error"; }
        void swap(int,int);
        void insert(int);
        int poll();
};

void Heap::swap(int indexOne, int indexTwo){
    int temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

void Heap::heapifyUp(){
    int index = size - 1;
    while(hasParent(index) && parent(index) > items[index]){
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void Heap::heapifyDown(){
    int index = 0;
    while(hasLeftChildren(index)){
        int smallIndex = getLeftChildrenIndex(index);
        if(hasRightChildren(index) && rightChildren(index) < leftChildren(index))
            smallIndex = getRightChildrenIndex(index);
        
        if(items[smallIndex] < items[index])
            swap(index, smallIndex);
        else
            break;
        
        index = smallIndex;
    }
}

void Heap::insert(int value){
    items.push_back(value);
    size++;
    heapifyUp();
}

int Heap::poll(){
    if(size == 0) throw "Error";
    int temp = items[0];
    items[0] = items[size - 1];
    size--;
    heapifyDown();
    return temp;
}


int main(){
    Heap heap;
    heap.insert(10);
    heap.insert(80);
    heap.insert(3);
    heap.insert(7);
    heap.insert(9);
    cout << heap.peek() << endl;
    return 0;
}