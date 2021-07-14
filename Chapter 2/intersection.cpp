#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        char data;
        Node *next;
        Node(char newData){
            data = newData;
            next = NULL;
        }
};

void addNode(Node *&head, Node *&tail, Node*&newNode){
    if(head == NULL)
        head = newNode;
    else    
        tail->next = newNode;
    tail = newNode;
}

void print(Node *head){
    while(head != NULL){
        cout << head << " ";
        head = head->next;
    }
    cout << endl;
}

int lengthLinked(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

Node* intersection(Node *first, Node *second){
   int lengthFirst = lengthLinked(first);
   int lengthSecond = lengthLinked(second);
   int count = 0;

   if(lengthFirst != lengthSecond){
        if(lengthFirst > lengthSecond)
            while(count++ < lengthFirst - lengthSecond)
                first = first->next;
        else    
            while(count++ < lengthSecond - lengthFirst)
                second = second->next;
   }

   while(first != NULL){
        if(first == second)
            return first;
        first = first->next;
        second = second->next;
   }
   return NULL;
}


int main(){
    Node *ft = NULL, *fh = NULL;
    Node *st = NULL, *sh = NULL;
    Node *one = new Node('a');
    Node *two = new Node('b');
    Node *three = new Node('c');
    Node *four = new Node('b');
    Node *five = new Node('a');
    Node *six = new Node('a');
    addNode(fh,ft,one);
    addNode(fh,ft,two);
    addNode(fh,ft,three);
    addNode(fh,ft,four);
    addNode(fh,ft,five);
    addNode(sh,st,six);
    addNode(sh,st,three);
    addNode(sh,st,four);
    addNode(sh,st,five);
    print(fh);
    print(sh);
    cout << intersection(fh,sh) << endl;
    return 0;
}