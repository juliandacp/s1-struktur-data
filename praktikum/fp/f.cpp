#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge{
    ll u, v;
};

struct DSU{
    vector<ll> parent;
    ll group;

    DSU(ll n){
        parent = vector<ll>(n + 1);
        group = n;

        for(ll i = 1; i <= n; i++) parent[i] = i;
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
    ll N, M;
    cin >> N >> M;

    vector<Edge> edges(M + 1);

    for(ll i = 1; i <= M; i++) cin >> edges[i].u >> edges[i].v;

    ll Q;
    cin >> Q;

    vector<ll> collapse(Q);
    vector<bool> is_collapse(M + 1, false);

    for(ll i = 0; i < Q; i++){
        cin >> collapse[i];
        is_collapse[collapse[i]] = true;
    }

    DSU dsu(N);

    for(ll i = 1; i <= M; i++){
        if(!is_collapse[i]) dsu.union_sets(edges[i].u, edges[i].v);
    }

    vector<ll> ans(Q);

    for(ll i = Q - 1; i >= 0; i--){
        ans[i] = dsu.group;

        ll edge_idx = collapse[i];

        dsu.union_sets(edges[edge_idx].u, edges[edge_idx].v);
    }

    for(ll i = 0; i < Q; i++) cout << ans[i] << endl;

    return 0;
}
