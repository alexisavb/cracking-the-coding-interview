#include <bits/stdc++.h>

using namespace std;


class Graph{
    private:
        vector<int> *adj;
        int nodes;
    public:
        Graph(int nodes){
            this->nodes = nodes;
            adj = new vector<int>[nodes];
        }
        bool route(int,int);
        void add(int,int);
};

void Graph::add(int start, int end){
    adj[start].push_back(end);
}


bool Graph::route(int start, int end){
    queue<int> q;
    bool visit[nodes] = {0};
    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0; i < adj[current].size(); i++){
            if(!visit[adj[current][i]]){
                if(adj[current][i] == end) return true;
                q.push(adj[current][i]);
                visit[adj[current][i]] = true;
            }
        }
    }
    return false;
}

int main(){
    Graph g(7);
    g.add(0,2);
    g.add(2,1);
    g.add(1,3);
    g.add(3,5);
    g.add(4,5);
    g.add(4,6);
    g.add(5,6);
    cout << g.route(0,4) << endl;
    cout << g.route(5,0) << endl;
    cout << g.route(0,3) << endl;
    cout << g.route(2,5) << endl;
    return 0;
}