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

int main() {
    freopen("output.txt","w",stdout);
    Doubly d;
    d.add_head(5);
    d.add_head(3);
    d.add_tail(2);
    d.add_tail(4);
    d.print();
    d.delete_tail();
    d.print();
    return 0;
}
