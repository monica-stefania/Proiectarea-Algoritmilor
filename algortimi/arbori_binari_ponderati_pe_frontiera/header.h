#pragma once 
#include <iostream>
#include <vector>
using namespace std;

/*  Arbore binaer ponderat pe frontiera = frunzele(frontiera)
contin valori numerice(ponderi), iar restul nodurilor sunt 
rezultatele din combinatia copiiilor(suma lor) 

    Avem niste alori si vrem sa construim un arbore binar ponderat pe frontiera.
Alegem cele mai mici doua noduri si construim un arbore cu ele, unde parintele va si suma copiilor.
Acest pas se repeta pana cand se termina de contruit arborele

10   15   20   6   7
-----------------------------------

    13      10      15      20
6       7
-------------------------------------------

        23            15     20
    10      13
        6       7      

------------------------------------------   

        23                      35
    10      13              15      20
        6       7
        
------------------------------------------        
                 58
        23                  35
    10      13          15      20
        6       7       
*/


/* Pentru implementare se va folos MinHeap(pentru a extrage 
valoril minime care se afla mereu pe prima pozitie) cu 
elemente de tip Node

    Pentru implementarea MinHeapului vom folosi std::vector
*/
//un nod din arborele binar
struct Node{
    int info;
    Node *left;
    Node *right;

    Node(int data):info(data), left(nullptr), right(nullptr) {}
}; 

void inserareHeap(vector<Node*> &heap, Node* val);
Node* stergereHeap(vector<Node*> &heap);
void afisareHeap(vector<Node*> heap);

vector<Node*> LEP(int a[], int n);
void afisareArbore(Node* r);