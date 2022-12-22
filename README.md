# Data Structure- Trosc Workshop
**Main points:**

 1. Time Complexity
 2. Linked List
 3. stack
 4. Queue
 5. Recursion Basics
 6. Tree

# [My Session ](https://docs.google.com/document/d/1EWznMVHHF_scHAn8hwAcV1wB5-_koxPF6MJiwBoNsMI/edit)
## **Linked List**
**Singly Linked List:**
- Classes
~~~ c++
class Node {
public:
    int data;
    Node* next ;
};
class linkedList {
public:
    Node *head =NULL;

};
~~~
____
 - Insert at head
 ~~~ c++
void addNodeAtHead(int num) {
        Node *new_node = new Node;
        new_node->data = num;  // data = 5
        if (head == NULL) {
            head = new_node;
            new_node->next = NULL;
        } else {
            new_node->next = head;
            head = new_node;

        }
    }
~~~
____
 - Insert at tail
 ~~~ c++
void addTail(int num){
        Node *new_node = new Node;
        new_node->data = num;
        if (head == NULL) {
            head = new_node;
            new_node->next = NULL;
        }
        else{
            Node* curr = head;
            while (curr -> next != NULL){
                curr = curr -> next;

            }
            curr -> next = new_node;
            new_node -> next = NULL;
        }
    }
 ~~~
____
 - Insert in nth index
 ~~~ c++
 void addNthPos(int val,int pos){
        Node* new_node = new Node;
        new_node->data = val;
        if (pos == 0){
            new_node -> next = head;
            head = new_node;
        }
        else{
            Node* curr = head;
            for (int i = 0 ;i<pos-1&& curr->next != NULL;i++){
             curr= curr -> next;
            }
            new_node -> next = curr -> next;
            curr -> next = new_node;
        }
    }
 ~~~
____
 - Delete from head
 ~~~ c++
   void deleteHead(){
        if (head == NULL) return;
        else{
            Node* curr = head;
            head = head -> next;
            delete curr;
        }
    }
 ~~~
____
 - Delete from tail 
 ~~~ c++
 void deleteTail(){
        Node* curr = head;
        Node * prev;
        while (curr -> next != NULL){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = NULL;
        delete curr;
    }
 ~~~
____
 - Delete from nth index
 ~~~ c++
 void deleteFromNth(int pos){
        if (head == NULL) return ;
        if (pos == 0){
            Node* curr = head;
            head = head->next;
            delete curr;
        }
        else {
            Node* temp = head;
            // condition to avoid
            for (int i = 0 ;i<pos-1 && temp->next != NULL;i++){
                temp = temp-> next;
            }
            Node* temp2 = temp -> next;
            temp-> next = temp2 -> next;
            delete temp2;

        }

    }
 ~~~
____
 - Search
 ~~~ c++
 bool search(int num){
        Node* curr = head;
        while (curr != NULL){
            if(curr->data ==num) return true;
            curr = curr -> next;
        }
        return false;
    }
 ~~~
____
 - print
 ~~~ c++
   void print() {
        Node *curr = head;
        if (head == NULL) {
            cout << "Linked list is empty";
        }
           else{
               while (curr != NULL) {
                   cout << curr->data << " ";
                   curr = curr->next;
               }
           }
        cout << endl;

    }
 ~~~
____


**Doubly Linked List :**
 - Classes
 ~~~ c++
 class Node {
public:
    int data;
    Node* next ;
    Node* prev;
};
class Doubly {
public:
    Node *head;
    Node* tail;

    Doubly() {
        head = tail = NULL;
    }
 };
 ~~~
 ____
 - Insert at head
~~~ c++
void add_head(int val){
        Node* new_node = new Node;
        new_node -> data= val;
        if (head == NULL){
            head = tail = new_node;
            new_node -> next = NULL;
            new_node -> prev = NULL;
        }
        else{
            new_node -> next = head;
            new_node -> prev = NULL;
            head -> prev = new_node;
            head = new_node;
        }
    }
~~~
_____
 - Insert at tail
 ~~~ c++
 void add_tail(int val){
        Node* new_node = new Node;
        new_node->data = val;
        if (head == NULL) {
            head = tail = new_node;
            new_node -> next = NULL;
            new_node -> prev = NULL;
        } else{
            new_node -> prev = tail;
            new_node -> next = NULL;
            tail -> next = new_node;
            tail = new_node;
        }
    }
~~~
_____
 - Delete from head
~~~ c++
void delete_head(){
        Node* curr = head;
        head = head -> next;
        head -> prev = NULL;
        delete curr;
    }
~~~
_____
 - Delete from tail 
~~~ c++
 void delete_tail(){
        Node* curr = head -> next;
        Node* pre = head;
        while (curr -> next != NULL){
            pre = curr;
            curr = curr -> next;
        }
        pre -> next = NULL;
        delete curr;
    }
~~~
_____
 - print
~~~ c++
void print(){
        Node* curr = head;
        while (curr -> next != head){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << curr -> data <<endl;
    }
~~~
_____

**Circular Linked List :**
 - classes
 ~~~ c++
 class Node {
public:
    int data;
    Node* next ;

};
class Circular {
public:
    Node *head = NULL;
    };
~~~
_____
 - Insert at head
~~~ c++
 void add_head(int val){
        Node* new_node = new Node;
        new_node -> data= val;
        if (head == NULL){
            head = new_node;
            new_node ->next = head;
        }
        else{
            new_node -> next = head;
            Node* curr = head;
            while (curr -> next != head){
                curr = curr -> next;
            }
            curr -> next = new_node;
            head = new_node;
        }
    }
~~~
_____
 - Insert at tail
~~~ c++
 void add_tail(int val){
        Node* new_node = new Node;
        new_node -> data= val;
        if (head == NULL){
            head = new_node;
            new_node ->next = head;
        }
        else{
            Node* curr = head;
            while (curr -> next != head){
                curr = curr -> next;
            }
            curr -> next = new_node;
            new_node->next = head;
        }
    }
~~~
_____
 - Delete from head
~~~ c++
 void delete_head(){
        Node* curr = head;
        while (curr -> next != head){
            curr = curr -> next;
        }
        curr -> next = head -> next;
        curr = head;
        head = head -> next;
        delete curr;
    }

~~~
_____
 - Delete from tail 
~~~ c++
    void delete_tail(){
        Node* curr = head;
        Node* prev = head;
        while (curr -> next != head){
            prev = curr;
            curr = curr -> next;
        }
        prev ->next = head;
        delete curr;
    }
~~~
_____
 - print
~~~ c++
void print(){
        Node* curr = head;
        while (curr -> next != head){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << curr -> data <<endl;
    }
~~~
_____
 
## Stack:
**Basic Operations of Stack:**
- push
- pop
- isEmpty
- isNull
- peek
~~~c++
#define MAX 10
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
~~~
____

## Queue
**Simple and Circular Queue:**
 - Enqueue
 - dequeue
 - isEmpty
 - isNUll
 - peek
~~~ c++
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
~~~
______
## Tree
**Basic Terminologies In Tree**
<br>
<br>
**Properties of a Tree**
<br>
<br>
**Types of Tree data structures**
<br>
<br>
**Basic Operation in Binary Search Tree**
- insertion
- deletion
- print Tree Traversals  (Inorder, Preorder and Postorder)
- Searching

