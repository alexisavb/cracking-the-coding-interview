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
        cout << head->data << " ";
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

bool palindrome(Node *head){
    int length = lengthLinked(head), count = 0;
    stack<char> stck;

    while(count++ < length / 2){
        stck.push(head->data);
        head = head->next;
    }

    if(length % 2 != 0)
        head = head->next;
    
    while(head != NULL){
        if(stck.top() != head->data)
            return false;
        head = head->next;
        stck.pop();
    }
    return true;
}

int main(){
    Node *tail = NULL, *head = NULL;
    Node *one = new Node('a');
    Node *two = new Node('b');
    Node *three = new Node('c');
    Node *four = new Node('b');
    Node *five = new Node('a');
    addNode(head,tail,one);
    addNode(head,tail,two);
    addNode(head,tail,three);
    addNode(head,tail,four);
    addNode(head,tail,five);
    print(head);
    cout << palindrome(head) << endl;
    return 0;
}