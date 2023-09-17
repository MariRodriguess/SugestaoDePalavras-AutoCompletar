#ifndef HUFFMAN_H 
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <unordered_map>

using namespace std;

struct RecordHuffman {
    string chave;
    int freq;

    RecordHuffman(string chave, int freq) : chave(chave), freq(freq) {}
};

class TreeHuffman {
public:
    RecordHuffman reg;
    TreeHuffman* esq;
    TreeHuffman* dir;
    string huffmanCode; // Campo para armazenar o código de Huffman

    TreeHuffman(RecordHuffman reg) : reg(reg), esq(nullptr), dir(nullptr) {}
};

class CompareNodes {
public:
    bool operator()(TreeHuffman* noEsq, TreeHuffman* noDir) {
        return noEsq->reg.freq > noDir->reg.freq;
    }
};

TreeHuffman* CreateRaizTreeHuffman();
bool TVaziaHuffman(TreeHuffman* t);
void deleteTreeHuffman(TreeHuffman* &t);

TreeHuffman* createHuffmanTree(vector<pair<string, int>> tabFreq);
void printHuffmanTree(TreeHuffman* t);

void preordemHuffman(TreeHuffman* t, ofstream &file);
void centralHuffman(TreeHuffman* t, ofstream &file);
void posordemHuffman(TreeHuffman* t, ofstream &file);
void escreveroutputHuffman(ofstream &file, TreeHuffman* t);

#endif
