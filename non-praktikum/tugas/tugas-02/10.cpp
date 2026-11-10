#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll var;
    cin >> var;
    ll *ptr = &var;

    cout << "Value of x: " << var << endl;
    cout << "Address of x: " << &var << endl;
    cout << "Value stored in poller ptr: " << ptr << endl;
    cout << "Value polled to by ptr: " << *ptr << endl;

    return 0;
}