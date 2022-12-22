#include <bits/stdc++.h>
using namespace std;
#define size 10
class CircularQ{
public:
    int queue[size];
    int front = -1 , rear = -1;
    bool is_full(){
        return (rear+1)%size == front;
    }
    bool is_empty(){
        return front ==-1 && rear== -1;
    }
    void enqueue(int val) {
        if (is_full()) return;
        else {
            if (rear == -1 && front == -1){
                ++rear;
                ++front;
                queue[rear] = val;
            }
            else {
                rear = (rear+1)% size;
                queue[rear] = val;
            }
        }
    }
    void dequeue(){
        if(is_empty()) return;
        else if (front == rear){
            front = rear = -1;
        }
        else
            front = (front+1)%size;
    }

    void print (){
        for(int i = front;i <=rear;i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    CircularQ cq;
    cq.enqueue(50);
    cq.enqueue(10);
    cq.enqueue(11);
    cq.enqueue(8);
    cq.dequeue();
    cq.print();
    return 0;
}
