#include <bits/stdc++.h>
#define ll long long
using namespace std;

string remove_ball(string s){
    bool change = true;

    while(change){
        change = false;

        string next;
        ll n = s.size();

        for(ll i = 0; i < n;){
            ll j = i;

            while(j < n && s[j] == s[i]) j++;

            ll count = j - i;

            if(count >= 3) change = true;
            else while(count--) next.push_back(s[i]);

            i = j;
        }

        s = next;
    }

    return s;
}

ll dfs(string board, string remains, unordered_map<string, ll> &memo){
    if(board.empty()) return 0;
    if(remains.empty()) return 6;

    string key = board + "|" + remains;

    if(memo.count(key)) return memo[key];

    ll ans = 6;
    ll n_remains = remains.size();

    for(ll i = 0; i < n_remains; i++){
        char ball = remains[i];
        string rem = remains.substr(0, i) + remains.substr(i + 1);
        string candidates;

        if(ball == 'X') candidates = "MKBHP";
        else candidates = string(1, ball);

        for(char c : candidates){
            ll n_board = board.size();

            for(ll pos = 0; pos <= n_board; pos++){
                if(pos > 0 && board[pos - 1] != c && (pos == n_board || board[pos] != c)) continue;

                string next = board;

                next.insert(next.begin() + pos, c);
                next = remove_ball(next);

                ll res = dfs(next, rem, memo);

                if(res != 6) ans = min(ans, res + 1);
            }

            if(ball != 'X') break;
        }

        while(i + 1 < n_remains && remains[i + 1] == remains[i]) i++;
    }

    memo[key] = ans;
    return ans;
}

int main(){
    string L, T;
    cin >> L >> T;

    sort(T.begin(), T.end());

    unordered_map<string, ll> memo;
    ll ans = dfs(L, T, memo);

    if(ans == 6) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
