#include "tree.hpp"
#include "fila.hpp"

using namespace std;

TreeBasic* CreateBasicTree() {
    return nullptr;
}

bool TVaziaBasicTree(TreeBasic* t) {
    return t == nullptr;
}

void deleteBasicTree(TreeBasic *&t){

    if (t == nullptr)
        return;

    deleteBasicTree(t->esq);
    deleteBasicTree(t->dir);

    delete t;
    t = nullptr; 
}

TreeBasic* insertBasicTree(TreeBasic* t, RecordBasic r) {
    if (TVaziaBasicTree(t)) {
        t = new TreeBasic;
        t->esq = NULL; 
        t->dir = NULL; 
        t->reg = r;
    } else {
        if (r.valor <= t->reg.valor) {
            t->esq = insertBasicTree(t->esq, r);
        } else if (r.valor > t->reg.valor) {
            t->dir = insertBasicTree(t->dir, r);
        }
    }
    return t;
}

void preordemBasicTree(TreeBasic* t, ofstream &file) {
    if (t != nullptr) {
        //std::cout << t->reg.chave << " ";
        file << t->reg.chave << "-" << t->reg.valor << " , ";
        //file << t->reg.valor << " , ";
        preordemBasicTree(t->esq, file); 
        preordemBasicTree(t->dir, file); 
    }
}

void centralBasicTree(TreeBasic* t, ofstream &file) {
    if (t != nullptr) {
        centralBasicTree(t->esq, file); 
        //file << t->reg.chave << " ";
        file << t->reg.chave << "-" << t->reg.valor << " , ";
        //file << t->reg.valor << " , ";
        centralBasicTree(t->dir, file); 
    }
}

void posordemBasicTree(TreeBasic* t, ofstream &file) {
    if (t != nullptr) {
        posordemBasicTree(t->esq, file); 
        posordemBasicTree(t->dir, file); 
        //file << t->reg.valor << " , ";
        file << t->reg.chave << "-" << t->reg.valor << " , ";
    }
}

void escreveroutputBasicTree(std::ofstream &file, TreeBasic* t){
    file << "==[ÁRVORE BINÁRIA]==\n\n";

    file << "Método Central: { ";
    centralBasicTree(t, file);
    file << "}\n\n";

    /*
    file << "Método Pré Ordem: { ";
    preordemBasicTree(t, file);
    file << "}\n\n";

    file << "Método Pós Ordem: { ";
    posordemBasicTree(t, file);
    file << "}\n\n";

    file << "Método Largura: { ";
    widthPathBasicTree(t, file);
    file << "}\n\n";
    */
}