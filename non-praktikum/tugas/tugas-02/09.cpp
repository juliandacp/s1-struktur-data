#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get_min(ll arr[], ll n){
    ll res = arr[0];

    for(ll i = 0; i < n; i++) res = min(res, arr[i]);
    return res;
}

ll get_max(ll arr[], ll n){
    ll res = arr[0];

    for(ll i = 0; i < n; i++) res = max(res, arr[i]);
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll arr[n];

    for(ll i = 0; i < n; i++) cin >> arr[i];

    cout << "Minimum element of array: " << get_min(arr, n) << endl;
    cout << "Maximum element of array: " << get_max(arr, n) << endl;
    return 0;
}