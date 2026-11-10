#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, x, y;

ll bfs(vector<vector<ll>> &matrix){
    queue<pair<ll, ll>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    q.push({x, y});
    visited[x][y] = true;

    ll luas = 0;

    while(!q.empty()){
        ll a = q.front().first;
        ll b = q.front().second;
        q.pop();
        luas++;

        if(a + 1 < n && !visited[a + 1][b] && matrix[a + 1][b] <= matrix[a][b]){
            q.push({a + 1, b});
            visited[a + 1][b] = true;
        }

        if(a - 1 >= 0 && !visited[a - 1][b] && matrix[a - 1][b] <= matrix[a][b]){
            q.push({a - 1, b});
            visited[a - 1][b] = true;
        }

        if(b + 1 < m && !visited[a][b + 1] && matrix[a][b + 1] <= matrix[a][b]){
            q.push({a, b + 1});
            visited[a][b + 1] = true;
        }

        if(b - 1 >= 0 && !visited[a][b - 1] && matrix[a][b - 1] <= matrix[a][b]){
            q.push({a, b - 1});
            visited[a][b - 1] = true;
        }
    }

    return luas;
}

int main(){
    cin >> n >> m >> x >> y;

    x--;
    y--;

    vector<vector<ll>> matrix(n, vector<ll>(m));

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++) cin >> matrix[i][j];
    }

    cout << bfs(matrix) << endl;

    return 0;
}
