
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Request{
    int id;
    int priority;
};

class PriorityQueue{
    public:
    vector<Request> heap;

    bool compare(Request a,Request b){
        if(a.priority == b.priority){
            return a.id < b.id;
        }

        return a.priority < b.priority;
    }

    void insert(int id,int priority){

        Request r;
        r.id = id;
        r.priority = priority;

        heap.push_back(r);

        heapifyUp(heap.size()-1);
    }

    void heapifyUp(int index){

        while(index > 0){

            int parent = (index-1)/2;

            if(compare(heap[parent],heap[index])){
                break;
            }

            swap(heap[parent],heap[index]);

            index = parent;
        }
    }

    Request extractMin(){

        Request r = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if(heap.size() > 0){
            heapifyDown(0);
        }

        return r;
    }

    void heapifyDown(int index){

        int smallest = index;

        int left = 2*index+1;
        int right = 2*index+2;

        if(left < heap.size() && compare(heap[left],heap[smallest])){
            smallest = left;
        }

        if(right < heap.size() && compare(heap[right],heap[smallest])){
            smallest = right;
        }

        if(smallest != index){

            swap(heap[index],heap[smallest]);

            heapifyDown(smallest);
        }
    }

    Request getNext(){
        return heap[0];
    }

    void display(){

        for(int i=0;i<heap.size();i++){
            cout<<"ID: "<<heap[i].id<<" Priority: "<<heap[i].priority<<endl;
        }
    }
};

int main(){

    PriorityQueue pq;

    pq.insert(101,3);
    pq.insert(102,1);
    pq.insert(103,2);
    pq.insert(104,1);
    pq.insert(105,4);
    pq.insert(106,2);

    cout<<"Priority Queue:"<<endl;
    pq.display();

    Request r = pq.extractMin();

    cout<<endl<<"Removed Request!"<<endl;
    cout<<"id:"<<r.id<<" Perority: "<<r.priority<<endl;

    Request next = pq.getNext();

    cout<<endl<<"Most Urgent Request!"<<endl;
    cout<<"id: "<<next.id<<" priority: "<<next.priority<<endl;

    cout<<endl<<"Update Queue!"<<endl;
    pq.display();

    return 0;
}
