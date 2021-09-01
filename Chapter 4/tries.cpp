#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        unordered_map<char,Node*> children;
        bool isCompletedWord;
        Node(){ isCompletedWord = false; }
};

class Trie{
    public:
        void insert(Node*&,string);
        bool search(Node*&,string);
        bool prefix(Node*&,string);
};

void Trie::insert(Node*& root, string str){
    if (root == NULL) 
        root = new Node();
    
    Node* current = root;
    for(int i = 0; i < str.size(); i++){
        if(current->children[str[i]] == NULL)
            current->children[str[i]] = new Node;
        current = current->children[str[i]];
    }
    current->isCompletedWord = true;
}

bool Trie::search(Node*& root, string str){
    if (root == NULL) 
        return false;

    Node* current = root;
    for(int i = 0; i < str.size(); i++){
        if(current->children[str[i]] == NULL)
            return false;
        current = current->children[str[i]];
    }
    return current->isCompletedWord;
}

bool Trie::prefix(Node*& root, string str){
    if (root == NULL) 
        return false;

    Node* current = root;
    for(int i = 0; i < str.size(); i++){
        if(current->children[str[i]] == NULL)
            return false;
        current = current->children[str[i]];
    }
    return true;
}

int main(){
    Node *root = NULL;
    Trie trie;
    trie.insert(root,"apple");
    cout << "apple: " << trie.search(root,"apple") << endl;
    cout << "appe: " << trie.search(root,"appe") << endl;
    trie.insert(root,"appe");
    cout << "appe: " << trie.search(root,"appe") << endl;
    cout << "apple: " << trie.search(root,"apple") << endl;
    trie.insert(root,"bottas");
    cout << "bottas: " << trie.search(root,"bottas") << endl;
    cout << "boa: " << trie.search(root,"boa") << endl;
    cout << "prex->bot: " << trie.prefix(root,"bot") << endl;
    return 0;
}