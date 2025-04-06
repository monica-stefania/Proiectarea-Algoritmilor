#include "header.h"

int main(){
    int n=3;
    int M=10;

    int w[] = {6,4,8};
    int p[] = {3,4,6};

    double x1[n] = {0};
    rucsac_1(w,p,n,M,x1);

    cout<<"\nPartile fractionare din rucsasul 1: ";
    for(int i=0; i<n; i++){
        cout<<"\ni: "<<i+1<<"->"<<x1[i];
    }

    double x2[n] = {0};
    rucsac_2(w,p,n,M,x2);

    cout<<"\nPartile fractionare din rucsasul 2: ";
    for(int i=0; i<n; i++){
        cout<<"\ni: "<<i+1<<"->"<<x2[i];
    }
}