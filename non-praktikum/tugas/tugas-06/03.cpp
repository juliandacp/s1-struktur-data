#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll evaluate_postfix(string exp){
    stack<ll> st;
    stringstream ss(exp);
    string token;

    while(ss >> token){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            ll val2 = st.top(); st.pop();
            ll val1 = st.top(); st.pop();
            
            if(token == "+") st.push(val1 + val2);
            else if(token == "-") st.push(val1 - val2);
            else if(token == "*") st.push(val1 * val2);
            else if(token == "/") st.push(val1 / val2);
        }
        else st.push(stoi(token));
    }

    return st.top();
}

int main(){
    string postfix;

    cout << "Masukkan postfix (pisahkan dengan spasi): ";
    getline(cin, postfix);
    cout << "Hasil: " << evaluate_postfix(postfix) << endl;

    return 0;
}