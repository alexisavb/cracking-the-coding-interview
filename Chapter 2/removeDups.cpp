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


void removeDupsWithoutBuffer(Node *head){
    Node *node = head;
    while(node->next != NULL){
        Node *aux  = node;
        while(aux->next != NULL){
            if(aux->next->data == node->data)
                aux->next = aux->next->next;
            aux = aux->next;
        }
        node = node->next;
    }
    print(head);
}

void removeDupsWithBuffer(Node *head){
    Node *node = head;
    Node *prev = NULL;
    unordered_set<int> values;

    while(node->next != NULL){
        if(values.find(node->data) != values.end()){
            prev->next = node->next;
        }else{
            values.insert(node->data);
            prev = node;
        }
        node = node->next;
    }
    print(head);
}


int main(){
    Node *tail = NULL, *head = NULL;
    Node *one = new Node(5);
    Node *two = new Node(7);
    Node *three = new Node(5);
    Node *four = new Node(7);
    Node *five = new Node(8);
    Node *six = new Node(10);
    addNode(head,tail,one);
    addNode(head,tail,two);
    addNode(head,tail,three);
    addNode(head,tail,four);
    addNode(head,tail,five);
    addNode(head,tail,six);
    print(head);
    removeDupsWithoutBuffer(head);
    removeDupsWithBuffer(head);
    return 0;
}