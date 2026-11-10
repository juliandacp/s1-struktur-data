#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll rows, columns, n, num = 1;
    cin >> n;

    for(ll rows = 0; rows <= n; rows++){
        for(ll columns = 0; columns < rows; columns++) cout << num++ << " ";
        cout << endl;
    }

    return 0;
}