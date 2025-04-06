#pragma once 
#include <iostream>
using namespace std;

void mergeSort(int a[], int p, int q);
void interclasare(int a[], int p, int q, int m, int temp[]);
void afisare(int a[], int n);

void quickSort1(int a[], int p, int q);
void partitioneaza(int a[], int p, int q, int &k);

void quickSort2(int a[], int p, int q);

void BatcherSort(int a[], int i, int d, bool s);
void sortare_secventa_bitona(int a[], int i, int d, bool s);
void compara_si_schimba(int &a, int &b, bool s);