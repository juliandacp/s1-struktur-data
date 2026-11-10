#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, prov = 0;
    ll arah_r[] = {-1, 0, 1, 0};
    ll arah_c[] = {0, -1, 0, 1};
    cin >> n >> m;

    char matrix[n][m];

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(matrix[i][j] == '*') continue;
            else{
                if(!visited[i][j]){
                    prov++;

                    queue<pair<ll, ll>> q;

                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        auto[r, c] = q.front();
                        q.pop();

                        for(ll i = 0; i < 4; i++){
                            ll idx_r = r + arah_r[i];
                            ll idx_c = c + arah_c[i];

                            if(idx_r >= 0 && idx_r < n && idx_c >= 0 && idx_c < m && !visited[idx_r][idx_c] && matrix[idx_r][idx_c] == 'K'){
                                q.push({idx_r, idx_c});
                                visited[idx_r][idx_c] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << prov << endl;

    return 0;
}
