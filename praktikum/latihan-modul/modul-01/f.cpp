#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll N;
    cin >> N;

    queue<ll> data;

    while(N--){
        ll a;
        cin >> a;

        data.push(a);
    }

    ll S;
    cin >> S;

    while(S-- && !data.empty()){
        string s;
        cin >> s;

        if(s == "BERHASIL") data.pop();
        else if(s == "GAGAL"){
            data.push(data.front());
            data.pop();
        }
    }

    if(data.empty()) cout << "KOSONG";
    else{
        while(!data.empty()){
            cout << data.front() << " ";
            data.pop();
        }
    }

    return 0;
}
