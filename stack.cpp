#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
class Stack {
public:
    int top= -1;
    int stack[MAX];
    bool is_full(){
        return top == MAX-1;
    }
    bool is_empty(){
      return top == -1;
    }
    void push(int val){
        if(is_full()) return;
        top++;
        stack[top]= val;
    }
    void pop (){
        if(is_empty()) return;
        --top;
    }
    void peek (){
        if (is_empty()) return;
        int x = stack[top];
        cout << "Top element is : " << x << endl;
    }
    int size(){
        return top;
    }
    void print (){
        for(int i = 0;i <=top;i++){
            cout << stack[i] << " ";
        }
        cout << endl;
    }

};

int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.pop();
  s.print();
  s.peek();

    return 0;
}
