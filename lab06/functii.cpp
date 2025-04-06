#include "header.h"
void rucsac_1(int w[], int p[], int nr, int M, double x[]){
    int S[nr];
    int C = 0;
    int n=nr;
    for(int i=0; i<n; i++){
        x[i] = 0;
        S[i] = 0;
    }
    while(C < M){
        int max = p[0];
        int poz = -1;
        for(int i=1; i<n;i++){
            if(max<p[i] && S[i] == 0)
            {
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
        else{
            x[poz]=(double)(M-C) / w[poz];
            C=M;
        }
    }
}


void rucsac_2( int w[], int p[], int n, int M, double x[])
{

    int S[n];
    int C=0;

    for ( int i=0; i<n; i++)
    {
        x[i]= 0;
        S[i] = i;
     
    }

    while (C<M)
    {
        int poz= -1;
        double max= -1.0; // raportul p/w maxim 

        for (int i = 0; i < n; i++) 
        {
            double raport= (double)p[i] / w[i]; //pt fiecare element
          
            if ( S[i]!=-1 && raport > max ) 
            {  
                max = raport;
             
                poz = i; 
            }
        }
       
        S[poz]= -1;

        if ( C + w[poz] <= M)
        {
            x[poz] =1;
            C= C+ w[poz];
        }
        else
        {
            x[poz]= (double)( M - C)/ w[poz];
            C=M;
        }

    }

}