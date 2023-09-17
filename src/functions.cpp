#include "functions.hpp"

using namespace std;


void processArqInput(string& filename, unordered_map<string, int>& glossario, vector<string> stopWord) {
    ifstream file(filename);

    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }
    
    string line;

    while(getline(file, line)){
        limparStr(line);
        istringstream wordToken(line);
        while(wordToken >> line){
            line = toLower(line);
            if((line!="-") && (line!="—") && (line.find_first_not_of(" \t") != string::npos)){
                if(line.size() > 2 && line.substr(0,2) == "--"){
                    line = line.substr(2);
                    if (!verifStopWord(line, stopWord)){
                        addGlossario(line, glossario);
                    }
                }
                else{
                    if (!verifStopWord(line, stopWord)){
                        addGlossario(line, glossario);
                    }
                }
            }
        }
    }    
    file.close();
}

void limparStr(string &str){
    str.erase(remove(str.begin(),str.end(),','),str.end());
    str.erase(remove(str.begin(),str.end(),'\''),str.end());
    str.erase(remove(str.begin(),str.end(),'"'),str.end());
    str.erase(remove(str.begin(),str.end(),'.'),str.end());
    str.erase(remove(str.begin(),str.end(),'!'),str.end());
    str.erase(remove(str.begin(),str.end(),'?'),str.end());
    str.erase(remove(str.begin(),str.end(),'('),str.end());
    str.erase(remove(str.begin(),str.end(),')'),str.end());    
    str.erase(remove(str.begin(),str.end(),';'),str.end());
    str.erase(remove(str.begin(),str.end(),'/'),str.end());
    str.erase(remove(str.begin(),str.end(),'\\'),str.end());
    str.erase(remove(str.begin(),str.end(),':'),str.end());
    str.erase(remove(str.begin(),str.end(),'1'),str.end());
    str.erase(remove(str.begin(),str.end(),'%'),str.end());
    str.erase(remove(str.begin(),str.end(),'$'),str.end());


    string caractereEsquerda = "\xe2\x80\x9c";
    string caractereDireita = "\xe2\x80\x9d";
    
    size_t foundEsquerda = str.find(caractereEsquerda);
    size_t foundDireita = str.find(caractereDireita);
    
    while (foundEsquerda != string::npos || foundDireita != string::npos) {
        if (foundEsquerda != string::npos) {
            str.erase(foundEsquerda, caractereEsquerda.length());
            foundEsquerda = str.find(caractereEsquerda);
        }
        
        if (foundDireita != string::npos) {
            str.erase(foundDireita, caractereDireita.length());
            foundDireita = str.find(caractereDireita);
        }
    }

}

string toLower(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool verifStopWord(string& str, vector<string> stopWord){

    for (int i=0; i<(int)stopWord.size(); i++){
        if (stopWord[i] == str){
            return true;
        }
    }
    return false;
}


void processStopWords(string& filename, vector<string>& stopWord){
    ifstream file(filename);

    if (!file) {
        cout << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    string palavra;
    while (file >> palavra) {
        stopWord.push_back(palavra);
    }
    file.close();
}

void processPalavras(queue<string>& Palavras){
    ifstream file("data/input.data");

    if (!file) {
        cout << "Erro ao abrir o arquivo: 'data/input.data'" << endl;
        return;
    }

    string palavra;
    while (file >> palavra) {
        Palavras.push(palavra);
    }
    file.close();
}


void addGlossario(string& str, unordered_map<string, int> &glossario){

    auto itmap = glossario.find(str);
    if ((!str.empty()) && (itmap == glossario.end()) && (str!="")){
        glossario[str] = 1;
    }else if ((!str.empty()) && (str!="")){
        glossario[str]++;
    }
}

void addHeap(unordered_map<string, int> glossario, vector<pair<string, int>>& heap, int k){
    int cont = 0, index=0;
    for (const auto& entry : glossario) {
        if (cont < k) {
            heap.push_back(make_pair(entry.first, entry.second));
            index++;
            heapify(heap, index, 0);
        } else if (entry.second > heap[0].second) {
            heap[0] = make_pair(entry.first, entry.second);
            heapify(heap, heap.size(), 0);
        }
        cont++;
    }
    heapify(heap, heap.size(), 0);
}

void heapify(vector<pair<string, int>>& vetor, int k, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < k && vetor[esquerda].second < vetor[maior].second)
        maior = esquerda;

    if (direita < k && vetor[direita].second < vetor[maior].second)
        maior = direita;

    if (maior != i) {
        swap(vetor[i], vetor[maior]);
        heapify(vetor, k, maior);
    }
}


void printGlossario(unordered_map<string, int> glossario){
    int cont=0;
    for (auto it:glossario){
        cout << it.first << " - " << it.second << endl;
        cont++;
    }
    cout << "\n\ncont: " << cont << endl;
}

void printVetor(vector<pair<string, int>> vetor){
    int cont=0;
    
    for (int i = 0; i < (int)vetor.size(); i++) {
        cout << vetor[i].first << ": " << vetor[i].second << " , ";
        cont ++;
    }
}

pair<bool, int> procurarGlossario(string str, std::unordered_map<string, int> glossario) {
    for (auto it : glossario) {
        if (it.first == str) {
            return make_pair(true, it.second);
        }
    }
    return std::make_pair(false, 0);
}


void copiarVetor(vector<pair<string, int>> vetor, vector<pair<string, int>>& copia, queue<string> palavras, int k){
    int cont=0;
    for (int i = 0; i < (int)vetor.size(); i++) {
        if (((vetor[i].first != palavras.front()) && (k>cont) && (!vetor[i].first.empty()))){
            copia.push_back(make_pair(vetor[i].first, vetor[i].second));
            heapify(copia, i, 0);
            cont++;
        }
    }
    heapify(copia, copia.size(), 0);
}

void imprimirPalavras(queue<string> Palavras) {
    while (!Palavras.empty()) {
        cout << Palavras.front() << endl;
        Palavras.pop();
    }
}
  