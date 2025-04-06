#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int info;
    Node* left;
    Node* right;
    
    Node(int data) : info(data), left(nullptr), right(nullptr) {}
};

void insertMinHeap(vector <Node*> &heap, Node* val);
Node* removeMinHeap(vector <Node*> &heap);
void afisareHeap(vector<Node*> heap);
void afisare(Node* heap);
vector<Node*> LEP(int a[], int n);