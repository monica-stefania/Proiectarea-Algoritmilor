#pragma once 
#include <iostream>
#include <vector>
using namespace std;

struct Pair{
    int weight;
    int profit;
};

vector<Pair> T;
vector<Pair> obiecte;

void rucsac(int M, int n, int w[], int p[], double x[]);
vector<Pair> interclasareGrafica(vector<Pair> S, vector<Pair> T);