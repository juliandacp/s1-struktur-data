#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_prime(ll n){
    if(n <= 1) return false;

    for(ll i = 2; i < n; i++) if(n % i == 0) return false;
    return true;
}

void find_prime(ll l, ll r){
    bool found = false;

    for(ll i = l; i <= r; i++){
        if(is_prime(i)){
            cout << i << " ";
            found = true;
        }
    }
    if(!found) cout << "No prime numbers found in the given range.";
}

int main(){
    ll l, r;
    cin >> l >> r;

    find_prime(l, r);

    return 0;
}