#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        char animal;
        int order;
        Node *next;
        Node(char newAnimal, int newOrder){
            animal = newAnimal;
            order = newOrder;
            next = NULL;
        }
};

class Shelter{
    public:
        Node *headCat = NULL, *tailCat = NULL;
        Node *headDog = NULL, *tailDog = NULL;
        int order = 1;
        void enqueue(char);
        void dequeueAny();
        void dequeueCat();
        void dequeueDog();
        void print();
    private:
        void newNode(Node *&, Node *&, char);
};

void Shelter::newNode(Node *&head, Node *&tail, char value){
    Node *newNd = new Node(value,order++);
    if(head == NULL)
        head = newNd;
    else    
        tail->next = newNd;
    tail = newNd;
}

void Shelter::enqueue(char value){
    if(value == 'C')
        newNode(headCat,tailCat,value);
    else
        newNode(headDog,tailDog,value);
}

void Shelter::dequeueAny(){
    if(headDog != NULL && headCat != NULL){
        if(headDog->order < headCat->order)
            headDog = headDog->next;
        else    
            headCat = headCat->next;
    }else if(headCat != NULL){
        headCat = headCat->next;
    }else if(headDog != NULL){
        headDog = headDog->next;
    }
}

void Shelter::dequeueCat(){
    if(headCat != NULL)
        headCat = headCat->next;
}

void Shelter::dequeueDog(){
    if(headDog != NULL)
        headDog = headDog->next;
}

void Shelter::print(){
    Node *aux = headDog;
    while(aux != NULL){
        cout << aux->animal << "-" << aux->order << "->";
        aux = aux->next;
    }
    Node *aux2 = headCat;
    cout << endl;
    while(aux2 != NULL){
        cout << aux2->animal << "-" << aux2->order << "->";
        aux2 = aux2->next;
    }
    cout << endl;
}

int main(){
    Shelter shelter;
    shelter.enqueue('C');
    shelter.enqueue('D');
    shelter.enqueue('D');
    shelter.enqueue('C');
    shelter.enqueue('D');
    shelter.enqueue('D');
    shelter.print();
    shelter.dequeueAny();
    shelter.print();
    shelter.dequeueAny();
    shelter.print();
    shelter.dequeueDog();
    shelter.print();
    shelter.dequeueDog();
    shelter.print();
    shelter.dequeueCat();
    shelter.print();
    return 0;
}