#include "header.h"

int main(){
    int a[]={2,6,9,3,1,8,4,10};
    int n=8;
    afisare(a,n);
    BatcherSort(a,0,n,1);
    cout<<endl;
    afisare(a,n);
}