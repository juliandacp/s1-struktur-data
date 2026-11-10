#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;

    cout << "Masukkan jumlah data: ";
    cin >> n;

    ll* data = new ll[n];

    for(ll i = 0; i < n; i++){
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    cout << endl << "Isi array:" << endl;

    for(ll i = 0; i < n; i++) cout << data[i] << " ";

    delete[] data;

    return 0;
}