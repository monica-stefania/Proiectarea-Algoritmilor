#include <iostream>
using namespace std;

void rucsac1(int w[], int p[], int n, int M, double x[]){
    int S[n];
    int C=0;
    for(int i=0; i<n; i++)
        {
            x[i]=0;
            S[i]=0;
        }
    while(C<M){
        //aleg poz cu profitul maxim 
       int poz=-1;
       int max=0;
       for(int i=0; i<n; i++){
            if(max < p[i] && S[i]==0){
                max=p[i];
                poz=i;
            }
       }
       S[poz]=-1;
       if(C + w[poz] <= M)
       {
            x[poz]=1.0;
            C=C+w[poz];
       }
       else
       {
            x[poz]=(double)(M-C) / w[poz];
            C=M;
       }
    }
}

void rucsac2(int w[], int p[], int n, int M, double x[]){
    int S[n];
    int C=0;
    for(int i=0; i<n; i++)
        {
            x[i]=0;
            S[i]=0;
        }
    while(C<M){
        //aleg poz cu profitul maxim 
       int poz=-1;
       double max=0;
       for(int i=0; i<n; i++){
            double raport=(double)p[i]/w[i];
            if(max < raport && S[i]==0){
                max=raport;
                poz=i;
            }
       }
       S[poz]=-1;
       if(C + w[poz] <= M)
       {
            x[poz]=1.0;
            C=C+w[poz];
       }
       else
       {
            x[poz]=(double)(M-C) / w[poz];
            C=M;
       }
    }
}

int main(){
    int n=3;
    int M=10;
    int w[]={6,4,8};
    int p[]={3,4,6};
    double x[3]={0,0,0};
    rucsac2(w,p,n,M,x);
    for(int i=0; i<n; i++){
        cout<<x[i]<<" ";
    }
}