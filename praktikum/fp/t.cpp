#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point{
    ll x, y;
};

int main(){
    ll n, m;
    cin >> n >> m;

    ll Qx, Qy;
    cin >> Qx >> Qy;

    ll Kx, Ky;
    cin >> Kx >> Ky;

    ll Tx, Ty;
    cin >> Tx >> Ty;

    vector<vector<bool>> obstacle(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;

        obstacle[x][y] = true;
    }

    queue<point> q;

    q.push({Kx, Ky});
    visited[Kx][Ky] = true;

    ll dx[8] = {-1, 1, -1, 0, 0, 1, 1, 1};
    ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while(!q.empty()){
        point cur = q.front();
        q.pop();

        if(cur.x == Tx && cur.y == Ty){
            cout << "Yay" << endl;
            return 0;
        }

        for(ll i = 0; i < 8; i++){
            ll nx = cur.x + dx[i];
            ll ny = cur.y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(visited[nx][ny]) continue;
            if(obstacle[nx][ny]) continue;
            if(nx == Qx || ny == Qy || abs(nx - Qx) == abs(ny - Qy)) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    cout << "Nay" << endl;

    return 0;
}
