
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


Node* BuildTree(){

    int value;

    cout<<"Enter node value:";
    cin>>value;

    if(value == -1){
        return NULL;
    }

    Node* root = new Node(value);

    cout<<"Enter left child of "<<value<<endl;
    root->left = BuildTree();

    cout<<"Enter right child of "<<value<<endl;
    root->right = BuildTree();

    return root;
}


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

    Node* root = BuildTree();

    if(root == NULL){
        cout<<"Tree is Empty!"<< endl;
        return 0;
    }

    cout<<endl;

    cout<<"Preorder Sequence"<<endl;
    PreOrder(root);

    cout<<endl;

    cout<<"Inorder Sequence"<<endl;
    Inorder(root);

    cout<<endl;

    cout <<"Postorder Sequence"<<endl;
    PostOrder(root);

    return 0;
}
