#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll evaluate_postfix(string exp){
    stack<ll> st;

    for(char c : exp){
        if(isdigit(c)) st.push(c - '0');
        else{
            ll val2 = st.top(); st.pop();
            ll val1 = st.top(); st.pop();
            switch(c){
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }

    return st.top();
}

int main(){
    string postfix;

    cout << "Masukkan ekspresi postfix: ";
    cin >> postfix;
    cout << "Hasil evaluasi: " << evaluate_postfix(postfix) << endl;

    return 0;
}