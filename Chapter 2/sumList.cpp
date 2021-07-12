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

Node* sumList(Node *first, Node *second){
    int carry = 0;
    Node *sumHead = NULL, *sumTail = NULL;

    while(first != NULL || second != NULL){
        int auxFirst = 0, auxSecond = 0;
        if(first != NULL){
            auxFirst = first->data;
            first = first->next;
        }
        if(second != NULL){
            auxSecond = second->data;
            second = second->next;
        }
        Node *sum = new Node((auxFirst + auxSecond + carry) % 10);
        addNode(sumHead,sumTail, sum);
        carry = (auxFirst + auxSecond) / 10;
    }
    return sumHead;
}

int lengthLink(Node *node){
    int sum = 0;
    while(node != NULL){
        sum++;
        node = node->next;
    }
    return sum;
}

int sumLinked(Node *node, int length){
    int sum = 0;
    while(node != NULL){
        int power = (int)(pow(10, length - 1) + 0.5);
        int result = node->data * power;
        sum += result;
        length--;
        node = node->next;
    }
    return sum;
}

Node* sumListReverse(Node *first, Node *second){
    Node *auxH = NULL, *auxT = NULL;
    int lengthF = 0, lengthS = 0, sum = 0;
    vector<int> arr;
    lengthF = lengthLink(first);
    lengthS = lengthLink(second);
    sum = sumLinked(first, lengthF) + sumLinked(second, lengthS); 
    
    while(sum > 0){
        arr.push_back(sum % 10);
        sum /= 10;
    }

    for(int i = arr.size() - 1; i >= 0; i--){
        Node *aux = new Node(arr[i]);
        addNode(auxH,auxT,aux);
    }

    return auxH;
}

int main(){
    Node *tail = NULL, *head = NULL;
     Node *tailS = NULL, *headS = NULL;
    Node *one = new Node(7);
    Node *two = new Node(1);
    Node *three = new Node(6);
    Node *four = new Node(5);
    Node *five = new Node(9);
    Node *six = new Node(2);
    addNode(head,tail,one);
    addNode(head,tail,two);
    addNode(head,tail,three);
    addNode(headS,tailS,four);
    addNode(headS,tailS,five);
    addNode(headS,tailS,six);
    print(head);
    print(headS);
    Node *sum = sumList(head,headS);
    print(sum);
    Node *sumReverse = sumListReverse(head,headS);
    print(sumReverse);
    return 0;
}