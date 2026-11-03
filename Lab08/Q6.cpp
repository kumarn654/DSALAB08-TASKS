
#include<iostream>
using namespace std;

class CompleteBinaryTree{
    public:
    int arr[100];
    int size;

    CompleteBinaryTree(){
        size = 0;
    }

    void insert(int value){
        arr[size] = value;
        size++;
    }

    
    void preorder(int index){

        if(index >= size){
            return;
        }

        cout<<arr[index]<<" ";

        preorder(2*index+1);
        preorder(2*index+2);
    }

    
    void inorder(int index){

        if(index >= size){
            return;
        }

        inorder(2*index+1);  // left

        cout<<arr[index]<<" ";

        inorder(2*index+2);  // right
    }

   
    void postorder(int index){

        if(index >= size){
            return;
        }

        postorder(2*index+1);
        postorder(2*index+2);

        cout<<arr[index]<<" ";
    }
};

int main(){

    CompleteBinaryTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);

    cout<<"Preorder Traversal"<<endl;
    tree.preorder(0);

    cout<<endl;

    cout<<"Inorder Traversal"<<endl;
    tree.inorder(0);

    cout<<endl;

    cout<<"Postorder Traversal"<<endl;
    tree.postorder(0);

    return 0;
}
