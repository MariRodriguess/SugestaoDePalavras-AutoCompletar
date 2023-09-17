#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>
#include <queue>
#include <string>
#include <iomanip> 
#include <queue>
#include <sstream>
#include <tuple>

using namespace std;

void processArqInput(string& filename, unordered_map<string, int>& glossario, vector<string> stopWord);
void processStopWords(string& filename, vector<string>& stopWord);
void processPalavras(queue<string>& Palavras);

bool verifStopWord(string& str, vector<string> stopWord);
void limparStr(string &str);
string toLower(string str);

void addGlossario(string& str, unordered_map<string, int>& glossario);
void addHeap(unordered_map<string, int> glossario, vector<pair<string, int>>& heap, int k);
void heapify(vector<pair<string, int>>& arr, int n, int i);
void copiarVetor(vector<pair<string, int>> vetor, vector<pair<string, int>>& copia, queue<string> palavras, int k);

void printGlossario(unordered_map<string, int> glossario);
void printVetor(vector<pair<string, int>> vetor);
pair<bool, int> procurarGlossario(string str, unordered_map<string, int> glossario);
void imprimirPalavras(queue<string> Palavras);

#endif