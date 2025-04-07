#include "header.h"

int main(){
    int n=3;
    int M=10;
    int w[] ={3,5,6};
    int p[]={10,30,20};
    double x[3]={0};

    for (int i = 0; i < n; i++) {
        obiecte.push_back({w[i], p[i]});
    }
    rucsac(M, n, w, p, x);
    cout << "Obiectele selectate:\n";
    for (int i = 0; i < n; i++) {
        cout << "Obiect " << i << ": " << x[i]<<endl;
    }
}