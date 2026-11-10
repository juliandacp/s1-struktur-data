#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n + 1), dp(n + 1);

        for(ll i = 1; i <= n; i++) cin >> a[i];

        deque<ll> dq;

        dp[1] = a[1];
        dq.push_back(1);

        for(ll i = 2; i <= n; i++){
            while(!dq.empty() && dq.front() < i - k) dq.pop_front();

            dp[i] = a[i] + dp[dq.front()];

            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();

            dq.push_back(i);
        }

        cout << dp[n] << endl;
    }

    return 0;
}
