#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node* right;
        Node* left;
        Node(int newValue){
            value = newValue;
            right = NULL;
            left = NULL;
        }
};

void insert(Node*& node, int newValue){
    if(node == NULL)
        node = new Node(newValue);
    else if(newValue <= node->value)
        insert(node->left,newValue);
    else
        insert(node->right,newValue);
}

bool search(Node* node, int searchValue){
    if(node != NULL){
        if(node->value == searchValue) 
            return true;
        else if(searchValue <= node->value) 
            return search(node->left, searchValue);
        else 
            return search(node->right, searchValue);
    }
    return false;
}

void inOrder(Node *node){
    if(node != NULL){
        inOrder(node->left);
        cout << node->value <<  " ";
        inOrder(node->right);
    }
}

void preOrder(Node *node){
    if(node != NULL){
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(Node *node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}


int main(){
    Node *root = NULL;
    insert(root,8);
    insert(root,10);
    insert(root,4);
    insert(root,2);
    insert(root,20);
    insert(root,6);
    cout << "Search 20: " << search(root,10) << endl;
    cout << "Search 1: " << search(root,1) << endl;
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}