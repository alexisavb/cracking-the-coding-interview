#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int newData){
            data = newData;
            next = NULL;
        }
};

void addNode(Node *&head, Node *&tail, Node *&newNode){
    if(head == NULL)
        head = newNode;
    else    
        tail->next = newNode;
    tail = newNode;
}

void print(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void partition(Node *&head, Node *&tail, int partition){
    Node *headLess = NULL, *tailLess = NULL;
    Node *headGreater = NULL, *tailGreater = NULL;

    while(head != NULL){
        Node *newNode = new Node(head->data);
        if(head->data < partition)
            addNode(headLess,tailLess,newNode);
        else
            addNode(headGreater,tailGreater,newNode);
        head = head->next;
    }
    
    head = headLess;
    tailLess->next = headGreater;
    tail = tailGreater;
}

int main(){
    Node *tail = NULL, *head = NULL;
    Node *one = new Node(3);
    Node *two = new Node(5);
    Node *three = new Node(8);
    Node *four = new Node(5);
    Node *five = new Node(10);
    Node *six = new Node(2);
    Node *seven = new Node(1);
    addNode(head,tail,one);
    addNode(head,tail,two);
    addNode(head,tail,three);
    addNode(head,tail,four);
    addNode(head,tail,five);
    addNode(head,tail,six);
    addNode(head,tail,seven);
    print(head);
    partition(head,tail,5);
    print(head);
    return 0;
}