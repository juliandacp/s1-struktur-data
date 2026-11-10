#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct priority{
    ll P;
    string T;

    bool operator<(const priority& other) const{
        if(P == other.P) return T < other.T;
        return P < other.P;
    }
};

int main(){
    ll N;
    cin >> N;

    priority temp;
    string text = "seru-seruan";
    priority_queue<priority> pq;

    while(N--){
        cin >> temp.P;
        cin.ignore();
        getline(cin, temp.T);

        if(temp.T.find(text) == string::npos) pq.push(temp);
    }

    while(!pq.empty()){
        cout << pq.top().T << endl;
        pq.pop();
    }

    cout << endl;

    return 0;
}
