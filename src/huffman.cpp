#include "huffman.hpp"

TreeHuffman* CreateRaizTreeHuffman() {
    return nullptr;
}

bool TVaziaHuffman(TreeHuffman* t) {
    return t == nullptr;
}

void deleteTreeHuffman(TreeHuffman* &t) {
    if (t == nullptr)
        return;

    deleteTreeHuffman(t->esq);
    deleteTreeHuffman(t->dir);

    delete t;
    t = nullptr;
}

void createHuffmanTreeHelper(TreeHuffman* t, string code) {
    if (t == nullptr) {
        return;
    }

    // Se o nó for uma folha, armazene o código de Huffman nele
    if (!t->reg.chave.empty()) {
        t->huffmanCode = code;
    }

    // Recursivamente, visite o filho esquerdo com '0' adicionado ao código
    createHuffmanTreeHelper(t->esq, code + "0");
    // Recursivamente, visite o filho direito com '1' adicionado ao código
    createHuffmanTreeHelper(t->dir, code + "1");
}

TreeHuffman* createHuffmanTree(vector<pair<string, int>> tabFreq) {
    priority_queue<TreeHuffman*, vector<TreeHuffman*>, CompareNodes> filaPrioritaria;

    // Criar nós folha para cada palavra na tabela de frequência
    for (const auto& pair : tabFreq) {
        if (!pair.first.empty()) {
            RecordHuffman record(pair.first, pair.second);
            TreeHuffman* node = new TreeHuffman(record);
            filaPrioritaria.push(node);
        }
    }

    // Construir a árvore de Huffman mesclando os nós
    while (filaPrioritaria.size() > 1) {
        TreeHuffman* esquerdo = filaPrioritaria.top();
        filaPrioritaria.pop();
        TreeHuffman* direito = filaPrioritaria.top();
        filaPrioritaria.pop();

        // Criar um novo nó interno com frequência combinada
        RecordHuffman record("", esquerdo->reg.freq + direito->reg.freq);
        TreeHuffman* newNode = new TreeHuffman(record);
        newNode->esq = esquerdo;
        newNode->dir = direito;

        // Adicionar o novo nó à fila de prioridade
        filaPrioritaria.push(newNode);
    }

    // Chame a função auxiliar para calcular os códigos de Huffman
    createHuffmanTreeHelper(filaPrioritaria.top(), "");

    // Retorne o nó raiz da árvore de Huffman
    return filaPrioritaria.top();
}

void printHuffmanTree(TreeHuffman* t) {
    if (t == nullptr) {
        return;
    }

    // Se o nó for uma folha, imprima a palavra, seu código de Huffman e frequência
    if (!t->reg.chave.empty()) {
        cout << t->reg.chave << " = " << t->huffmanCode << " - " << t->reg.freq << endl;
    }

    // Recursivamente, visite o filho esquerdo
    printHuffmanTree(t->esq);
    // Recursivamente, visite o filho direito
    printHuffmanTree(t->dir);
}


void preordemHuffman(TreeHuffman* t, ofstream &file) {
    if (t == nullptr) {
        return;
    }

    if (!t->reg.chave.empty()) {
        file << t->reg.chave << " = " << t->huffmanCode << " - " << t->reg.freq << " , ";
    }

    preordemHuffman(t->esq, file);
    preordemHuffman(t->dir, file);
}

void centralHuffman(TreeHuffman* t, ofstream &file) {
    if (t == nullptr) {
        return;
    }

    centralHuffman(t->esq, file);

    if (!t->reg.chave.empty()) {
        file << t->reg.chave << " = " << t->huffmanCode << " - " << t->reg.freq << " , ";
    }

    centralHuffman(t->dir, file);
}

void posordemHuffman(TreeHuffman* t, ofstream &file) {
    if (t == nullptr) {
        return;
    }

    posordemHuffman(t->esq, file);
    posordemHuffman(t->dir, file);

    if (!t->reg.chave.empty()) {
        file << t->reg.chave << " = " << t->huffmanCode << " - " << t->reg.freq << " , ";
    }
}

void escreveroutputHuffman(ofstream &file, TreeHuffman* t) {
    file << "==[ÁRVORE HUFFMAN]==\n\n";

    file << "Método Central: { ";
    centralHuffman(t, file);
    file << "}\n\n";

    /*
    file << "Método Pré Ordem: { ";
    preordemHuffman(t, file);
    file << "}\n\n";

    file << "Método Pós Ordem: { ";
    posordemHuffman(t, file);
    file << "}\n\n";
    */    
}