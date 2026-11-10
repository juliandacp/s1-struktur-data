#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll nilai[5];

    for(ll i = 0; i < 5; i++){
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    cout << endl;
    cout << "Status Kelulusan" << endl;

    for(ll i = 0; i < 5; i++){
        if(nilai[i] >= 75) cout << "Mahasiswa " << i + 1 << ": Lulus" << endl;
        else cout << "Mahasiswa " << i + 1 << ": Tidak Lulus" << endl;
    }
    
    return 0;
}