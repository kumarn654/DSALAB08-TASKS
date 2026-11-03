
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MinHeap{
    public:
    vector<int> heap;

    void insert(int urgency){

        heap.push_back(urgency);

        heapifyUp(heap.size()-1);
    }

  
    void heapifyUp(int index){

        while(index > 0){

            int parent = (index-1)/2;

            if(heap[parent] <= heap[index]){
                break;
            }

            swap(heap[parent],heap[index]);

            index = parent;
        }
    }

  
    int extractMin(){

        if(heap.empty()){
            return -1;
        }

        int minValue = heap[0];

        heap[0] = heap.back();

        heap.pop_back();

        if(!heap.empty()){
            heapifyDown(0);
        }

        return minValue;
    }

   
    void heapifyDown(int index){

        int smallest = index;

        int left = 2*index+1;
        int right = 2*index+2;

        if(left < heap.size() && heap[left] < heap[smallest]){
            smallest = left;
        }

        if(right < heap.size() && heap[right] < heap[smallest]){
            smallest = right;
        }

        if(smallest != index){

            swap(heap[index],heap[smallest]);

            heapifyDown(smallest);
        }
    }

    
    void display(){

        for(int i=0;i<heap.size();i++){
            cout<<heap[i]<<" ";
        }

        cout<<endl;
    }
};

int main(){

    MinHeap h;

    h.insert(35);
    h.insert(12);
    h.insert(25);
    h.insert(8);
    h.insert(40);
    h.insert(5);

    cout<<"Min Heap:"<<endl;
    h.display();

    cout<<"Extracted Minimum: "<<h.extractMin()<<endl;

    cout<<"Updated Min Heap:"<<endl;
    h.display();

    return 0;
}
