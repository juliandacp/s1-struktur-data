#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll T;
    cin >> T;

    map<string, ll> freq;
    string kata;
    ll kamus1 = 0, kamus2 = 0;

    for(ll i = 0; i < T; i++){
        cin >> kata;

        freq[kata]++;

        if(freq[kata] == 1){
            cout << kata << " masuk Kamus 1!" << endl;
            kamus1++;
        }else if(freq[kata] == 2){
            cout << kata << " masuk Kamus 2!" << endl;
            kamus2++;
        }else cout << kata << " tidak bisa masuk Kamus!" << endl;
    }

    cout << "Kamus 1 berisi " << kamus1 << " kata" << endl;
    cout << "Kamus 2 berisi " << kamus2 << " kata" << endl;

    return 0;
}
