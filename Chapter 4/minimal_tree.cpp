#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node *left;
        Node *right;
        Node(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};

void insert(Node*& node,int value){
    if(node == NULL)
        node = new Node(value);
    else if(value <= node->value)
        insert(node->left, value);
    else    
        insert(node->right, value);
}
        
bool search(Node* node,int value){
    if(node != NULL){
        if(node->value == value)
            return true;
        else if(value <= node->value)
            insert(node->left, value);
        else    
            insert(node->right, value);    }
    return false;
}


void buildTree(vector<int>&arr,int low, int high, Node*& root){
    int middle = low + (high - low) / 2;
    if(!search(root,arr[middle])){
        insert(root,arr[middle]);
        buildTree(arr,low,middle,root);
        buildTree(arr,middle,high,root);
    }
}

int main(){
    Node *root = NULL;
    vector<int> arr = {100,87,64,57,30,29,22,12,8,2};
    buildTree(arr,0,arr.size() - 1, root);
    return 0;
}