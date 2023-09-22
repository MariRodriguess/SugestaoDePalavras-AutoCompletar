#include "functions.hpp"
#include "tree.hpp"
#include "avl.hpp"
#include "huffman.hpp"

#include <time.h>
#include <locale.h>
#include <chrono>

#define k 15
#define qtdArq 6

int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    //Tempo de execução
    clock_t startTime, endTime;
    startTime = clock();

    //Variaveis gerais
    int cont=1;
    
    //Criação das estruturas gerais
    unordered_map<string, int> glossario;
    vector<string> stopWords;
    queue<string> palavras;

    //Caminhos dos arquivos
    string filestopWords = "data/stopwords.txt";
    processStopWords(filestopWords, stopWords);
    string fileInput = "";
    string fileoutput = "data/output.data";
    ofstream output(fileoutput);

    //Para criação e uso do heap
    vector<pair<string, int>> heap;
    vector<pair<string, int>> copiaHeap;
    string vecHeap = "", copHeap = "";

    while(cont <= qtdArq){

        //Abrindo arquivos de entrada e adicionando as palavras no heap
        fileInput = "data/txt" + to_string(cont) + ".txt";
        processArqInput(fileInput, glossario, stopWords);
        addHeap(glossario, heap, k+1);

        output << "====================================== [" + to_string(cont) + "] TEXTO [" + to_string(cont) + "] ======================================" << endl;

        //Processa as palavras de pesquisa e adiciona em uma fila
        processPalavras(palavras);
        int tamFila = palavras.size();
        while (tamFila>0){
            
            //Valida se a palavra está presente no texto (glossário)
            auto validar = procurarGlossario(palavras.front(), glossario);
            output << "\nPalavra: " << palavras.front() << " - " << validar.second << endl << endl;

            if (validar.first){
                
                //Criação de uma copia do vector heap sem conter a palavra de pesquisa do momento
                copiarVetor(heap, copiaHeap, palavras, k);
                
                if ((copiaHeap.size()>0) && (glossario.size()>0)){

                    //Binária
                    //auto startBinaria = std::chrono::high_resolution_clock::now();
                    TreeBasic* raizBasic = CreateBasicTree();
                    for (const auto& elemento : copiaHeap) {
                        if (!elemento.first.empty()){
                            
                            RecordBasic rBasic;
                            rBasic.chave = elemento.first;
                            rBasic.valor = elemento.second;
                            raizBasic = insertBasicTree(raizBasic, rBasic); 
                        }    
                    }
                    //auto endBinaria = std::chrono::high_resolution_clock::now();
                    //auto durationBinaria = std::chrono::duration_cast<std::chrono::nanoseconds>(endBinaria - startBinaria);
                    //cout << "\nTempo de execucao da arvore Binaria: " << durationBinaria.count() << " ns";

                    //Huffman
                    //auto startHuffman = std::chrono::high_resolution_clock::now();
                    TreeHuffman* huffmanTree = createHuffmanTree(copiaHeap);
                    //auto endHuffman = std::chrono::high_resolution_clock::now();
                    //auto durationHuffman = std::chrono::duration_cast<std::chrono::nanoseconds>(endHuffman - startHuffman);
                    //cout << "\nTempo de execucao da arvore Huffman: " << durationHuffman.count() << " ns";

                    //AVL
                    //auto startAvl = std::chrono::high_resolution_clock::now();
                    TreeAvl* raizAvl = CreateTreeAvl();
                    for (const auto& elemento : copiaHeap) {
                        if (!elemento.first.empty()){

                            RecordAvl rAvl;
                            rAvl.chave = elemento.first;
                            rAvl.valor = elemento.second;
                            insertTreeAvl(&raizAvl, rAvl); 

                        }    
                    }
                    //auto endAvl = std::chrono::high_resolution_clock::now();
                    //auto durationAvl = std::chrono::duration_cast<std::chrono::nanoseconds>(endAvl - startAvl);
                    //cout << "\nTempo de execucao da arvore AVL: " << durationAvl.count() << " ns" << endl << endl;
                    

                    //Escreve o resultado das arvores no arquivo de output
                    escreveroutputBasicTree(output, raizBasic);
                    escreveroutputAvl(output, raizAvl);
                    escreveroutputHuffman(output, huffmanTree);

                    //Exclui as arvores
                    deleteBasicTree(raizBasic);
                    deleteTreeAVL(raizAvl);
                    deleteTreeHuffman(huffmanTree);
                } 
                
            }else{
                output << "Palavra não encontrada no texto." << endl << endl;
            }
            
            //Atualiza as estruturas utilizadas no momento
            palavras.pop();
            copiaHeap.clear();
            tamFila--;
        }
        output << endl;

        //Limpa as estruturas para começar o proximo texto
        glossario.clear();
        heap.clear();
        cont++;
    }
    
    output.close();

    //Tempo de execução
    endTime = clock();
    clock_t elapsedTime = endTime - startTime;
    double elapsedTimeMs = ((double)elapsedTime/CLOCKS_PER_SEC)*1000;
    cout << "\n\nTEMPO DE EXECUÇÃO: " << elapsedTimeMs << " ms " << endl << endl;

    return 0;
}