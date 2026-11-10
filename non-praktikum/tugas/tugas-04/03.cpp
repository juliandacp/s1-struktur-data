#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Queue{
private:
    ll *arr;
    ll front, rear;
    ll kapasitas;

public:
    Queue(ll size){
        kapasitas = size;
        arr = new ll[kapasitas];
        front = 0;
        rear = -1;
    }

    void enqueue(ll x){
        if(rear == kapasitas - 1){
            cout << "Queue penuh\n";
            return;
        }
        arr[++rear] = x;
    }

    void dequeue(){
        if(front > rear){
            cout << "Queue kosong\n";
            return;
        }
        cout << "Elemen yang dihapus: " << arr[front++] << endl;
    }

    void display(){
        if(front > rear){
            cout << "Queue kosong\n";
            return;
        }
        for(ll i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
    
    ~Queue(){
        delete[] arr;
    }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}