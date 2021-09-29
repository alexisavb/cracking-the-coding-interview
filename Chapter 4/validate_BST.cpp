#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        Node *left;
        Node *right;
        int value;
        Node(int newValue){
            this->left = NULL;
            this->right = NULL;
            this->value = newValue;
        }
};

class Tree{ 
    public:
        void addNode(Node *&node, int value){
            if(node == NULL)
                node = new Node(value);
            else if(value <= node->value)
                addNode(node->left,value);
            else
                addNode(node->right,value);
        }
        void inOrder(Node *node, int &last, bool &isBSF){
            if(node != NULL){                
                inOrder(node->left,last,isBSF);
                if(last > node->value)
                    isBSF = false;            
                last = node->value;
                inOrder(node->right,last,isBSF);
            }
        }
};

int main(){
    Tree tree;
    Node *head = NULL;
    int last = 0;
    bool isBSF = true;
    tree.addNode(head,40);
    tree.addNode(head,20);
    tree.addNode(head,60);
    tree.addNode(head,10);
    tree.addNode(head,25);
    tree.addNode(head,50);
    tree.addNode(head,71);
    tree.addNode(head,8);
    tree.addNode(head,15);
    tree.addNode(head,23);
    tree.addNode(head,70);
    tree.inOrder(head,last,isBSF);
    cout << "isBSF: " << isBSF << endl;
    return 0;
}