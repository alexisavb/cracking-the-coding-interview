#include <bits/stdc++.h>

using namespace std;

class Stack{
    public: 
        vector<pair<int,int> > stack;
        void push(int, int);
        int top(int);
        void pop(int);
        bool isEmpty(int);
        void print();
};

void Stack::push(int value, int numStack){
    stack.push_back(make_pair(value,numStack));
}

int Stack::top(int numStack){
    for(int i = stack.size() - 1; i >= 0; i--)
        if(stack[i].second == numStack)
            return stack[i].first;
    throw "There isn't top to this stack.";
}

void Stack::pop(int numStack){
    for(int i = stack.size() - 1; i >= 0; i--){
        if(stack[i].second == numStack){
            stack.erase(stack.begin() + i);
            return;
        }         
    }
    throw "There isn't pop to this stack.";
}

bool Stack::isEmpty(int numStack){
     for(int i = stack.size() - 1; i >= 0; i--)
        if(stack[i].second == numStack)
            return false;
    return true;
}

void Stack::print(){
    for(int i = 0; i < stack.size(); i++)
        cout << "Value: " << stack[i].first << " Stack: " << stack[i].second << endl; 
}

int main(){
    Stack stack;
    stack.push(1,1);
    stack.push(1,2);
    stack.push(1,3);
    stack.push(2,1);
    stack.push(3,1);
    stack.print();
    
    try {
        cout << "Top Stack 1: " << stack.top(1) << endl;
        cout << "Top Stack 2: " << stack.top(3) << endl;
        cout << "Top Stack 3: " << stack.top(3) << endl;
        cout << "Is stack 3 empty? Before: " << stack.isEmpty(3) << endl;
        stack.pop(3);
        cout << "Is stack 3 empty? After: " << stack.isEmpty(3) << endl;
        stack.print();
        cout << "Top Stack 4: " << stack.top(4) << endl;
    }catch (const char* msg) {
        cerr << msg << endl;
    }
    
    return 0;
}