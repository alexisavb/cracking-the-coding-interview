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

Node* loopDetection(Node *head){
    Node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }

    if(fast == NULL || slow == NULL)
        return NULL;
    
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){
    Node *tail = NULL, *head = NULL;
    Node *one = new Node('a');
    Node *two = new Node('b');
    Node *three = new Node('c');
    Node *four = new Node('b');
    Node *five = new Node('e');
    addNode(head,tail,one);
    addNode(head,tail,two);
    addNode(head,tail,three);
    addNode(head,tail,four);
    addNode(head,tail,five);
    addNode(head,tail,two);
    Node * result = loopDetection(head);
    cout << "Reference: " << result << " Value: " << result->data << endl;
    return 0;
}