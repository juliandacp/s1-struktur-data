#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> adj[105];
bool visited[105];

void dfs(ll node){
    visited[node] = true;

    for(auto next : adj[node]){
        if(!visited[next]) dfs(next);
    }
}

int main(){
    ll n;
    cin >> n;

    vector<ll> num(n);

    for(ll i = 0; i < n; i++) cin >> num[i];

    ll c;
    cin >> c;

    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            ll res = num[i] ^ num[j];

            if(res % c == 0){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    ll kelompok = 0;

    for(ll i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            kelompok++;
        }
    }

    cout << kelompok << endl;

    return 0;
}
