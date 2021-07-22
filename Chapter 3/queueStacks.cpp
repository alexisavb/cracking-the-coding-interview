#include <bits/stdc++.h>

using namespace std;

class MyQueue{
    public:
        stack<int> first;
        stack<int> second;
        void add(int);
        void remove();
        int peek();
        bool isEmpty();
};

void MyQueue::add(int value){
    if(first.empty())
        first.push(value);
    else    
        second.push(value);
}


void MyQueue::remove(){
    if(!first.empty()){
        first.pop();
        if(first.empty()){
            while(!second.empty()){
                first.push(second.top());
                second.pop();
            }
        }
        return;
    }   
    throw "Error";
}

int MyQueue::peek(){
    if(!first.empty())
        return first.top();
    throw "Error";
}

bool MyQueue::isEmpty(){
    return first.empty();
}

int main(){
    MyQueue myQueue;
    myQueue.add(1);
    myQueue.add(2);
    myQueue.add(3);
    myQueue.add(4);
    cout << myQueue.peek() << endl;
    myQueue.remove();
    cout << myQueue.peek() << endl;
    cout << "first: " << myQueue.first.size() << " second: " << myQueue.second.size() << endl;
    myQueue.add(4);
    cout << "first: " << myQueue.first.size() << " second: " << myQueue.second.size() << endl;
    myQueue.remove();
    cout << "first: " << myQueue.first.size() << " second: " << myQueue.second.size() << endl;
    myQueue.remove();
    myQueue.remove();
    cout << "first: " << myQueue.first.size() << " second: " << myQueue.second.size() << endl;
    return 0;
}