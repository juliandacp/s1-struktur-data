#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll Q;
    cin >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    while(Q--){
        string cmd;
        cin >> cmd;

        if(cmd == "ADD"){
            ll x;
            cin >> x;

            pq.push(x);
        }else if(cmd == "BUY"){
            if(pq.empty()) cout << -1 << endl;
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }

    return 0;
}
