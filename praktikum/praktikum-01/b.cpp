#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll index(vector<string>& names, string target){
    for(ll i = 0; i < names.size(); i++){
        if(names[i] == target) return i;
    }

    return -1;
}

int main(){
    ll n;
    cin >> n;

    vector<string> names(n);

    for(ll i = 0; i < n; i++) cin >> names[i];

    vector<ll> to(n);

    for(ll i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;

        ll u = index(names, x);
        ll v = index(names, y);

        to[u] = v;
    }

    string a, b;
    cin >> a >> b;

    ll start = index(names, a);
    ll end = index(names, b);
    vector<bool> visited(n, false);
    queue<ll> q;

    q.push(start);

    while(!q.empty()){
        ll cek = q.front();
        q.pop();

        if(visited[cek]) continue;

        visited[cek] = true;

        if(cek == end){
            cout << "Oalah, ez ini mah!" << endl;
            return 0;
        }

        q.push(to[cek]);
    }

    cout << "cooked" << endl;

    return 0;
}
