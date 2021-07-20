#include <bits/stdc++.h>

using namespace std;

stack<int> mainStack;
stack<int> minStack;

void push(int value){
    mainStack.push(value);
    if(minStack.empty() || value <= minStack.top())
        minStack.push(value);    
}

void pop(){
    if(minStack.top() == mainStack.top())
        minStack.pop();
    mainStack.pop();
}

int min(){
    return minStack.top();
}

int main(){
    push(10);
    push(11);
    push(3);
    push(14);
    push(2);
    push(15);
    cout << min() << endl;
    pop();
    pop();
    cout << min() << endl;
    return 0;
}