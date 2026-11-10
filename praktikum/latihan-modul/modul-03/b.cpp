#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<pair<ll, ll>, bool> visited;

void bfs(pair<ll, ll> start, vector<string> matrix, ll ukuran){
    queue<pair<ll, ll>> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        ll n = q.front().first;
        ll m = q.front().second;
        q.pop();

        if(n + 1 < ukuran && m + 1 < ukuran && matrix[n + 1][m + 1] == '+' && !visited[{n + 1, m + 1}]){
            q.push({n + 1, m + 1});
            visited[{n + 1, m + 1}] = true;
        }

        if(n - 1 >= 0 && m - 1 >= 0 && matrix[n - 1][m - 1] == '+' && !visited[{n - 1, m - 1}]){
            q.push({n - 1, m - 1});
            visited[{n - 1, m - 1}] = true;
        }

        if(n - 1 >= 0 && m + 1 < ukuran && matrix[n - 1][m + 1] == '+' && !visited[{n - 1, m + 1}]){
            q.push({n - 1, m + 1});
            visited[{n - 1, m + 1}] = true;
        }

        if(n + 1 < ukuran && m - 1 >= 0 && matrix[n + 1][m - 1] == '+' && !visited[{n + 1, m - 1}]){
            q.push({n + 1, m - 1});
            visited[{n + 1, m - 1}] = true;
        }

        if(n + 1 < ukuran && matrix[n + 1][m] == '+' && !visited[{n + 1, m}]){
            q.push({n + 1, m});
            visited[{n + 1, m}] = true;
        }

        if(n - 1 >= 0 && matrix[n - 1][m] == '+' && !visited[{n - 1, m}]){
            q.push({n - 1, m});
            visited[{n - 1, m}] = true;
        }

        if(m + 1 < ukuran && matrix[n][m + 1] == '+' && !visited[{n, m + 1}]){
            q.push({n, m + 1});
            visited[{n, m + 1}] = true;
        }

        if(m - 1 >= 0 && matrix[n][m - 1] == '+' && !visited[{n, m - 1}]){
            q.push({n, m - 1});
            visited[{n, m - 1}] = true;
        }
    }
}

int main(){
    ll N;
    cin >> N;

    vector<string> matrix;

    for(ll i = 0; i < N; i++){
        string s;
        cin >> s;

        matrix.push_back(s);
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            visited[{i, j}] = false;
        }
    }

    ll kelompok = 0;

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(matrix[i][j] == '+' && !visited[{i, j}]){
                kelompok++;
                bfs({i, j}, matrix, N);
            }
        }
    }

    cout << kelompok << endl;

    return 0;
}
