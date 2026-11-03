
#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  
  Node(int data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
  }
};

void PreOrder(Node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    
    PreOrder(root->left);
    PreOrder(root->right); 
}
void Inorder(Node* root){
    if(root == NULL){

        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}
void PostOrder(Node* root){
    if(root == NULL){
       
        return;
    }

    
  
    PostOrder(root->left);
     
    PostOrder(root->right);
    cout<<root->data<<" ";
    
}
int main(){
    int sum = 0;
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right = new Node(30);

    cout<<"PreOrder Sequence"<<endl;
    PreOrder(root);
    
    cout<<endl;
    cout<<"InOrder Sequence"<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"PostOrdr Sequence"<<endl;
    PostOrder(root);
    cout<<"The sum is:"<<sum<<endl;
    return 0;
}