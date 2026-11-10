#include <bits/stdc++.h>
#define ll long long
#define MAX 5
using namespace std;

class Queue{
private:
    ll arr[MAX];
    ll frll, rear;

public:
    Queue(){
        frll = -1;
        rear = -1;
    }

    bool is_empty(){
        return (frll == -1);
    }

    bool is_full(){
        return (rear == MAX - 1);
    }

    void enqueue(ll x){
        if(is_full()){
            cout << "Queue Overflow\n";
            return;
        }
        if(is_empty()) frll = 0;

        arr[++rear] = x;

        cout << "Elemen " << x << " masuk ke queue\n";
    }

    void dequeue(){
        if(is_empty()){
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Elemen " << arr[frll] << " keluar dari queue\n";

        if(frll == rear) frll = rear = -1;
        else frll++;
    }

    void display(){
        if(is_empty()){
            cout << "Queue kosong\n";
            return;
        }

        cout << "Isi Queue: ";

        for(ll i = frll; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}