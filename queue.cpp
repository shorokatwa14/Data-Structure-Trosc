#include <bits/stdc++.h>

using namespace std;
#define size 10
class Queue {
public:
    int queue[size];
    int front = -1 , rear = -1;
    bool is_full(){
        return rear == size-1;
    }
    bool is_empty(){
        return front == rear;
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
                ++rear;
                queue[rear] = val;
            }
        }
    }
    void dequeue(){
        if(is_empty()) return;
        ++front;
    }
    void peek(){
        if(is_empty()) return;
        int x = queue[front];
        cout <<"The front element is " << x;
    }
    void print (){
        for(int i = front;i <=rear;i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
  Queue q;
  q.enqueue(50);
  q.enqueue(10);
  q.enqueue(11);
  q.enqueue(8);
  q.dequeue();
  q.print();
  q.peek();

    return 0;
}
