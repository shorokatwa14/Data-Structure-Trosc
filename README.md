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
*###Classes
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
 - Insert at head
 - Insert at tail
 - Delete from head
 - Delete from tail 
 - print

**Circular Linked List :**
 - Insert at head
 - Insert at tail
 - Delete from head
 - Delete from tail 
 - print
 
## Stack:
**Basic Operations of Stack:**
- push
- pop
- isEmpty
- isNull
- peek

## Queue
**Simple and Circular Queue:**
 - Enqueue
 - dequeue
 - isEmpty
 - isNUll
 - peek
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

