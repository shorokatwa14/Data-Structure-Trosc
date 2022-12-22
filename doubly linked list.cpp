#include <iostream>
using namespace std;
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
    void delete_head(){
        Node* curr = head;
        head = head -> next;
        head -> prev = NULL;
        delete curr;
    }
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

};


class node{
public:
        int data;
        node *next ;
};
class circular{
public:
    node* head = NULL;
    void add_head(int val){
        node* new_node = new node;
        new_node -> data = val;
        if (head == NULL){
            head = new_node;
            new_node -> next = head;
        }
        else {
            new_node -> next = head;
            node* curr = head;
            while (curr -> next != head){
                curr = curr -> next;
            }
            curr->next = new_node;
            head = new_node;
        }
    }
    void add_tail(int val){
        node* new_node = new node;
        new_node -> data = val;
        if (head == NULL){
            head = new_node;
            new_node -> next = head;
        }
        else{
            node* curr = head;
            while (curr -> next != head){
                curr = curr -> next;
            }
            curr -> next = new_node;
            new_node -> next = head;
        }
    }
    void print (){
        node* curr =head;
        while (curr -> next != head){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << curr -> data << endl;
    }

void delete_head(){
       node* curr = head;
       node* prev = head;
       while (curr -> next != head){
           curr = curr -> next;
       }
       curr -> next = head -> next;
       head = head -> next;
       delete prev;
    }
  void delete_tail(){
        node* curr = head;
        node* prev;
      while (curr -> next != head){
          prev = curr;
          curr = curr -> next;
      }
      prev -> next = head;
      delete curr;
    }


};
int main() {
    freopen("output.txt","w",stdout);
    circular c;
    c.add_head(5);
    c.add_head(3);
    c.add_tail(2);
    c.add_tail(4);
    c.print();
    c.delete_tail();
    c.print();
    return 0;
}
