#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{
private:
    ll matrix[100][100];
    ll vertices;

public:
    Graph(ll v){
        vertices = v;

        for(ll i = 0; i < v; i++) for(ll j = 0; j < v; j++) matrix[i][j] = 0;
    }

    void addEdge(ll u, ll v){
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void display(){
        cout << "Adjacency Matrix" << endl;
        
        for(ll i = 0; i < vertices; i++){
            for(ll j = 0; j < vertices; j++) cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.display();

    return 0;
}