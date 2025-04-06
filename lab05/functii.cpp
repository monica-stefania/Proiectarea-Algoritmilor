#include "header.h"
void insertMinHeap(vector <Node*> &heap, Node* val){
    int child, parent;
    heap.push_back(val);
    child = heap.size()-1;
    parent = (heap.size()-1)/2;
    while(parent >= 0)
    {
        if(heap[child]->info < heap[parent]->info){
            swap(heap[child], heap[parent]);
            child = parent;
            parent = child/2;
        }
        else   
            parent = -1;
    }
}
Node* removeMinHeap(vector <Node*> &heap){
    int child, parent;
    Node* a = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    parent = 0;
    child = 1; 
    while(child <= heap.size())
    {
        if(child + 1 <= heap.size() && heap[child+1]->info < heap[child]->info)
            child=child+1;
        else{
            if(heap[parent]->info > heap[child]->info)
            {
                swap(heap[child], heap[parent]);
                parent = child;
                child = 2*parent;
            }
            else
                child = heap.size() + 1;
        }
    }
    return a;

}
void afisareHeap(vector<Node*> heap){
    for(int i = 0; i < heap.size(); i++)
        cout<<heap[i]->info<<" ";
    /*if(heap != nullptr){
        cout<<heap->info<<" ";
        afisare(heap->left);
        afisare(heap->right);
    }
    else
        cout<<"Heap-ul este gol";
     */
}

void afisare(Node* heap){
    if(heap != nullptr){
        cout<<heap->info<<" ";
        afisare(heap->left);
        afisare(heap->right);
    }
}

vector<Node*> LEP(int a[], int n){
    vector<Node*> B;
    for(int i=0; i < n; i++)
        insertMinHeap(B, new Node(a[i]));
    while(B.size() > 1){
        Node *t1=removeMinHeap(B);
        Node *t2=removeMinHeap(B);
        Node *t=new Node(t1->info + t2->info);
        t->left=t1;
        t->right=t2;
        B.push_back(t);
    }
    return B;
}