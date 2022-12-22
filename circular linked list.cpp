#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next ;

};
class Circular {
public:
    Node *head = NULL;

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

    void print(){
        Node* curr = head;
        while (curr -> next != head){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << curr -> data <<endl;
    }

};
int main() {
    freopen("output.txt","w",stdout);
    Circular c;
    c.add_head(5);
    c.add_head(10);
    c.add_head(15);
    c.print();
    c.add_tail(50);
    c.add_tail(30);
    c.print();
    c.delete_head();
    c.print();
    c.delete_tail();
    c.print();

    return 0;
}
