#include "fila.hpp"

void FFVazia(Fila *f) {
    f->first = new Block;
    f->last = f->first;
    f->first->prox = nullptr;
}

bool isVazia(Fila *f) {
    return f->first == f->last;
}

void Enfileira(Fila *f, Item d) {
    f->last->prox = new Block;
    f->last = f->last->prox;
    f->last->data = d;
    f->last->prox = nullptr;
}

void Desenfileira(Fila *f, Item *d) {
    Block *aux;

    if (f->first == f->last) {
        std::cout << "FILA VAZIA!" << std::endl;
        return;
    }

    aux = f->first->prox;
    f->first->prox = aux->prox;

    if (f->first->prox == nullptr)
        f->last = f->first;

    *d = aux->data;
    delete aux;
}
