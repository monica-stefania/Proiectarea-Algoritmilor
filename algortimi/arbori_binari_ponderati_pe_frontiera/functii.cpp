#include "header.h"

void inserareHeap(vector<Node*> &heap, Node* val){
    heap.push_back(val);
    int child=heap.size()-1;
    int parent=(heap.size()-1)/2;
    while(parent >= 0){
        if(heap[child]->info < heap[parent]->info)
        {
            swap(heap[child], heap[parent]);
            child=parent;
            parent=child/2;
        }
        else
            parent=-1;
    }
}
Node* stergereHeap(vector<Node*> &heap){
    Node* val = heap[0];
    heap[0]=heap.back();
    heap.pop_back();
    int parent=0;
    int child=1;
    while(child <= heap.size()){
        if(child + 1 <= heap.size() && heap[child+1]->info < heap[child]->info)
            child = child+1;
        else{
            if(heap[parent]->info > heap[child]->info){
                swap(heap[child], heap[parent]);
                parent=child;
                child=2*parent;
            }
            else    
                child=heap.size()+1;
        }
    }
    return val;
}
void afisareHeap(vector<Node*> heap){
    for(int i=0; i<heap.size(); i++)
        cout<<heap[i]->info<<" ";
}

vector<Node*> LEP(int a[], int n){
    vector<Node*> B;
    for(int i=0; i<n;i++)
        inserareHeap(B, new Node(a[i]));
    while(B.size() > 1){
        Node* t1=stergereHeap(B);
        Node* t2=stergereHeap(B);
        Node* t = new Node(t1->info + t2->info);
        t->left=t1;
        t->right=t2;
        B.push_back(t);
    }
    return B;
}

void afisareArbore(Node* r){
    if(r!=nullptr){
        cout<<r->info<<" ";
        afisareArbore(r->left);
        afisareArbore(r->right);
    }
}