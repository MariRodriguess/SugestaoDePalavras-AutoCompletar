#include "avl.hpp"

TreeAvl* CreateTreeAvl() {
    return nullptr;
}

void deleteTreeAVL(TreeAvl*& t) {
    if (t == nullptr)
        return;

    deleteTreeAVL(t->esq);
    deleteTreeAVL(t->dir);

    delete t;
    t = nullptr;
}

void insertTreeAvl(TreeAvl** t, RecordAvl r) {
    if (*t == nullptr) {
        *t = new TreeAvl;
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->weight = 0;
        (*t)->reg = r;
    } else {
        if (r.valor <= (*t)->reg.valor) {
            insertTreeAvl(&(*t)->esq, r);
            if ((getWeightAvl(&(*t)->esq) - getWeightAvl(&(*t)->dir)) == 2) {
                if (r.valor <= (*t)->esq->reg.valor){
                    rotacaoSimplesDireitaAvl(t);
                }    
                else{
                    rotacaoDuplaDireitaAvl(t);
                }    
            }
        }else if (r.valor > (*t)->reg.valor) {
            insertTreeAvl(&(*t)->dir, r);
            if ((getWeightAvl(&(*t)->dir) - getWeightAvl(&(*t)->esq)) == 2) {
                if (r.valor > (*t)->dir->reg.valor){
                    rotacaoSimplesEsquerdaAvl(t);
                }    
                else{
                    rotacaoDuplaEsquerdaAvl(t);
                }    
            }
        }
    }

    (*t)->weight = getMaxWeightAvl(getWeightAvl(&(*t)->esq), getWeightAvl(&(*t)->dir)) + 1;
}

void pesquisaAvl(TreeAvl** t, TreeAvl** aux, RecordAvl r) {
    if (*t == nullptr) {
        std::cout << "[ERROR]: Node not found!";
        return;
    }

    if ((*t)->reg.valor > r.valor) {
        pesquisaAvl(&(*t)->esq, aux, r);
        return;
    }
    if ((*t)->reg.valor < r.valor) {
        pesquisaAvl(&(*t)->dir, aux, r);
        return;
    }

    *aux = *t;
}

void antecessorAvl(TreeAvl** t, TreeAvl* aux) {
    if ((*t)->dir != nullptr) {
        antecessorAvl(&(*t)->dir, aux);
        return;
    }

    aux->reg = (*t)->reg;
    aux = *t;
    *t = (*t)->esq;
    delete aux;
}

void rebalanceTreeAvl(TreeAvl** t) {
    int balance;
    int esq = 0;
    int dir = 0;

    balance = getWeightAvl(&(*t)->esq) - getWeightAvl(&(*t)->dir);
    if ((*t)->esq)
        esq = getWeightAvl(&(*t)->esq->esq) - getWeightAvl(&(*t)->esq->dir);
    if ((*t)->dir)
        dir = getWeightAvl(&(*t)->dir->esq) - getWeightAvl(&(*t)->dir->dir);

    if (balance == 2 && esq >= 0)
        rotacaoSimplesDireitaAvl(t);
    if (balance == 2 && esq < 0)
        rotacaoDuplaDireitaAvl(t);

    if (balance == -2 && dir <= 0)
        rotacaoSimplesEsquerdaAvl(t);
    if (balance == -2 && dir > 0)
        rotacaoDuplaEsquerdaAvl(t);
}

void removeTreeAvl(TreeAvl** t, TreeAvl** f, RecordAvl r) {
    TreeAvl* aux;

    if (*t == nullptr) {
        std::cout << "[ERROR]: Record not found!!!" << std::endl;
        return;
    }

    if (r.valor < (*t)->reg.valor) {
        removeTreeAvl(&(*t)->esq, t, r);
        return;
    }
    if (r.valor > (*t)->reg.valor) {
        removeTreeAvl(&(*t)->dir, t, r);
        return;
    }

    if ((*t)->dir == nullptr) {
        aux = *t;
        *t = (*t)->esq;
        delete aux;
        rebalanceTreeAvl(f);
        return;
    }

    if ((*t)->esq != nullptr) {
        antecessorAvl(&(*t)->esq, *t);
        rebalanceTreeAvl(t);
        rebalanceTreeAvl(f);
        return;
    }

    aux = *t;
    *t = (*t)->dir;
    delete aux;
    rebalanceTreeAvl(t);
    rebalanceTreeAvl(f);
}

void preordemAvl(TreeAvl* t, ofstream &file) {
    if (!(t == nullptr)) {
        //file << t->reg.valor << " , ";
        file << t->reg.chave << "-" << t->reg.valor << " , ";
        preordemAvl(t->esq, file);
        preordemAvl(t->dir, file);
    }
}

void centralAvl(TreeAvl* t, ofstream &file) {
    if (!(t == nullptr)) {
        centralAvl(t->esq, file);
        //file << t->reg.valor << " , ";
        file << t->reg.chave << "-" << t->reg.valor << " , ";
        centralAvl(t->dir, file);
    }
}

void posordemAvl(TreeAvl* t, ofstream &file) {
    if (!(t == nullptr)) {
        posordemAvl(t->esq, file);
        posordemAvl(t->dir, file);
        //file << t->reg.valor << " , ";
        file << t->reg.chave << "-" << t->reg.valor << " , ";
    }
}

int getWeightAvl(TreeAvl** t) {
    if (*t == nullptr)
        return -1;
    return (*t)->weight;
}

int getMaxWeightAvl(int esq, int dir) {
    if (esq > dir)
        return esq;
    return dir;
}

void rotacaoSimplesDireitaAvl(TreeAvl** t) {
    TreeAvl* aux;
    aux = (*t)->esq;
    (*t)->esq = aux->dir;
    aux->dir = (*t);
    (*t)->weight = getMaxWeightAvl(getWeightAvl(&(*t)->esq), getWeightAvl(&(*t)->dir)) + 1;
    aux->weight = getMaxWeightAvl(getWeightAvl(&aux->esq), (*t)->weight) + 1;
    (*t) = aux;
}

void rotacaoSimplesEsquerdaAvl(TreeAvl** t) {
    TreeAvl* aux;
    aux = (*t)->dir;
    (*t)->dir = aux->esq;
    aux->esq = (*t);
    (*t)->weight = getMaxWeightAvl(getWeightAvl(&(*t)->esq), getWeightAvl(&(*t)->dir)) + 1;
    aux->weight = getMaxWeightAvl(getWeightAvl(&aux->esq), (*t)->weight) + 1;
    (*t) = aux;
}

void rotacaoDuplaDireitaAvl(TreeAvl** t) {
    rotacaoSimplesEsquerdaAvl(&(*t)->esq);
    rotacaoSimplesDireitaAvl(t);
}

void rotacaoDuplaEsquerdaAvl(TreeAvl** t) {
    rotacaoSimplesDireitaAvl(&(*t)->dir);
    rotacaoSimplesEsquerdaAvl(t);
}


void escreveroutputAvl(std::ofstream &file, TreeAvl* t){
    file << "==[ÁRVORE AVL]==\n\n";

    file << "Método Central: { ";
    centralAvl(t, file);
    file << "}\n\n";

    /*
    file << "Método Pré Ordem: { ";
    preordemAvl(t, file);
    file << "}\n\n";

    file << "Método Pós Ordem: { ";
    posordemAvl(t, file);
    file << "}\n\n";
    */
}