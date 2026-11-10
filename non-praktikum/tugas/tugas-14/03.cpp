#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{
private:
    ll V;
    vector<vector<ll>> adj;
    vector<bool> visited;

public:
    Graph(ll vertices){
        V = vertices;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(ll u, ll v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(ll v){
        visited[v] = true;
        cout << v << " ";
        
        for(ll u : adj[v]) if(!visited[u]) DFS(u);
    }
};

int main(){
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "DFS : ";

    g.DFS(0);

    return 0;
}