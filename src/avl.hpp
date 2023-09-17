#ifndef AVL_H 
#define AVL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct RecordAvl RecordAvl;
typedef struct TreeAvl TreeAvl;

struct RecordAvl {
    string chave;
    int valor;
};

struct TreeAvl {
    RecordAvl reg;
    TreeAvl* esq, * dir;
    int weight;
};

TreeAvl* CreateTreeAvl();
void deleteTreeAVL(TreeAvl*& t);

void insertTreeAvl(TreeAvl** t, RecordAvl r);
void pesquisaAvl(TreeAvl** t, TreeAvl** aux, RecordAvl r);

void removeTreeAvl(TreeAvl** t, TreeAvl** f, RecordAvl r);
void antecessorAvl(TreeAvl** t, TreeAvl* aux);
void rebalanceTreeAvl(TreeAvl** t);

void preordemAvl(TreeAvl* t, ofstream &file);
void centralAvl(TreeAvl* t, ofstream &file);
void posordemAvl(TreeAvl* t, ofstream &file);

int getWeightAvl(TreeAvl** t);
int getMaxWeightAvl(int esq, int dir);

void rotacaoSimplesDireitaAvl(TreeAvl** t);
void rotacaoSimplesEsquerdaAvl(TreeAvl** t);
void rotacaoDuplaDireitaAvl(TreeAvl** t);
void rotacaoDuplaEsquerdaAvl(TreeAvl** t);

void escreveroutputAvl(std::ofstream &file, TreeAvl* t);

#endif