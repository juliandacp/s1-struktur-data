#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll nilai[2][3][4] = {{{85, 90, 78, 92}, {76, 88, 95, 82}, {92, 85, 80, 88}},
                          {{78, 85, 90, 87}, {95, 82, 79, 91}, {70, 88, 85, 90}}};
                          
    for(ll layer = 0; layer < 2; layer++){
        for(ll baris = 0; baris < 3; baris++){
            for(ll kolom = 0; kolom < 4; kolom++) cout << nilai[layer][baris][kolom] << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}