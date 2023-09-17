#ifndef TREE_H 
#define TREE_H

#include <iostream>
#include <string>
#include <queue> 
#include <fstream>

using namespace std;

typedef struct RecordBasic RecordBasic;
typedef struct TreeBasic TreeBasic;

struct RecordBasic {
    string chave;
    int valor;
};

struct TreeBasic {
    RecordBasic reg;
    TreeBasic* esq;
    TreeBasic* dir;
};

TreeBasic* CreateBasicTree();
bool TVaziaBasicTree(TreeBasic* t);

TreeBasic* insertBasicTree(TreeBasic* t, RecordBasic r);
//void inserirTree(vector<pair<string, int>> copiaHeap, tree* arvore);
//void insertTree(Tree*& t, Record r);
void deleteBasicTree(TreeBasic *&t);

void preordemBasicTree(TreeBasic* t, ofstream &file);
void centralBasicTree(TreeBasic* t, ofstream &file);
void posordemBasicTree(TreeBasic* t, ofstream &file);
void widthPathBasicTree(TreeBasic* t, ofstream &file);

void escreveroutputBasicTree(ofstream &file, TreeBasic* t);

#endif
