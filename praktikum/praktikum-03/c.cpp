#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;

    ll a[n + 1];

    for(ll i = 1; i <= n; i++) cin >> a[i];

    vector<ll> dist(n + 1, -1);
    queue<ll> q;

    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        ll pos = q.front();
        q.pop();

        if(pos > 1 && dist[pos - 1] == -1){
            dist[pos - 1] = dist[pos] + 1;
            q.push(pos - 1);
        }

        if(pos < n && dist[pos + 1] == -1){
            dist[pos + 1] = dist[pos] + 1;
            q.push(pos + 1);
        }

        ll pow_jump = pos + a[pos];

        if(pow_jump <= n && dist[pow_jump] == -1){
            dist[pow_jump] = dist[pos] + 1;
            q.push(pow_jump);
        }

        if(dist[n] != -1) break;
    }
    
    cout << dist[n] << endl;

    return 0;
}
