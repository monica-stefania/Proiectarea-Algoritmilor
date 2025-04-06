#include "header.h"

/*Merge Sort -> sortare prin interclasare
    a[p...q]-tablou
    alg. consta in divizarea tabloului in 2:
        a[p...m] si a[m+1...q]
        m=[p+q/2]
*/
void mergeSort(int a[], int p, int q){
    int temp[q-p+1];
    if(p < q){
       int m = (p+q)/2;
       //cout<<m<<" ";
       mergeSort(a,p,m);
       mergeSort(a,m+1,q);
       interclasare(a,p,q,m,temp);
       //afisare(a,q+1);
       //afisare(temp,q+1);
       for(int i=p; i<=q; i++)
            a[i]=temp[i-p];
        //afisare(a,q+1);
    }
}

void interclasare(int a[], int p, int q, int m, int temp[]){
    int i=p;
    int j=m+1;
    int k=-1;
    while((i <= m) && (j <= q)){
        k++;
        if(a[i] <= a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
    }
    while(i <= m){
        k++;
        temp[k]=a[i];
        i++;
    }
    while(j <= q){
        k++;
        temp[k]=a[j];
        j++;
    }
}

void afisare(int a[], int n){
    cout<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}

/*quickSOrt -> Sortarea rapida
    a[p...q]=tablou
    problema consta in alegerea unei valori x din a[p...q] si determinarea
    prin interschimbari a unui indice k cu proprietatile:
        i) p<=k<=q si a[k]=x;
        ii) oricare i: p<=i<=k -> a[i]<=a[k];
        iii) oricare j: k<j<=q -> a[k]<=a[j]
        x-pivot
        
        Distingem urmatoarele cazuri:
        1. a[i] ≤ x. Transformarea i ← i+1 pastreaza proprietatea (i).
        2. a[j] ≥ x. Transformarea j ← j−1 pastreaza proprietatea (ii).
        3. a[i] > x >a[j]. Daca se realizeaza interschimbarea a[i] ↔ a[j] si se face i ← i+1 si j ← j−1,
    atunci sunt paastrate ambele predicate (i) si (ii)*/
void quickSort1(int a[], int p, int q){
    int k;
    if(p<q){
        partitioneaza(a,p,q,k);
        //cout<<endl<<k;
        quickSort1(a,p,k-1);
        //afisare(a,q+1);
        quickSort1(a,k+1,q);
        //afisare(a,q+1);
    }
}
void partitioneaza(int a[], int p, int q, int &k){
    int x=a[p];
    int i=p+1;
    int j=q;
    while(i<=j){
        if(a[i] <= x)
            i++;
        if(a[j] >= x)
            j--;
        if(i<j){
            if(a[i]>x && x>a[j])
            {
                swap(a[i],a[j]);
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
        if(k-p > q-k)
        {
            quickSort2(a,k+1,q);
            q=k-1;
        }
        else{
            quickSort2(a,p,k-1);
            p=k+1;
        }
    }
}


/*Batcher Sort -> Sortare bitonica
    Secventa bitona este o secventa de elemente: a[0...n-1] pentru care:
        - exista i a.i a[0...i] este crescator si a[i+1...n-1] este descrescator
        - exista o permutare circulara a.i sa fie satisfacuta conditia anterioara
        */

void BatcherSort(int a[], int i, int d, bool s){
    if(d==2){
        compara_si_schimba(a[i], a[i+1], s);
    }
    else{
        //sortarea crescatoare a unei secvente S de lungime d/2
        BatcherSort(a,i,d/2,0);
        //sortarea descrescatoare a unei secvente S', care urmeza lui S, de lungime d/2
        BatcherSort(a,i+d/2,d/2,1);
        //sortarea secventei bitone SS' de lungime d
        sortare_secventa_bitona(a,i,d,s);
    }
}
void sortare_secventa_bitona(int a[], int i, int d, bool s){
    if(d==2)
        compara_si_schimba(a[i],a[i+1], s);
    else{
        //construirea secventelor bitone S1 si S2 de lungime d/2
        for(int j=0; j<d/2; j++)
            compara_si_schimba(a[i+j], a[i+j+d/2],s);
        //sortarea secventei bitone S1 de lungime d/2
        sortare_secventa_bitona(a,i,d/2,s);
        //sortarea secventei bitone S2 de lungime d/2
        sortare_secventa_bitona(a,i+d/2,d/2,s);
    }
}
void compara_si_schimba(int &a, int &b, bool s){
    if( (s==0 && a>b) || (s==1 && a<b))
        swap(a,b);
}