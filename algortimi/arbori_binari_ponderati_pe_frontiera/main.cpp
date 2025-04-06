#include "header.h"

int main(){
    vector<Node*> heap;
    /*int n;
    cin>>n;
    while(n){
        Node* node=new Node(n);
        inserareHeap(heap, node);
        cin>>n;
    }
    afisareHeap(heap);
    Node* val = stergereHeap(heap);
    cout<<endl;
    afisareHeap(heap);
    */
   int a[5]={10,15,20,6,7};
   int n=5;
   heap=LEP(a,n);
   afisareArbore(heap.back());
}