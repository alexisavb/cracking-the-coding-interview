#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
        unordered_map<string, list<pair<string,int>> > l;
    void addEdge(string to, string from, int weigh){
        l[to].push_back(make_pair(from,weigh));
        l[from].push_back(make_pair(to,weigh));
    }
    void print(){
        for(auto items: l){
            cout << items.first << "->";
            for(auto edges : items.second){
                cout << edges.first << " " << edges.second << ",";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",20);
    g.addEdge("B","D",40);
    g.addEdge("A","C",10);
    g.addEdge("C","D",40);
    g.addEdge("A","D",50);
    g.print();
    return 0;
}