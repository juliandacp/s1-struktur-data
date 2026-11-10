#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    map<string, pair<ll, string>> data;
    ll N;
    cin >> N;

    while(N--){
        string label;
        string nama, asal;
        ll usia;

        cin >> label >> nama;
        cin >> label >> usia;
        cin >> label >> asal;

        data[nama] = make_pair(usia, asal);
    }

    ll Q;
    cin >> Q;

    while(Q--){
        string nama;
        cin >> nama;

        cout << "Usia: " << data[nama].first << endl;
        cout << "Asal: " << data[nama].second << endl;
    }

    return 0;
}
