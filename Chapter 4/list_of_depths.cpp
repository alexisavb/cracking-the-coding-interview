#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int value;
        Node* right;
        Node* left;
        Node(int value){
            this->value = value;
            right = NULL;
            left = NULL;
        }
};

void insert(Node*& root, int value){
    if(root == NULL)
        root = new Node(value);
    else if(value <= root->value)
        insert(root->left,value);
    else
        insert(root->right,value);
}

vector<list<int> > depths(Node *root){
    vector<list<int> > linked;
    if(root != NULL){
        queue <pair<Node*,int> > q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*,int> node = q.front();
            if(linked.size() < node.second + 1){
                list<int> aux;
                aux.push_back(node.first->value);
                linked.push_back(aux);
            }else{
                linked[node.second].push_back(node.first->value);
            }
                
           
            if(node.first->right != NULL)
                q.push(make_pair(node.first->right,node.second + 1));
            if(node.first->left != NULL)
                q.push(make_pair(node.first->left,node.second + 1));
            
            q.pop();
        }
    }
    return linked;
}


int main(){
    Node *root = NULL;
    insert(root,30);
    insert(root,12);
    insert(root,87);
    insert(root,8);
    insert(root,22);
    insert(root,64);
    insert(root,100);
    insert(root,2);
    insert(root,9);
    insert(root,20);
    insert(root,29);
    insert(root,57);
    insert(root,70);
    insert(root,94);
    insert(root,300);
   vector<list<int> > result = depths(root);
    for(list<int> lists : result){
        for(int value : lists){
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}