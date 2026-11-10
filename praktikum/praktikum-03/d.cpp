#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll N, M, KS, KC, KR;
    cin >> N >> M >> KS >> KC >> KR;

    char P[N + 1];

    for(ll i = 1; i <= N; i++) cin >> P[i];

    vector<ll> adj[N + 1];

    for(ll i = 1; i <= M; i++){
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> team(N + 1, -1);
    queue<ll> q;

    team[1] = 1;
    q.push(1);

    while(!q.empty()){
        ll member = q.front();
        q.pop();

        for(ll neighbor : adj[member]){
            if(team[neighbor] == -1){
                team[neighbor] = 3 - team[member];
                q.push(neighbor);
            }else if(team[member] == team[neighbor]){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    ll s1 = 0, c1 = 0, r1 = 0;
    ll s2 = 0, c2 = 0, r2 = 0;

    for(ll i = 1; i <= N; i++){
        if(team[i] == 1){
            if(P[i] == 'S') s1++;
            else if(P[i] == 'C') c1++;
            else r1++;
        }else{
            if(P[i] == 'S') s2++;
            else if(P[i] == 'C') c2++;
            else r2++;
        }
    }

    if(s1 >= KS && s2 >= KS && c1 >= KC && c2 >= KC && r1 >= KR && r2 >= KR){
        for(ll i = 1; i <= N; i++) cout << team[i] << " ";
        cout << endl;
    }else cout << "IMPOSSIBLE" << endl;

    return 0;
}
