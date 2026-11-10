#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1000000;
vector<pair<ll, ll>> graph[100];

void dijkstra(ll start, ll V){
    vector<ll> dist(V, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();

        for(auto edge : graph[u]){
            ll v = edge.first;
            ll w = edge.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Jarak Terpendek" << endl;

    for(ll i = 0; i < V; i++) cout << i << " : " << dist[i] << endl;
}

int main(){
    ll V = 5;

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({0, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 8});
    graph[2].push_back({4, 10});
    graph[3].push_back({1, 5});
    graph[3].push_back({2, 8});
    graph[3].push_back({4, 2});
    graph[4].push_back({2, 10});
    graph[4].push_back({3, 2});

    dijkstra(0, V);

    return 0;
}