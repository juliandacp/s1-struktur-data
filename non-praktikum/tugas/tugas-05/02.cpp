#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    ll data;
    Node* next;
};

class Stack{
private:
    Node* top;

public:
    Stack(){
        top = NULL;
    }

    void push(ll x){
        Node* newNode = new Node();

        newNode->data = x;
        newNode->next = top;
        top = newNode;

        cout << x << " ditambahkan ke stack\n";
    }

    void pop(){
        if(top == NULL){
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;

        cout << temp->data << " dihapus dari stack\n";

        top = top->next;
        delete temp;
    }

    void peek(){
        if(top == NULL) cout << "Stack kosong\n";
        else cout << "Elemen teratas: " << top->data << endl;
    }

    bool is_empty(){
        return(top == NULL);
    }
};

ll main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();
    s.pop();
    s.peek();
    
    return 0;
}