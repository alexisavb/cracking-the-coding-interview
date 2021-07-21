 #include <bits/stdc++.h>

 using namespace std;

 const int limit = 5;

 class SetOfStacks{
    public:
        vector<stack<int> > stacks;
        int index = 0;
        void push(int);
        int top();
        void pop();   
        void popAt(int);
 };

 void SetOfStacks::push(int value){
    if(!stacks.empty() && stacks[index].size() != limit){
        stacks[index].push(value); 
    }else{
        if(!stacks.empty())
            index++;
        stack<int> stck;
        stck.push(value);
        stacks.push_back(stck);
    }
 }

 int SetOfStacks::top(){
    if(!stacks.empty())
        return stacks[index].top();
    throw "Error";
 }

 void SetOfStacks::pop(){
    if(!stacks.empty()){
        stacks[index].pop();
        if(stacks[index].empty()){
            stacks.erase(stacks.begin() + index);
            if(index != 0) index--;
        }
        return;
    }
    throw "Error";
 }

 void SetOfStacks::popAt(int ind){
    if(ind > index) throw "Error";
    if(!stacks.empty()){
        stacks[ind].pop();
        if(stacks[ind].empty()){
            stacks.erase(stacks.begin() + ind);
            if(index != 0) index--;
        }
    }
 }

 int main(){
    SetOfStacks stacks;
    stacks.push(1);
    stacks.push(2);
    stacks.push(3);
    stacks.push(4);
    stacks.push(5);
    cout << stacks.index << endl;
    stacks.push(6);
    stacks.push(7);
    stacks.push(8);
    stacks.push(9);
    stacks.push(10);
    cout << stacks.index << endl;
    stacks.push(11);
    stacks.push(12);
    cout << stacks.index << endl;
    stacks.pop();
    stacks.pop();
    cout << stacks.index << endl;
    stacks.push(11);
    cout << stacks.index << endl;
    stacks.popAt(1);
    stacks.popAt(1);
    stacks.popAt(1);
    stacks.popAt(1);
    stacks.popAt(1); 
    cout << stacks.index << endl;
    return 0;
 }

