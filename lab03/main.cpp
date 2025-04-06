#include "header.h"

int main(){
    int a[500000],n;
    cout<<"\nIntroduceti dimensiunea: ";
    cin>>n;
    citireRandom(a,n);
    //afisare(a,n);
    auto start = chrono::high_resolution_clock::now();
    mergeSort(a,0, n-1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout <<"mergeSort: "<< duration.count() << " milliseconds" << endl;
    //afisare(a,n);

    cout<<"\n";
    citireRandom(a,n);
    //afisare(a,n);
    auto start1 = chrono::high_resolution_clock::now();
    quickSort1(a,0, n-1);
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
    cout <<"quickSort1: "<< duration1.count() << " milliseconds" << endl;
    //afisare(a,n);

    cout<<"\n";
    citireRandom(a,n);
    //afisare(a,n);
    auto start2 = chrono::high_resolution_clock::now();
    quickSort2(a,0, n-1);
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
    cout <<"quickSort2: "<< duration2.count() << " milliseconds" << endl;
    //afisare(a,n);
}