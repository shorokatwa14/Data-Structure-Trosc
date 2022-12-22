#include <iostream>
using namespace std;

class BST{
public:
    int data;
    BST* right,*left;
public:
    BST(){
        data = 0;
        right = left = NULL;
    }
    BST(int val){
        data = val;
        right = left = NULL;
    }
    BST* insert (BST* root ,int num){
       if (root == NULL) return new BST(num);
       else if (num > root -> data ){
           root -> right = insert(root -> right , num);
       }
       else if (num <= root -> data ){
            root -> left  = insert(root -> left , num);
        }
       return root ;
    }

    BST* findMax(BST* root){
        while (root -> right != NULL){
            root = root -> right;
        }
        return root;
    }
    BST* findMin(BST* root){
        while (root -> left != NULL){
            root = root -> left;
        }
        return root;
    }
    BST* search(BST* root , int num){
        if(!root) return NULL;
        else if (num == root -> data) return root;
        else if (num > root -> data) {
            search(root -> right ,num);
        }
        else if (num > root -> data) {
            search(root -> left ,num);
        }
    }

    void preorder(BST* root){   //  root left right
        if (!root) return;
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
    void inorder(BST* root){   //  left root  right
        if (!root) return;  
        preorder(root -> left);
        cout << root -> data << " ";
        preorder(root -> right);
    }
    void postorder (BST* root){   //  left right root
        if (!root) return;
        preorder(root -> left);
        preorder(root -> right);
        cout << root -> data << " ";
    }

    BST* remove (BST* root,int val){
        if(!root) return NULL;
       else if (val > root -> data){
            root -> right = remove(root -> right , val);
        }
        else if (val > root -> data){
            root -> left = remove(root -> left , val);
        }
        else{
            if(root -> right == NULL){
                BST* temp = root -> left ;
                free(root);
                return temp ;
            }
           else if(root -> left == NULL){
                BST* temp = root -> right ;
                free(root);
                return temp ;
            }
           else {
                BST *temp = findMin(root->right);
                root->data = temp->data;
                free(temp);
            }
        }
    }

};


int main() {
  BST bs,*root = NULL;
  root = bs.insert(root,5);
  bs.insert(root,10);
  bs.insert(root,6);
  bs.insert(root,20);
  bs.insert(root,3);
  bs.preorder(root);
  cout << endl;
  bs.inorder(root);
  cout << endl;
  bs.postorder(root);
  cout << endl;
 cout << (bs.search(root,50 )?"Found":"Not found") << endl;
 bs.remove(root,20);
 bs.inorder(root);
 cout <<endl<< bs.findMax(root) -> data << endl;
    return 0;
}

