#include "header.h"

int main(){
    vector<Node*> heap;
    /*int n = 6;
    int val;
    for(int i =0; i < n; i++)
    {
        cin>>val;
        Node* node= new Node(val);
        insertMinHeap(heap, node);
    }
    afisareHeap(heap);
    */
    int x[5]={10, 15, 20, 6, 7};
    heap=LEP(x,5);
    afisare(heap.back());
}