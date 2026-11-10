#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;

    unordered_map<ll, ll> m;

    for(ll i = 0; i < t; i++){
        ll n;
        cin >> n;

        for(ll j = 0; j < n; j++){
            ll id;
            cin >> id;

            m[id] = i;
        }
    }

    vector<queue<ll>> member(t);
    queue<ll> q;
    string cmd;

    while(cin >> cmd){
        if(cmd == "ENQUEUE"){
            ll x;
            cin >> x;

            ll dept = m[x];

            if(member[dept].empty()) q.push(dept);

            member[dept].push(x);
        }else if(cmd == "DEQUEUE"){
            ll dept = q.front();
            ll student = member[dept].front();

            member[dept].pop();

            cout << student << endl;

            if(member[dept].empty()) q.pop();
        }
    }

    return 0;
}
