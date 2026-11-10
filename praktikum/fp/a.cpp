#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll N;
    cin >> N;

    unordered_map<string, ll> m;

    while(N--){
        string W;
        cin >> W;

        string prefix = "";

        for(ll i = 0; i < W.size(); i++){
            prefix += W[i];
            m[prefix]++;
        }
    }

    ll Q;
    cin >> Q;

    while(Q--){
        string S;
        cin >> S;

        cout << m[S] << endl;
    }

    return 0;
}
