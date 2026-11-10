#include <bits/stdc++.h>
#define ll long long
using namespace std;

void build_depth(vector<vector<ll>> &child, vector<ll> &depth, ll n){
    vector<ll> stack;

    stack.push_back(1);

    while(!stack.empty()){
        ll node = stack.back();
        stack.pop_back();

        for(ll i = 0; i < child[node].size(); i++){
            ll next = child[node][i];

            depth[next] = depth[node] + 1;
            stack.push_back(next);
        }
    }
}

ll find_admin(ll a, ll b, vector<ll> &depth, vector<vector<ll>> &up, ll LOG){
    if(depth[a] < depth[b]) swap(a, b);

    ll diff = depth[a] - depth[b];

    for(ll i = LOG - 1; i >= 0; i--){
        if(diff & (1 << i)) a = up[a][i];
    }

    if(a == b) return a;

    for(ll i = LOG - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main(){
    ll n, q;
    cin >> n >> q;

    ll LOG = 1;

    while((1 << LOG) <= n) LOG++;

    vector<vector<ll>> child(n + 1);
    vector<vector<ll>> up(n + 1, vector<ll>(LOG, 0));
    vector<ll> depth(n + 1, 0);

    for(ll i = 2; i <= n; i++){
        ll parent;
        cin >> parent;

        child[parent].push_back(i);
        up[i][0] = parent;
    }

    build_depth(child, depth, n);

    for(ll j = 1; j < LOG; j++){
        for(ll i = 1; i <= n; i++) up[i][j] = up[up[i][j - 1]][j - 1];
    }

    while(q--){
        ll a, b;
        cin >> a >> b;

        cout << find_admin(a, b, depth, up, LOG) << endl;
    }

    return 0;
}
