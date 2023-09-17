<h1 align="center" font-size="200em"><b>SugestaoDePalavras/AutoCompletar</b></h1>

<div align = "center" >
<!-- imagem -->


[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>


## 📌Sumário

- [Introdução](#introdução)
- [Objetivos](#objetivos)
- [Arquivos](#arquivos)
- [Resolução do Problema](#resolução-do-problema)
- [Funções](#funções)
- [Resultados](#resultados)
- [Conclusão](#conclusão)
- [Referências](#referências)
- [Compilação e execução](#compilação-e-execução)
- [Contato](#contato)

## ✒️Introdução

Este é um programa desenvolvido em C++ para a disciplina de Algoritmos e Estruturas de Dados II.

O presente trabalho aborda a identificação dos k elementos mais relevantes em um conjunto de dados. Estes elementos são então empregados na criação de um sistema de autocompletar e sugestão de palavras para os usuários. Para alcançar esse objetivo, foram empregadas três estruturas fundamentais: árvore Binária Padrão, árvore AVL e árvore de Huffman. Essa abordagem permite a análise comparativa do desempenho dessas estruturas durante o desenvolvimento do programa.

É relevante mencionar que este código incorpora a implementação da atividade anterior de Algoritmos e Estruturas de Dados I, que se concentra na identificação das palavras mais frequentes em um texto usando a estrutura de dados Heap mínimo. Para obter informações mais detalhadas sobre essa parte específica do código, é possível acessar o seguinte link: Link para a implementação anterior. Isso proporciona aos interessados um contexto adicional sobre o projeto e sua evolução ao longo do curso.

## 💻Objetivos

O objetivo deste projeto é criar um sistema de autocompletar e sugestões de palavras usando árvores binárias como base. O sistema deve ser capaz de receber um arquivo de entrada contendo uma lista de palavras de pesquisa, construir árvores binárias a partir de textos fornecidos, identificar palavras relevantes e apresentar os resultados em um arquivo de saída. Além disso, o projeto inclui a exploração de diferentes abordagens, incluindo a implementação de uma árvore Binária Padrão, a codificação de Huffman e a utilização de árvores AVL, permitindo uma análise comparativa do desempenho e funcionalidade das diferentes implementações das árvores binárias no contexto do sistema de autocompletar e sugestões de palavras.

<strong><h4>Condições impostas: </h4></strong>
- Este programa deverá ler uma coleção de arquivos contento textos sem nenhuma formatação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".", "?", "!").
- Cada parágrafo é separado por, pelo menos, uma linha em branco.
- Considere como palavra uma sequência de letras delimitada por espaço em branco, ”coluna da esquerda”, ”coluna da direita” e símbolos de pontuação.
- O programa deve ser capaz de ler um ou mais arquivos de entrada com o nome "data/txt(x).txt," onde "x" pode ser ajustado pelo usuário. Se houver 3 textos, por exemplo, os arquivos "txt1.txt," "txt2.txt," e "txt3.txt" devem ser adicionados à pasta "data".
- O usuário deve fornecer um arquivo chamado "input.data" na pasta "data," contendo uma lista de palavras-chave, uma por linha. Cada palavra será tratada como um termo de pesquisa no sistema.
- Um arquivo de "stop words" também é fornecido na pasta "data" contendo artigos e conjunções que devem ser ignorados ao contar as palavras mais frequentes. O usuário pode personalizar essa lista conforme desejar.
- Após o processamento, um arquivo chamado "output.txt" será automaticamente gerado na pasta "data" para apresentar informações de saída de forma organizada. Esse arquivo incluirá o nome do arquivo lido no formato "Texto x", a palavra pesquisada e sua frequência. Além disso, as três árvores binárias serão representadas usando o método central, juntamente com a árvore de Huffman codificada com base nos códigos gerados, também apresentados usando o método central.
- Faz parte do projeto do programa fornecer uma saída legível.

## 📄Arquivos
<strong>main.cpp:</strong> Responsável pela criação das principais estruturas do código e chamadas das funções necessárias para o funcionamento do programa.

<strong>functions.hpp</strong> e <strong>functions.cpp:</strong> Encarregados da declaração e desenvolvimento das funções gerais do código.

<strong>tree.cpp</strong> e <strong>tree.hpp:</strong>> Encarregados da declaração e desenvolvimento das funções da árvore binária padrão.

<strong>huffman.cpp</strong> e <strong>huffman.hpp:</strong> Responsáveis pela declaração e desenvolvimento das funções da árvore de codificação de Huffman.

<strong>avl.cpp</strong> e <strong>avl.hpp:</strong> Responsáveis pela declaração e desenvolvimento das funções da árvore AVL.

<strong>fila.cpp</strong> e <strong>fila.hpp:</strong> Responsáveis pela declaração e desenvolvimento das funções de uma fila, utilizadas para a impressão das árvores utilizando o método em níveis, caso seja do interesse do usuário.

<strong>data/txtx.txt:</strong> Arquivo de texto de entrada, onde "x" é um parâmetro ajustável que representa o número dos respectivos arquivos txt.

<strong>data/stopwords.txt:</strong> Arquivo de texto contendo as "stop words", como artigos (a, o, as, os) e conjunções (e, ou).

<strong>data/input.data:</strong> Arquivo de dados contendo as palavras-chave de pesquisa, uma por linha.

## 🔨Resolução do problema

A fim de resolver eficientemente o problema de identificar as K palavras mais frequentes em uma coleção de textos, o código utiliza uma combinação eficaz de estruturas de dados: o uso de um Unordered Map como Tabela Hash e a utilização de um Heap Mínimo para manter as K palavras mais frequentes.

Para entender melhor como essas estruturas de dados se relacionam com o problema em questão no contexto do código, você pode consultar a documentação do repositório mencionado na introdução.

No desenvolvimento deste código para resolver o novo problema, foram empregadas as seguintes estruturas de dados:

<h3><b>Árvore Binária Padrão</b></h3>

Uma árvore binária padrão representa uma estrutura de dados não linear organizada hierarquicamente. Em uma árvore binária, cada nó pode ter, no máximo, dois filhos: um à esquerda e outro à direita. Cada nó armazena um elemento de dados e possui referências para seus filhos, um à esquerda e outro à direita. O nó de topo na hierarquia é conhecido como o nó raiz da árvore.

Dentro de uma árvore de busca binária, segue-se a regra de que o valor de um nó à esquerda é menor que o valor do nó pai, enquanto o valor de um nó à direita é maior que o valor do nó pai. Essa regra é aplicada recursivamente às subárvores à esquerda e à direita da raiz.

<p align="center">
  <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/2f215d21-5342-479f-b574-739b0be86b1b" width="500px" height="auto" alt="gif">
</p>

<p align="center">
  GIF criado utilizando o simulador disponível em: https://www.cs.usfca.edu/~galles/visualization/BST.html
</p>


<br>No GIF acima, podemos observar que o nó raiz é 15, e todos os nós da subárvore esquerda são menores que o nó raiz, e todos os nós da subárvore direita são maiores que o nó raiz. É possível observar também que o lado esquerdo da árvore obteve uma altura 5, enquanto o lado direito obteve uma altura 2, o que mostra que a árvore está desequilibrada.

No código desenvolvido, quando o valor de um nó é igual ao valor da raiz, esses nós são direcionados para a esquerda.

A complexidade de tempo para operações em uma árvore binária depende da altura da árvore. No pior caso, em uma árvore desbalanceada, as operações podem ter uma complexidade de O(n), onde "n" é o número de elementos na árvore. No entanto, em uma árvore balanceada, como uma árvore de busca binária balanceada, as operações de busca, inserção e remoção têm uma complexidade média de O(log n), onde "n" é o número de elementos.

<h3><b>Árvore de Huffman</b></h3>

Uma árvore de Huffman representa uma estrutura de dados usada principalmente para compressão de dados, como em algoritmos de compactação de arquivos. Ela é construída a partir de um conjunto de símbolos, onde cada símbolo tem uma frequência associada. A ideia central é atribuir códigos binários menores às frequências mais altas, otimizando assim a compressão.

A codificação e decodificação da árvore de Huffman envolvem a representação dos símbolos em um código binário. Os símbolos são dispostos nas folhas da árvore, e os caminhos da raiz às folhas representam os códigos binários associados a esses símbolos. A codificação de Huffman é gerada atribuindo "1" quando se move para a direita na árvore e "0" quando se move para a esquerda.

Dentro de uma árvore de Huffman, os símbolos com maiores frequências são geralmente posicionados mais próximos da raiz, enquanto os símbolos com menores frequências estão nas folhas mais distantes. Isso garante que os símbolos mais frequentes tenham códigos mais curtos, o que otimiza a compactação.

Nesse código, o processo de codificação de Huffman se inicia com a construção de uma árvore que se baseia nas frequências das palavras. Posteriormente, essa árvore é empregada para gerar códigos individuais para cada palavra. 

O GIF abaixo ilustra o processo de construção de uma árvore de codificação de Huffman para as palavras: "entre", "modo", "mundo", "sujeito" e "teoria", junto com suas respectivas frequências no arquivo "txt1.txt" disponível na pasta "data" (frequências: 127, 129, 134, 145 e 176).

<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/bc91d3ed-250e-452e-b637-3b719e03f9cb" width="500px" height="auto" alt=".">
    <figcaption>Construção de uma árvore de codificação Huffman</figcaption>
  </figure>
</div>

<br> É evidente que a construção da árvore segue uma lógica de ordenar as palavras de acordo com suas frequências, neste caso, em ordem crescente, e então combinar sempre as duas frequências mais baixas em um único nó, e reorganizar as palavras novamente. Esse processo é repetido até que reste apenas um único nó na árvore. Posteriormente, para atribuir códigos a cada palavra, percorremos a árvore, adicionando "1" quando seguimos para a direita e "0" quando seguimos para a esquerda. Isso resulta em códigos únicos para cada palavra na árvore de Huffman.

A complexidade de tempo para a construção da árvore de Huffman é geralmente O(n log n), onde "n" é o número de símbolos. No entanto, uma vez que a árvore está construída, a codificação e a decodificação têm complexidade O(log n), o que a torna eficiente para a compressão de dados.

<h3><b>Árvore AVL</b></h3>

Uma árvore AVL é uma estrutura de dados de árvore binária de busca balanceada, e sua principal característica é a manutenção automática do equilíbrio após inserções e remoções de elementos. Essa manutenção é realizada por meio de rotações, que reorganizam a árvore para garantir que a diferença de altura entre as subárvores esquerda e direita de cada nó (fator de balanceamento) seja, no máximo, 1.

As rotações desempenham um papel fundamental no processo de balanceamento das árvores AVL e podem ser divididas em quatro configurações distintas:

▶ Rotação Simples à Esquerda:<br>
Essa rotação é aplicada quando um nó desequilibrado tem uma subárvore direita mais alta do que a subárvore esquerda, violando a condição de equilíbrio.
A rotação simples à esquerda envolve uma única operação que move o filho direito do nó desequilibrado para a posição do nó pai, enquanto o nó pai se torna o filho esquerdo do nó anteriormente filho direito.

▶ Rotação Simples à Direita:<br>
Essa rotação é aplicada quando um nó desequilibrado tem uma subárvore esquerda mais alta do que a subárvore direita, violando a condição de equilíbrio.
A rotação simples à direita é semelhante à rotação à esquerda, mas envolve movimentos na direção oposta, onde o filho esquerdo do nó desequilibrado se torna o novo nó pai, e o nó pai se torna o filho direito do nó anteriormente filho esquerdo.

▶ Rotação Dupla à Esquerda:<br>
Esta rotação é necessária quando ocorre uma desigualdade de altura na subárvore direita de um nó e a subárvore esquerda de seu filho direito.
A rotação dupla à esquerda envolve duas rotações simples: primeiro uma rotação simples à direita no filho direito do nó desequilibrado, seguida por uma rotação simples à esquerda no nó desequilibrado.

▶ Rotação Dupla à Direita:<br>
Esta rotação é aplicada quando há uma desigualdade de altura na subárvore esquerda de um nó e a subárvore direita de seu filho esquerdo.
A rotação dupla à direita consiste em duas rotações simples consecutivas: primeiro, uma rotação simples à esquerda no filho esquerdo do nó desequilibrado, seguida por uma rotação simples à direita no nó desequilibrado.

O processo de balanceamento de uma árvore binária tem como objetivo a redução do número médio de comparações necessárias para encontrar qualquer elemento na árvore. Durante as operações de inserção e remoção, há uma tendência de desequilíbrio na árvore, o que implica em um custo adicional nessas etapas para garantir que o equilíbrio seja sempre mantido. 

No entanto, é importante notar que esses mecanismos de balanceamento, garantem que a altura da árvore seja mantida em um limite logarítmico em relação ao número de elementos "n". No GIF abaixo, é possível perceber que os elementos são os mesmos inseridos na ávore Binária Padrão anteriormente, e enquanto na AVL a diferença de altura do lado esquerdo para o lado direito foi apenas 1, na AVL foi 3.

<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/df3263b3-ff35-404f-a5d7-49cdf7b727d0" width="500px" height="auto" alt=".">
    <figcaption>GIF criado utilizando o simulador disponível em: https://www.cs.usfca.edu/~galles/visualization/AVLtree.html</figcaption>
  </figure>
</div>

<br> Portanto, independentemente da sequência de operações realizadas, a árvore AVL continua a fornecer um desempenho eficiente e previsível para operações de busca, inserção e remoção, com a complexidade limitada a O(log n). 

## 🔨 Funções 

As funções utilizadas para encontrar as K palavras mais recorrentes do texto foram detalhadamente especificadas na documentação do Trabalho de AED I. Porém, houve alterações em relação à eliminação de caracteres especiais durante a leitura, substituindo o uso de regex por um método idiomático, que é eficaz para remover caracteres indesejados e realizar operações de limpeza em strings. Além disso, vale destacar que são encontradas k+1 palavras mais recorrentes. Isso permite que, caso uma das palavras seja igual à palavra de busca atual, ela seja substituída por outra que seja ainda mais recorrente.

- ```copiarVetor(vector<pair<string, int>> vetor, vector<pair<string, int>>& copia, queue<string> palavras, int k):``` Essa função percorre o vetor "heap", que contém as k+1 palavras mais recorrentes do texto. Em cada iteração, ela adiciona cada palavra a um vetor auxiliar e chama a função "heapify" para reorganizar esse vetor como um heap mínimo. No entanto, caso a palavra atual de busca seja encontrada durante a iteração, ela não é incluída no vetor auxiliar. No final da execução, o vetor auxiliar será idêntico ao heap, contendo k palavras, e não incluirá a palavra atual de busca. Isso garante que o vetor resultante contenha as k palavras mais recorrentes, excluindo a palavra de busca atual.

▶ Árvore Binária Padrão:

- ```CreateBasicTree:``` Essa função cria e retorna uma árvore binária vazia baseada na estrutura `TreeBasic`. Inicialmente, a árvore é criada com um nó raiz representado pelo ponteiro `nullptr`, indicando que não há elementos na árvore no momento da criação.

    A estrutura `TreeBasic` é composta por três elementos principais:
        1. `reg`: Este campo armazena um registro do tipo `RecordBasic`, que consiste em uma string de chave (`chave`) e um valor inteiro (`valor`). Neste contexto, cada nó da árvore binária contém um par de valores chave-valor associados.
        2. `esq`: Este é um ponteiro para o filho esquerdo do nó na árvore. Inicialmente, quando a árvore é criada com `CreateBasicTree`, esse ponteiro está definido como `nullptr`, indicando que não há filho esquerdo.
        3. `dir`: Similarmente, este é um ponteiro para o filho direito do nó na árvore, e também é inicializado como `nullptr`.

    Resumindo, a função `CreateBasicTree` é responsável por configurar uma árvore binária básica vazia que pode ser usada posteriormente para adicionar elementos e construir uma estrutura hierárquica de dados. Por padrão, quando esta função é chamada, ela retorna um ponteiro nulo (`nullptr`), indicando que a árvore está vazia e pronta para a inserção de dados.

- ```TVaziaBasicTree(TreeBasic t):``` Essa função verifica se uma árvore binária de busca (representada pelo ponteiro t) está vazia. Ela retorna true se a árvore estiver vazia (ponteiro nulo) e false caso contrário.

- ```deleteBasicTree(TreeBasic &t):``` Essa função é responsável por liberar a memória associada a uma árvore binária de busca e garantir que todos os seus nós sejam devidamente desalocados. O ponteiro t passado por referência é atualizado para nulo após a liberação.

- ```insertBasicTree(TreeBasic t, RecordBasic r):``` Essa função insere um novo registro r em uma árvore binária de busca representada por t. Ela verifica se a árvore está vazia e insere o novo nó na posição adequada para manter a propriedade de árvore de busca binária, levando em consideração o valor do registro r.

<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/22b60d92-78a4-46ee-97af-77b24b0d33d5" width="500px" height="auto" alt=".">
    <figcaption>Função insertBasicTree</figcaption>
  </figure>
</div>

<br>

- ```preordemBasicTree(TreeBasic t, ofstream &file):``` Essa função realiza uma travessia pré-ordem na árvore binária de busca t e escreve os registros no arquivo de saída file. A travessia pré-ordem visita primeiro o nó raiz, seguido dos nós à esquerda e, por fim, dos nós à direita.

- ```centralBasicTree(TreeBasic t, ofstream &file):``` Essa função realiza uma travessia em ordem (ou central) na árvore binária de busca t e escreve os registros no arquivo de saída file. A travessia em ordem visita primeiro os nós à esquerda, seguido do nó raiz e, por fim, dos nós à direita.

- ```posordemBasicTree(TreeBasic t, ofstream &file):``` Essa função realiza uma travessia pós-ordem na árvore binária de busca t e escreve os registros no arquivo de saída file. A travessia pós-ordem visita primeiro os nós à esquerda, seguido dos nós à direita e, por fim, o nó raiz.

- ```escreveroutputBasicTree(std::ofstream &file, TreeBasic t):``` Essa função escreve no arquivo de saída file uma representação dos registros armazenados na árvore binária de busca t. Ela inclui registros na ordem definida pela função centralBst e adiciona um cabeçalho indicando que se trata de uma árvore binária.

▶ Árvore de Huffman:

- ```CreateRaizTreeHuffman:``` Esta função cria e retorna uma árvore de Huffman vazia com um nó raiz representado pelo ponteiro `nullptr`. A estrutura `TreeHuffman` é composta pelos seguintes elementos:
   1. `reg`: Este campo armazena um registro do tipo `RecordHuffman`, que inclui uma string de chave (`chave`) e um valor de frequência (`freq`).
   2. `esq` e `dir`: Esses são ponteiros para os filhos esquerdo e direito da árvore de Huffman, inicialmente definidos como `nullptr`.
   3. `huffmanCode`: Este campo é usado para armazenar o código de Huffman associado a um nó.

- ```TVaziaHuffman(TreeHuffman* t):``` Esta função verifica se uma árvore de Huffman (representada pelo ponteiro `t`) está vazia. Ela retorna `true` se a árvore estiver vazia (ponteiro nulo) e `false` caso contrário.

- ```deleteTreeHuffman(TreeHuffman* &t):``` Esta função é responsável por liberar a memória associada a uma árvore de Huffman e garantir que todos os seus nós sejam devidamente desalocados. O ponteiro `t` passado por referência é atualizado para nulo após a liberação.

- ```createHuffmanTreeHelper(TreeHuffman* t, string code):``` Esta função auxiliar é usada para calcular os códigos de Huffman associados aos nós da árvore de Huffman. Ela percorre a árvore e armazena os códigos nos nós folha, atribuindo "1" quando se move para a direita na árvore e "0" quando se move para a esquerda.

- ```createHuffmanTree(vector<pair<string, int>> tabFreq):``` Esta função cria uma árvore de Huffman com base em uma tabela de frequência de palavras. Ela constrói a árvore mesclando os nós de acordo com suas frequências, usando uma fila de prioridade. Em seguida, chama a função auxiliar `createHuffmanTreeHelper` para calcular os códigos de Huffman.

<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/d1ec4ab7-eea4-4656-b317-c11655cfb486" width="500px" height="auto" alt=".">
    <figcaption>Função createHuffmanTree</figcaption>
  </figure>
</div>

<br>

- ```printHuffmanTree(TreeHuffman* t):``` Esta função imprime os nós da árvore de Huffman juntamente com seus códigos de Huffman e frequências. É usada para depuração e visualização da árvore.

- ```preordemHuffman(TreeHuffman* t, ofstream &file):``` Esta função realiza uma travessia pré-ordem na árvore de Huffman `t` e escreve os registros em um arquivo de saída `file`. A travessia pré-ordem visita primeiro o nó raiz, seguido dos nós à esquerda e, por fim, dos nós à direita.

- ```centralHuffman(TreeHuffman* t, ofstream &file):``` Esta função realiza uma travessia em ordem (ou central) na árvore de Huffman `t` e escreve os registros em um arquivo de saída `file`. A travessia em ordem visita primeiro os nós à esquerda, seguido do nó raiz e, por fim, dos nós à direita.

- ```posordemHuffman(TreeHuffman* t, ofstream &file):``` Esta função realiza uma travessia pós-ordem na árvore de Huffman `t` e escreve os registros em um arquivo de saída `file`. A travessia pós-ordem visita primeiro os nós à esquerda, seguido dos nós à direita e, por fim, o nó raiz.

- ```escreveroutputHuffman(ofstream &file, TreeHuffman* t):``` Esta função escreve no arquivo de saída `file` uma representação dos registros armazenados na árvore de Huffman `t`. Ela inclui registros na ordem definida pela função `centralHuffman` e adiciona um cabeçalho indicando que se trata de uma árvore de Huffman.

▶ Árvore AVL:

- ```CreateTreeAvl:``` Essa função cria e retorna uma árvore AVL (Árvore de Busca Binária Balanceada) vazia baseada na estrutura `TreeAvl`. Inicialmente, a árvore é criada com um nó raiz representado pelo ponteiro `nullptr`, indicando que não há elementos na árvore no momento da criação.

    A estrutura `TreeAvl` é composta por quatro elementos principais:
        1. `reg`: Este campo armazena um registro do tipo `RecordAvl`, que consiste em uma string de chave (`chave`) e um valor inteiro (`valor`). Cada nó da árvore binária contém um par de valores chave-valor associados.
        2. `esq`: Este é um ponteiro para o filho esquerdo do nó na árvore. Inicialmente, quando a árvore é criada com `CreateTreeAvl`, esse ponteiro é definido como `nullptr`, indicando que não há filho esquerdo.
        3. `dir`: Similarmente, este é um ponteiro para o filho direito do nó na árvore e também é inicializado como `nullptr`.
        4. `weight`: Este campo mantém o fator de balanceamento (peso) do nó, que é usado para garantir que a árvore AVL permaneça balanceada.

- ```deleteTreeAVL(TreeAvl*& t):``` Essa função é responsável por liberar a memória associada a uma árvore AVL e garantir que todos os seus nós sejam devidamente desalocados. O ponteiro `t` passado por referência é atualizado para nulo após a liberação.

- ```insertTreeAvl(TreeAvl** t, RecordAvl r):``` Essa função insere um novo registro `r` em uma árvore AVL representada por `t`. Ela verifica se a árvore está vazia e insere o novo nó na posição adequada para manter a propriedade de árvore de busca binária balanceada, levando em consideração o valor do registro `r`. Além disso, ela realiza rotações simples ou duplas, se necessário, para manter o balanceamento da árvore.

<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/504e828e-5384-4d82-aa92-9be9ae9f01ec" width="500px" height="auto" alt=".">
    <figcaption>Função insertTreeAvl</figcaption>
  </figure>
</div>
<br>

- ```pesquisaAvl(TreeAvl** t, TreeAvl** aux, RecordAvl r):``` Essa função busca um registro na árvore AVL. Se o registro for encontrado, o ponteiro `aux` aponta para o nó correspondente; caso contrário, uma mensagem de erro é exibida.

- ```removeTreeAvl(TreeAvl** t, TreeAvl** f, RecordAvl r):``` Essa função remove um registro da árvore AVL. Ela verifica se o registro existe na árvore, remove-o e realiza rebalanceamento, se necessário, para manter a árvore balanceada.

- ```preordemAvl(TreeAvl* t, ofstream &file):``` Essa função realiza uma travessia pré-ordem na árvore AVL `t` e escreve os registros em um arquivo de saída `file`. A travessia pré-ordem visita primeiro o nó raiz, seguido dos nós à esquerda e, por fim, dos nós à direita.

- ```centralAvl(TreeAvl* t, ofstream &file):``` Essa função realiza uma travessia em ordem (ou central) na árvore AVL `t` e escreve os registros em um arquivo de saída `file`. A travessia em ordem visita primeiro os nós à esquerda, seguido do nó raiz e, por fim, dos nós à direita.

- ```posordemAvl(TreeAvl* t, ofstream &file):``` Essa função realiza uma travessia pós-ordem na árvore AVL `t` e escreve os registros em um arquivo de saída `file`. A travessia pós-ordem visita primeiro os nós à esquerda, seguido dos nós à direita e, por fim, o nó raiz.

- ```escreveroutputAvl(std::ofstream &file, TreeAvl* t):``` Essa função escreve no arquivo de saída `file` uma representação dos registros armazenados na árvore AVL `t`. Ela inclui registros na ordem definida pela função `centralAvl` e adiciona um cabeçalho indicando que se trata de uma árvore AVL.

▶ main.cpp:

- Na função principal (main), além de invocar as funções responsáveis pelo funcionamento do código, são realizadas operações de abertura de arquivos de texto a serem lidos e a coleta das palavras-chave de busca. Para cada texto lido, é criado um glossário específico, juntamente com um vetor que representa uma estrutura de heap mínimo e outro vetor que armazena todas as palavras-chave.

    O processo se inicia com a leitura da primeira palavra do vetor. Se a palavra existir no glossário, ou seja, no texto em análise, o código gera uma cópia do vetor da heap, removendo a palavra em questão, desde que esta esteja entre as mais frequentes. Em seguida, são criadas as três árvores e as palavras da cópia da heap são inseridas em cada uma delas. Os resultados são registrados no arquivo de saída (output) e, em seguida, as árvores são eliminadas. No caso em que a palavra não existe no texto, o código apenas a registra no arquivo de saída com a mensagem indicando que a palavra não foi encontrada no texto em questão.

    Após a conclusão desse processo para a primeira palavra do vetor, essa palavra é removida e a próxima palavra é lida, repetindo-se o ciclo. Esse processo continua até que o vetor de palavras-chave esteja vazio. Posteriormente, o glossário é deletado, e o próximo texto é lido e todo o processo se repete novamente. Esse ciclo é repetido até que todos os textos tenham sido lidos, e todas as árvores tenham sido criadas e seus resultados inseridos no arquivo de saída.


## 🎯Resultados

▶ Arquivo output:

<h4><b>Entradas: </b></h4>
<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/6cb45f0b-bc5d-42c6-a741-224377e5fe62" width="700px" height="auto" alt=".">
    <figcaption>Entradas: txt1.txt e txt2.txt, disponíveis na pasta "data" (qtdArq=2), com 7 palavras mais recorrentes (k=7) e 2 palavras-chave de busca</figcaption>
  </figure>
</div>

<h4><b>Saida:</b></h4>
<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/3dccdf7a-55af-4dce-af6b-a7c03d82d0fb" width="800px" height="auto" alt=".">
    <figcaption>Arquivo "output.data" após a execução</figcaption>
  </figure>
</div>


▶ Terminal de comando:

<h4><b>Entradas:</b></h4>

Todos os 6 arquivos de texto disponíveis na pasta "data" (qtdArq=6), com 10 palavras mais recorrentes (k=10) e 1 palavra-chave de busca. </b></h4>


<h4><b>Saida:</b></h4>
<div align="center">
  <figure>
    <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/23c60e4d-f9c8-409c-afd4-4ae4dde05e3c" width="450px" height="auto" alt=".">
    <figcaption>Saída do terminal de comando</figcaption>
  </figure>
</div>



## ✔️Conclusão

Neste projeto, foi implementado três estruturas de árvores binárias (Árvore Binária Padrão, Árvore de Huffman e Árvore AVL) para processar e analisar textos. Com base nos resultados obtidos, podemos fazer algumas considerações importantes sobre o desempenho e a utilidade de cada uma dessas estruturas.

A Árvore Binária Padrão apresentou um tempo de execução consistente e relativamente baixo em comparação com as outras estruturas. Sua simplicidade a torna uma opção viável, especialmente quando se prioriza a simplicidade no código. No entanto, uma desvantagem significativa dessa abordagem reside na ausência de balanceamento automático da árvore. Isso pode resultar em um caminhamento ineficiente, particularmente quando um lado da árvore se torna substancialmente maior que o outro. Esse desequilíbrio pode impactar negativamente o desempenho da busca, aumentando o número de passos necessários para encontrar palavras-chave, o que pode ser problemático em cenários de alta demanda de processamento.

A Árvore de Huffman mostrou um tempo de execução mais longo em comparação com a Árvore Binária Padrão e a Árvore AVL. Essa estrutura é especialmente útil quando o foco principal é a compactação de dados, como na compressão de arquivos. No contexto deste projeto, a Árvore de Huffman fornece uma representação eficiente das palavras com base na frequência. No entanto, essa eficiência vem com um custo em termos de tempo de execução.

A Árvore AVL apresentou um desempenho sólido, mesmo em grandes conjuntos de dados. Ela manteve tempos de execução razoáveis, o que a torna uma escolha sólida para sistemas de autocompletar e sugestões de palavras. A principal vantagem da Árvore AVL é a capacidade de manter um equilíbrio entre a estrutura da árvore, o que garante tempos de busca previsíveis.

A escolha da estrutura de árvore depende das necessidades específicas do projeto. Se a prioridade for a eficiência na pesquisa em tempo real, a Árvore Binária Padrão pode ser uma boa escolha devido ao seu tempo de execução mais rápido.  No entanto, se o projeto envolver frequentes operações de busca e inserção, a Árvore AVL é a opção mais equilibrada, garantindo um bom desempenho em ambas as operações. Por outro lado, a Árvore de Huffman é mais apropriada para cenários que envolvem a compressão de dados, onde a economia de espaço é fundamental, tornando-a a escolha ideal para essas situações específicas.

Em resumo, este projeto demonstrou a importância da escolha da estrutura de dados adequada para atender às demandas específicas de um sistema. Cada estrutura tem suas vantagens e desvantagens, e a decisão deve ser baseada nas necessidades de desempenho e relevância do projeto em questão.

## ✔️Referências
- https://www.cs.usfca.edu/~galles/visualization/BST.html
- https://www.programiz.com/dsa/binary-search-tree
- https://www.youtube.com/watch?v=o8UPZ_KDWdU
- https://www.youtube.com/watch?v=wrOrg1GdS-0
- https://www.programiz.com/dsa/huffman-coding
- https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
- https://www.programiz.com/dsa/avl-tree
- https://www.youtube.com/watch?v=l8IBdCb2BWA&t=0s

## 👾Compilação e execução

* Especificações da máquina em que o código foi rodado:
  * AMD Ryzen 5-3500U;
  * Sistema Operacional Windows 11 Pro e Sistema Operacional Linux;
  * Terminal do Visual Studio;
  * 12GB de RAM.

* **(🚨)** Inicialmente, cinco configurações precisam ser especificadas no código:

  * **Quantidade de Arquivos a Serem Lidos:**
  Para permitir a leitura de um ou vários arquivos de texto, você deve definir a quantidade na variável qtdArq. Além disso, nomeie todos os arquivos como data/input(x).txt, em que o valor de x é um parâmetro ajustável. Por exemplo, se deseja processar dois arquivos de entrada, os nomes serão data/input1.txt e data/input2.txt, seguindo essa sequência para a quantidade de arquivos definida em qtdArq. É importante observar que a pasta chamada "data" foi criada para alocar os arquivos de entrada.

  * **Quantidade de Palavras com Maior Ocorrência Desejada:**
  Para obter as K palavras mais frequentes no texto, você só precisa ajustar a variável "k" para o valor desejado. Por exemplo, se almeja as 20 palavras mais recorrentes, basta definir k=20. Isso permitirá que o código identifique e exiba as palavras mais frequentes conforme a quantidade definida.

      <br> <img src="https://github.com/MariRodriguess/TOP_K_Elementos/assets/127866299/477dabdd-de12-4ef2-bbea-1c95a50ec8fe">

  * **Palavras-chaves de busca:**
  Para utilizar as palavras desejadas como critérios de busca, basta incluí-las no arquivo "input.data" seguindo o formato ilustrado abaixo:
 
      <br> <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/3ea5e983-618a-49e4-b95b-e0201a82067d">

  * **Palavras stopwords:**
  Para adicionar palavras específicas como palavras de parada (stopwords), basta listá-las no arquivo "stopword.txt" conforme o formato exemplificado a seguir:
   
      <br> <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/4b193044-2256-41ea-b627-4b54b7af9893">

  * **Textos a serem lidos:**
  Para adicionar os textos que serão processados, basta colocá-los na pasta "data" e nomeá-los no padrão "txt(x).txt", como ilustrado abaixo:

      <br> <img src="https://github.com/MariRodriguess/SugestaoDePalavras-AutoCompletar/assets/127866299/69089a9b-4954-4bbf-9fd1-26807b7970d3">


* | Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
  |  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## ✉️Contato
<div>
 <br><p align="justify"> Mariana Rodrigues Lamounier Melo</p>
 <a href="https://t.me/MariRodriguess0">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:mariana.itapec@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>mariana.itapec@gmail.com</i>
</a>
