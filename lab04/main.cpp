#include "header.h"

int main(){
    int a[150000],b[150000],c[150000],d,n;
    cout<<"\nIntroduceti dimensiunea: ";
    cin>>d;
    n=pow(2,d);
    for(int i=0; i<n; i++)
        a[i]=i;
    //cout<<"\nVectorul inainte de sortare: ";
    //afisare(a,n);
    //0 pentru crescator 
    //1 pentru descrescator
    auto start = chrono::high_resolution_clock::now();
    BatcherSort(a,0,n,0);
    //cout<<"\nVectorul dupa sortare : ";
    //afisare(a,n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout <<"\nVector crescator: "<<duration.count() << " milliseconds" << endl;

    cout<<endl;
    for(int i=0; i<n; i++)
        b[i]=n-i;
    //cout<<"\nVectorul inainte de sortare: ";
    //afisare(a,n);
    auto start1 = chrono::high_resolution_clock::now();
    BatcherSort(b,0,n,0);
    //cout<<"\nVectorul dupa sortare : ";
    //afisare(a,n);
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
    cout << "\nVector descrescator: "<<duration1.count() << " milliseconds" << endl;

    cout<<endl;
    citireRandom(c,n);
    //cout<<"\nVectorul inainte de sortare: ";
    //afisare(a,n);
    auto start2 = chrono::high_resolution_clock::now();
    BatcherSort(c,0,n,0);
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
    cout <<"\nVector random: "<< duration2.count() << " milliseconds" << endl;
}