#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> adj[100005];
bool visited[100005];

void dfs(ll node){
    visited[node] = true;

    for(auto next : adj[node]){
        if(!visited[next]) dfs(next);
    }
}

int main(){
    ll N, M;
    cin >> N >> M;

    for(ll i = 0; i < M; i++){
        ll A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    ll res = 0;

    for(ll i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
            res++;
        }
    }

    if(res == 1) cout << "Kompleksitas entitas terbentuk";
    else cout << "Seluruh kosmik tidak berkaitan, butuh " << res - 1 << " lagi";

    cout << endl;

    return 0;
}
