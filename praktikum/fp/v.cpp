#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct schedule{
    ll mission;
    ll value;
    ll T;
    ll L;
    ll R;
};

void add_edge(ll u, ll v, vector<vector<ll>>& graph, vector<vector<ll>>& reverse_graph){
    graph[u].push_back(v);
    reverse_graph[v].push_back(u);
}

ll literal_node(ll mission, ll value){
    return 2 * mission + value;
}

void dfs1(ll u, vector<vector<ll>>& graph, vector<ll>& visited, vector<ll>& order){
    visited[u] = 1;

    for(ll v : graph[u]) if(!visited[v]) dfs1(v, graph, visited, order);

    order.push_back(u);
}

void dfs2(ll u, ll id, vector<vector<ll>>& reverse_graph, vector<ll>& component){
    component[u] = id;

    for(ll v : reverse_graph[u]) if(component[v] == -1) dfs2(v, id, reverse_graph, component);
}

int main(){
    ll N;
    cin >> N;

    vector<schedule> schedules;

    schedules.reserve(2 * N);

    for(ll i = 0; i < N; i++){
        ll TA, LA, RA;
        ll TB, LB, RB;
        cin >> TA >> LA >> RA >> TB >> LB >> RB;

        schedules.push_back({i, 0, TA, LA, RA});
        schedules.push_back({i, 1, TB, LB, RB});
    }

    ll nodes = 2 * N;
    vector<vector<ll>> graph(nodes);
    vector<vector<ll>> reverse_graph(nodes);
    ll M = schedules.size();

    for(ll i = 0; i < M; i++){
        for(ll j = i + 1; j < M; j++){
            if(schedules[i].mission == schedules[j].mission) continue;
            if(schedules[i].T != schedules[j].T) continue;

            ll overlap_L = max(schedules[i].L, schedules[j].L);
            ll overlap_R = min(schedules[i].R, schedules[j].R);

            if(overlap_L < overlap_R){
                ll a = literal_node(schedules[i].mission, schedules[i].value);
                ll b = literal_node(schedules[j].mission, schedules[j].value);

                add_edge(a, b ^ 1, graph, reverse_graph);
                add_edge(b, a ^ 1, graph, reverse_graph);
            }
        }
    }

    vector<ll> visited(nodes, 0);
    vector<ll> order;

    for(ll i = 0; i < nodes; i++){
        if(!visited[i]) dfs1(i, graph, visited, order);
    }

    reverse(order.begin(), order.end());

    vector<ll> component(nodes, -1);
    ll connect_count = 0;

    for(ll u : order){
        if(component[u] == -1){
            dfs2(u, connect_count, reverse_graph, component);
            connect_count++;
        }
    }

    for(ll i = 0; i < N; i++){
        if(component[2 * i] == component[2 * i + 1]){
            cout << "RIFT COLLAPSED" << endl;
            return 0;
        }
    }

    cout << "RIFT SEALED" << endl;

    return 0;
}
