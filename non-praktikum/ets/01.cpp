#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll priority(char op){
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infix_to_postfix(string infix){
    stack<char> st;
    string postfix = "";
    for(ll i = 0; i < infix.length(); i++){
        char c = infix[i];
        
        if(isalnum(c)){
            postfix += c;
            postfix += " ";
        }
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.pop();
        }
        else if(is_operator(c)){
            while(!st.empty() && priority(st.top()) >= priority(c)){
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()){
        postfix += st.top();
        postfix += " ";
        st.pop();
    }
    
    return postfix;
}

int main(){
    string infix = "a+(2*b^3)/(f-g)+d*h";
    cout << "Infix   : " << infix << endl;
    cout << "Postfix : " << infix_to_postfix(infix) << endl;
    
    return 0;
}