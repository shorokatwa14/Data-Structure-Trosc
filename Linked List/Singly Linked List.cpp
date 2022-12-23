#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next ;
};
class linkedList {
public:
    Node *head =NULL;



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
    bool search(int num){
        Node* curr = head;
        while (curr != NULL){
            if(curr->data ==num) return true;
            curr = curr -> next;
        }
        return false;
    }
    void delete_head() {
        if (head == NULL) return;
        else {
            Node* curr = head;
            head = head->next;
            delete curr;
        }
    }

    void deleteHead(){
        if (head == NULL) return;
        else{
            Node* curr = head;
            head = head -> next;
            delete curr;
        }
    }
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
    void delete_tail(){
        Node* curr = head -> next;
        Node* prev= head;
        while (curr ->next != NULL){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = NULL;
        delete curr;
    }
    void reverse()
    {

        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {

            next = current->next;

            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void deleteFromNth(int pos){
        if (head == NULL) return ;
        if (pos == 0){
            Node* curr = head;
            head = head -> next;
            delete curr;
        }
        else {
            Node* curr = head;
            for (int i = 0 ;i<pos-1&& curr->next != NULL;i++){
                curr = curr -> next;
            }
            Node* temp  = curr -> next;
            curr -> next = temp -> next ;
            delete temp;
            }

    }

};


int main() {

    linkedList list ;
    list.addNodeAtHead(5);
    list.addNodeAtHead(10);
    list.addNodeAtHead(15);
    //list.print();
    list.addTail(18);
    list.addTail(20);
   list.print();
    list.addNthPos(12,10);
    list.deleteFromNth(3);
    list.print();


    return 0;
}
