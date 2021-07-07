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

int kthLast(Node *head, int k){
    int lengthLinked = 0;
    int count = 0;
    Node *aux = head;

    while(head != NULL){
        lengthLinked++;
        head = head->next;
    }

    while(aux != NULL){
        if(count++ == lengthLinked - k)
            return aux->data;
        aux = aux->next;
    }
    return -1;
}

Node* kthLastR(Node *head, int k, int &i){
    if(head == NULL)
        return NULL;
    Node *hd = kthLastR(head->next, k, i);
    i += 1;
    if(i == k)
        return head;
    return hd;
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
    cout << kthLast(head,3) << endl;
    int i = 0;
    cout << kthLastR(head,3,i)->data << endl;
    return 0;
}