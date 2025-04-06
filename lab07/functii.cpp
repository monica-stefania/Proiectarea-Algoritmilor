#include "header.h"

void rucsac(int M, int n, int w[], int p[], double x[]){
    vector<vector<Pair>> S(n+1);
    S[0].push_back({0,0}); //initializare rucsac
    T.push_back({obiecte[0].weight, obiecte[0].profit});
    for(int i=1; i<n; i++){
        S[i]=interclasareGrafica(S[i-1], T);
        for(auto pair: S[i]){
            T.push_back({pair.weight + w[i+1], pair.profit + p[i+1]});
        }
    }

    int maxProfit = 0;
    int maxWeight = 0;
    for (auto pair : S[n]) {
        if (pair.weight <= M && pair.profit > maxProfit) {
            maxProfit = pair.profit;
            maxWeight = pair.weight;
        }
    }

    for(int i=n-1; i>=0; i--){
        for(auto pair : S[n]){
            if(maxProfit == pair.profit && maxWeight == pair.weight)
        }
        if()
        {
            x[i+1] = 0; 
        }
        else{
            x[i+1] = 1;

        }
    }
}

vector<Pair> interclasareGrafica(vector<Pair> S, vector<Pair> T){
    int j=0, k=0, profit=0, i=1;
    vector<Pair> Q;
    while(j < S.size() && k < T.size()){
        if(S[j].weight < T[k].weight)
        {
            if(S[j].profit > profit){
                Q.push_back(S[j]);
                profit = S[j].profit;
            }
            j++;
        }
        if(S[j].weight > T[k].weight){
            if(T[k].profit > profit){
                Q.push_back(T[k]);
                profit = T[k].profit;
            }
            k++;
        }
        if(S[j].weight == T[k].profit){
            if(T[k].profit > profit && T[k].profit > S[j].profit){
                Q.push_back(T[k]);
                profit = T[k].profit;
            }
            else if(S[j].profit > profit && S[j].profit > T[k].profit){
                Q.push_back(S[j]);
                profit = S[j].profit;
            }
            k++;
            j++;
        }
    }
    return Q;
}