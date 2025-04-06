#include "header.h"

void BatcherSort(int a[], int i, int d, bool s){
    if(d==2)
        compara_si_schimba(a[i], a[i+1], s);
    else{
        BatcherSort(a,i,d/2,0);
        BatcherSort(a,i+d/2,d/2,1);
        sortare_secventa_bitona(a,i,d,s);
    }
}
void sortare_secventa_bitona(int a[], int i, int d, bool s){
    if(d==2){
        compara_si_schimba(a[i], a[i+1],s);
    }
    else{
        for(int j=0; j<d/2; j++)
            compara_si_schimba(a[i+j], a[i+j+d/2],s);
        sortare_secventa_bitona(a,i,d/2,s);
        sortare_secventa_bitona(a,i+d/2,d/2,s);
    }
}
void compara_si_schimba(int &a, int &b, bool s){
    if((s==1 && a<b) || (s==0 && a>b))
        swap(a,b);
}
void citireRandom(int a[], int n){
    for(int i=0; i<n; i++)
        a[i]=rand() %n;
}
void afisare(int a[], int n){
    for(int i=0; i<n; i++)
        cout<<a[i]<<" "; 
}