#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll matrix[3][4] = {{255, 255, 250, 240}, {150, 200, 255, 225}, {0,  50, 150, 200}};

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 4; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}