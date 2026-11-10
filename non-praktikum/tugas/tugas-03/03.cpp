#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll nilai[5];

    for(ll i = 0; i < 5; i++){
        cout << "Masukkan nilai ke-" << i << ": ";
        cin >> nilai[i];
    }

    cout << endl;
    cout << "Data yang dimasukkan: " << endl;

    for(ll i = 0; i < 5; i++) cout << nilai[i] << endl;
    
    return 0;
}