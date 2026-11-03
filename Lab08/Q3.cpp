
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

void Inorder(Node* root){

    if(root == NULL){
        return;
    }

    Inorder(root->left);

    cout << root->data << " ";

    Inorder(root->right);
}

int main(){

    Node* root = new Node(35);

    root->left = new Node(18);
    root->right = new Node(55);

    root->left->left = new Node(10);
    root->left->right = new Node(25);

    root->right->left = new Node(45);
    root->right->right = new Node(65);

    cout <<"Inorder Sequence"<< endl;
    Inorder(root);

    return 0;
}
