#include "header.h"

void citireRandom(int a[], int n){
    for(int i=0; i<n; i++){
        a[i]=rand() %n;
    }
}
void afisare(int a[], int n){
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
}
void mergeSort(int a[], int p, int q){
    int m,temp[q-p+2];
    if(p<q){
        m=(p+q)/2;
        mergeSort(a,p,m);
        mergeSort(a, m+1, q);
        interclasare(a, p, q, m, temp);
        for(int i=p; i<= q; i++)
            a[i]=temp[i-p];
    }
}
void interclasare(int a[], int p, int q, int m, int temp[]){
    int i=p;
    int j=m+1;
    int k=-1;
    while(i<=m && j<=q){
        k=k+1;
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i=i+1;
        }
        else{
            temp[k]=a[j];
            j=j+1;
        }

    }
    while(i<=m){
        k=k+1;
        temp[k]=a[i];
        i=i+1;
    }
    while(j<=q){
        k=k+1;
        temp[k]=a[j];
        j=j+1;
    }
}

void quickSort1(int a[], int p, int q){
    int k;
    if(p<q){
        partitioneaza(a,p,q,k);
        quickSort1(a,p,k-1);
        quickSort1(a,k+1,q);
    }
}
void partitioneaza(int a[], int p, int q, int &k){
    int x=a[p];
    int i=p+1;
    int j=q;
    while(i<=j){
        if(a[i]<=x)
            i++;
        if(a[j]>=x)
            j--;
        if(i<j){
            if(a[i]>x && x>a[j])
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
    }
    k=i-1;
    a[p]=a[k];
    a[k]=x;
}

void quickSort2(int a[], int p, int q){
    int k;
    while(p<q){
        partitioneaza(a,p,q,k);
        if(k-p>q-k){
            quickSort2(a,k+1,q);
            q=k-1;
        }
        else{
            quickSort2(a,p,k-1);
            p=k+1;
        }
    }
}   