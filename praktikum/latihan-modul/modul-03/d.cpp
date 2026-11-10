#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> adj[1005];
bool visited[1005];

void bfs(ll start){
    queue<ll> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        ll node = q.front();
        q.pop();

        for(auto next : adj[node]){
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(){
    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll Q;
        cin >> Q;

        for(ll j = 0; j < Q; j++){
            ll K;
            cin >> K;

            adj[i].push_back(K);
        }
    }

    bfs(0);

    bool area = true;

    for(ll i = 0; i < N; i++){
        if(!visited[i]) area = false;
    }

    if(area) cout << "Para peserta LBH berhasil keluar!" << endl;
    else cout << "Para peserta LBH terjebak selamanya." << endl;

    return 0;
}
