
#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* left;
    Node* right;

    Node(char data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void PreOrder(Node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    PreOrder(root->left);
    PreOrder(root->right);
}

void Inorder(Node* root){

    if(root == NULL){
        return;
    }


    if(root->left != NULL || root->right != NULL){
        cout << "(";
    }

    Inorder(root->left);

    cout << root->data;

    Inorder(root->right);

    
    if(root->left != NULL || root->right != NULL){
        cout << ")";
    }
}

void PostOrder(Node* root){

    if(root == NULL){
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);

    cout << root->data << " ";
}

int main(){

    // root
    Node* root = new Node('*');

    
    root->left = new Node('+');
    root->left->left = new Node('A');
    root->left->right = new Node('B');

    
    root->right = new Node('-');
    root->right->left = new Node('C');
    root->right->right = new Node('D');

    cout <<"Preorder Sequence"<< endl;
    PreOrder(root);

    cout << endl;

    cout <<"Inorder Sequence"<< endl;
    Inorder(root);

    cout << endl;

    cout <<"Postorder Sequence"<< endl;
    PostOrder(root);

    return 0;
}
