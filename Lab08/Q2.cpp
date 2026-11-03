
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

    cout << root->data << " ";

    PreOrder(root->left);
    PreOrder(root->right);
}

int main(){

    Node* root = new Node(15);

    root->left = new Node(8);
    root->right = new Node(25);

    root->left->left = new Node(4);
    root->left->right = new Node(12);

    root->right->right = new Node(30);

    cout <<"PreOrder Sequence"<< endl;
    PreOrder(root);

    return 0;
}
