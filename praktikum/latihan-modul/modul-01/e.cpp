#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll T;
    vector<ll> data;
    cin >> T;

    while(T--){
        ll input;
        cin >> input;

        if(input == 1){
            ll x;
            cin >> x;

            data.push_back(x);
        }else if(input == 2){
            ll x;
            cin >> x;

            for(ll i = 0; i < data.size(); i++) data[i] += x;
        }else if(input == 3){
            if(!data.empty()) data.pop_back();
            else{
                cout << "kosong woe\n";
            }
        }else if(input == 4){
            if(!data.empty()){
                for(ll i = 0; i < data.size(); i++) cout << data[i] << " ";

                cout << endl;
            }else cout << "gaada isinya :(\n";
        }else if(input == 5){
            ll y, x;
            cin >> y >> x;

            data.push_back(0);

            vector<ll> temp = data;

            for(ll i = y; i < data.size()-1; i++) data[i+1] = temp[i];

            data[y] = x;
        }
    }

    return 0;
}
