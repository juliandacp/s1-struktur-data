#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX = 10;
string antrean[MAX];
ll front = -1, rear = -1;

void enqueue(string data){
    if(rear == MAX - 1){
        cout << "Antrean penuh" << endl;
        return;
    }
    if(front == -1) front = 0;
    rear++;
    antrean[rear] = data;
    cout << data << " masuk antrean" << endl;
}

void dequeue(){
    if(front == -1 || front > rear){
        cout << "Antrean kosong" << endl;
        return;
    }
    cout << antrean[front] << " sedang dilayani" << endl;
    front++;
    if(front > rear) front = rear = -1;
}

void display(){
    if(front == -1 || front > rear){
        cout << "Antrean kosong" << endl;
        return;
    }
    cout << "Isi antrean: ";
    for(ll i = front; i <= rear; i++) cout << antrean[i] << " ";
    cout << endl;
}

int main(){
    enqueue("A");
    enqueue("B");
    enqueue("C");

    display();
    cout << endl;

    dequeue();
    display();
    cout << endl;

    enqueue("D");

    display();
    cout << endl;

    return 0;
}