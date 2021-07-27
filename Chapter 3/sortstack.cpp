#include <bits/stdc++.h>

using namespace std;

class SortStack{
    public:
        stack<int> first;
        stack<int> second;
        void push(int);
        void switchLastValue(stack<int>&);
        void pop();
        int peek();
};

void SortStack::push(int value){
    if(first.empty() && second.empty())
        first.push(value);
    else if(!first.empty() && second.empty())
        second.push(value);
    else if(first.empty() && !second.empty())
        first.push(value);
    else{
        if(value < first.top() && value < second.top()){
            if(first.top() == min(first.top(),second.top()))
                first.push(value);
            else    
                second.push(value);
        }else if(value > first.top() && value > second.top()){
             if(first.top() == max(first.top(),second.top()))
                first.push(value);
            else    
                second.push(value);
        }else{
            if(abs(first.top() - value) < abs(second.top() - value))
                first.push(value);
            else if(abs(second.top() - value) < abs(first.top() - value))
                second.push(value);
            else{
                if(first.top() == min(first.top(),second.top()))
                    first.push(value);
                else    
                    second.push(value);
            }
        }
    }
    switchLastValue(first);
    switchLastValue(second);
}

void SortStack::switchLastValue(stack<int>& stck){
    if(!stck.empty()){
        int aux = stck.top();
        stck.pop();
        if(!stck.empty()){
            int aux2 = stck.top();
            if(aux < aux2)
                stck.push(aux);
            else{
                stck.pop();
                stck.push(aux);
                stck.push(aux2);
            }
        }else{
            stck.push(aux);
        }
    }
}


void SortStack::pop(){
    if(!first.empty() && !second.empty()){
        switchLastValue(first);
        switchLastValue(second);
        if(first.top() < second.top()){
            first.pop();
            if(first.empty()){
                push(second.top());
                second.pop();
            }
        }else{
            second.pop();
            if(second.empty()){
                push(first.top());
                first.pop();
            }
        }           
    } 
}

int SortStack::peek(){
    switchLastValue(first);
    switchLastValue(second);
    if(!first.empty() && !second.empty())
        return first.top() < second.top() ? first.top() : second.top();
    else if(!first.empty() && second.empty())
        return first.top();
    else    
        return second.top();
}

int main(){
    SortStack stck;
    stck.push(10);
    stck.push(7);
    stck.push(3);
    stck.push(14);
    stck.push(9);
    stck.push(6);
    stck.push(1);
    stck.push(4);
    stck.push(30);
    stck.push(2);
    stck.push(17);
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    stck.pop();
    cout << stck.peek() << endl;
    return 0;
}