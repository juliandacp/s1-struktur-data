#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{
private:
    ll V;
    vector<pair<ll, ll>> adj[100];

public:
    Graph(ll vertices){
        V = vertices;
    }

    void addEdge(ll u, ll v, ll weight){
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    void display(){
        for(ll i = 0; i < V; i++){
            cout << "Vertex " << i << " : ";
            
            for(auto edge : adj[i]) cout << "(" << edge.first << "," << edge.second << ") ";
            cout << endl;
        }
    }
};

int main(){
    Graph g(4);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    
    g.display();

    return 0;
}