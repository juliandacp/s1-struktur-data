#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Stack{
private:
    ll *arr;
    ll top;
    ll kapasitas;

public:
    Stack(ll size){
        kapasitas = size;
        arr = new ll[kapasitas];
        top = -1;
    }

    void push(ll x){
        if(top == kapasitas - 1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Elemen yang dihapus: " << arr[top--] << endl;
    }

    void peek(){
        if(top == -1) cout << "Stack kosong\n";
        else cout << "Elemen teratas: " << arr[top] << endl;
    }

    void display(){
        if(top == -1){
            cout << "Stack kosong\n";
            return;
        }

        for(ll i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }

    ~Stack(){
        delete[] arr;
    }
};

int main(){
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();

    return 0;
}