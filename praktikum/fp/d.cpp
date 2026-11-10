#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge{
    ll weight;
    ll u, v;

    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

struct Query{
    ll P;
    ll id;

    bool operator<(const Query& other) const{
        return P < other.P;
    }
};

struct DSU{
    vector<ll> parent;
    ll group;

    DSU(ll n){
        parent.resize(n);

        for(ll i = 0; i < n; i++) parent[i] = i;

        group = n;
    }

    ll find_set(ll v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    bool union_sets(ll a, ll b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
            parent[b] = a;
            group--;
            return true;
        }

        return false;
    }
};

int main(){
    ll N, Q;
    cin >> N >> Q;

    vector<pair<ll, ll>> coordinates(N);

    for(ll i = 0; i < N; ++i) cin >> coordinates[i].first >> coordinates[i].second;

    vector<Edge> edges;

    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            ll dx = coordinates[i].first - coordinates[j].first;
            ll dy = coordinates[i].second - coordinates[j].second;
            ll dist = dx * dx + dy * dy;

            edges.push_back({dist, i, j});
        }
    }

    sort(edges.begin(), edges.end());

    vector<Query> q(Q);

    for(ll i = 0; i < Q; ++i){
        cin >> q[i].P;
        q[i].id = i;
    }

    sort(q.begin(), q.end());

    vector<ll> ans(Q);
    DSU dsu(N);
    ll edge_idx = 0;
    ll num_edges = edges.size();

    for(ll i = 0; i < Q; i++){
        while(edge_idx < num_edges && edges[edge_idx].weight <= q[i].P){
            dsu.union_sets(edges[edge_idx].u, edges[edge_idx].v);
            edge_idx++;
        }

        ans[q[i].id] = dsu.group;
    }

    for(ll i = 0; i < Q; i++) cout << ans[i] << endl;

    return 0;
}
