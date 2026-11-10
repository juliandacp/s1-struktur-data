#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll nilai[5], total = 0;
    float rerata;

    for(ll i = 0; i < 5; i++){
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
        total += nilai[i];
    }

    rerata = total / 5.0;

    cout << endl;
    cout << "Total nilai: " << total << endl;
    cout << "Rata-rata nilai: " << rerata << endl;
    
    return 0;
}