#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll arr[] = {2, 4, 6, 8};

    for(ll i = 0; i < 4; i++){
        cout << arr[i] << endl;
        cout << "Id: " << &arr[i] << endl;
    }
    
    return 0;
}