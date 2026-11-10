#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(ll start, vector<ll>& dist, vector<ll> adj[], ll n){
    fill(dist.begin(), dist.end(), -1);

    queue<ll> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for(ll v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n, d;
        cin >> n >> d;

        vector<ll> adj[n+1];

        for(ll i = 0; i < n-1; i++){
            ll u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<ll>> dist(n+1, vector<ll>(n+1));

        for(ll i = 1; i <= n; i++) bfs(i, dist[i], adj, n);

        ll ans = 0;

        for(ll a = 1; a <= n; a++){
            for(ll b = a+1; b <= n; b++){
                ll d_ab = dist[a][b];

                for(ll c = b+1; c <= n; c++){
                    ll subtree_size = (d_ab + dist[b][c] + dist[c][a]) / 2 + 1;

                    if(subtree_size == d) ans++;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
