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

void deleteMiddleNode(Node *middleNode){
    if(middleNode != NULL && middleNode->next != NULL)
        middleNode->next = middleNode->next->next;
}

int main(){
    Node *tail = NULL, *head = NULL;
    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);
    Node *six = new Node(6);
    addNode(head,tail,one);
    addNode(head,tail,two);
    addNode(head,tail,three);
    addNode(head,tail,four);
    addNode(head,tail,five);
    addNode(head,tail,six);
    print(head);
    deleteMiddleNode(three);
    print(head);
    return 0;
}