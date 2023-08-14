<h1 align="center" font-size="200em"><b>Top K elementos</b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## 📌Sumário
- [Introdução](#Introdução)
- [Objetivos](#Objetivos)
- [Arquivos](#Arquivos)
- [Resolução do Problema](#Resolução-do-problema)
- [Funções](#Funções)
- [Resultados](#Resultados)
- [Conclusão](#Conclusão)
- [Referências](#Referências)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)

## ✒️Introdução
<p align="justify">
Este programa em C++ foi criado como parte do curso de Algoritmos e Estruturas de Dados I. O objetivo central é encontrar os k elementos mais valiosos dentre um conjunto de dados. Para alcançar essa meta, faz-se uso de tabelas de hash para rastrear a frequência de cada item, enquanto uma estrutura de heap é empregada para gerenciar uma lista dos k palavras mais frequentes no texto de forma eficiente.
</p>

## 💻Objetivos

O propósito deste projeto é construir uma tabela de dispersão (hash) para registrar a frequência de cada elemento tokenizado na coleção de dados de entrada. Além disso, visa-se criar uma árvore de prioridades (heap) com capacidade para k elementos, na qual os primeiros k elementos da tabela de dispersão são inseridos.

<strong><h4>Condições impostas: </h4></strong>
- Inicialmente, este código realiza a leitura de um arquivo de entrada denominado ```data/input(x).txt```. O arquivo contém o texto que será submetido à análise. No contexto, o valor de x é o valor de uma variável ajustável no início do arquivo ```main```, denominada numFiles. Por exemplo, se houver a necessidade de processar dois arquivos de entrada, os nomes dos arquivos seriam data/input1.txt e data/input2.txt, e assim sucessivamente, de acordo com a quantidade de arquivos definida na variável numFiles. Lembrando que ```data``` é a pasta criada para os arquivos de entrada.
- As sentenças são definidas pelos sinais de pontuação (".", "?", "!").
- Cada parágrafo é separado por uma linha em branco.
- Existe um arquivo de ```stop words``` para análise. Sendo as stop words artigos e conjunções que podem ser alteradas de acordo com a preferência do usuário. As palavras presentes neste arquivo serão desconsideradas da contagem das top k palavras.
- Ao término da execução, a estrutura de heap conterá os k elementos com os maiores valores (frequências) na coleção de dados. Posteriormente, esses elementos são impressos em ordem crescente no terminal.
- Há somente uma saída no terminal, a qual é a combinação das palavras mais frequentemente encontradas em todos os textos fornecidos como entrada.


## 📄Arquivos
- <strong>Main.cpp:</strong> Na função main, inicia uma instância do topKItems, arquivos de entrada são processados e é chamado as funçoes, além de definir o tamanho do heap.
- <strong>topKElementos.hpp:</strong> Declaração das funções.
- <strong>topKELementos.cpp:</strong> Desenvolvimento das funções. 
- <strong>data/input.txt:</strong> Texto de entrada.
- <strong>data/stopwords.txt:</strong> Stop words, como por exemplo, para artigo (a, o, as,os) e para conjunções (e, ou).

## 🔨Resolução do problema

Visando encontrar uma solução eficiente e rápida para resolução do problema, foram usadas as seguintes estruturas de dados:

<h3><b>Unodered_map</b></h3>

Emprega uma tabela de hash para armazenar as palavras e suas frequencias, resultando em inserções e buscas rápidas com complexidade média de O(1). Isso é benéfico quando é crucial ter acesso veloz, tornando possível utilizar palavras como chaves para contabilizar suas frequências.

<h3><b>Unodered_set</b></h3>

É um contêiner associativo não ordenado implementado usando uma tabela de hash onde as chaves são divididas em índices de uma tabela de hash para que a inserção seja sempre aleatória, foi utilizado para armazenar as StopWords. Todas as operações no unordered_set levam tempo constante O(1) em uma média que pode ir até o tempo linear O(n) no pior caso, 

<h3><b>Heapify_máx</b></h3>

Especificamente, max heapify é o processo de pegar uma matriz que é representada como uma árvore binária e registrar os valores em cada nó, de modo que os nós filhos sejam menores ou iguais ao pai, satisfazendo um heap máximo. Dessa forma, conseguimos armazenas as `k` palavras mais frequentes nos textos. Heapify um único nó leva complexidade de tempo O(log N), onde N é o número total de nós. Portanto, construir todo o Heap levará N operações de heapify e a complexidade de tempo total será O(N*logN).


## 🔨 Funções 
<div align="justify">

- `init ` é responsável por iniciar o processo de processamento de um arquivo de texto, assim ela inicia abrindo o arquivo de entrada ```data/input(x).txt```, assegura-se de que a abertura tenha ocorrido sem problemas e, em seguida, aciona a função ```StopWords``` para carregar palavras que devem ser excluídas da contagem de frequência. Após essa etapa, ela procede à leitura de cada linha do arquivo de entrada e direciona cada linha para a função ```tokenizacao ```.

- ```StopWords:``` Após abrir o arquivo e verificar a abertura bem-sucedida, ela lê cada linha do arquivo e converte cada palavra em minúsculas para garantir uniformidade. As palavras processadas dessa maneira são então inseridas em uma unodered_set chamada ```unorderedStopWords```, permitindo uma rápida verificação de pertencimento durante a  função tokenização. Ao final, o arquivo é fechado.

- ```Tratamentos:``` Esta funçao realiza tratamentos especificos para caracteres especias encontrados durante os testes. Primeiramente, verifica se a palavra termina em hífen e remove-o. Em seguida, verifica se a palavra começa com hífen e, dependendo das circunstâncias, remove um ou dois hífens do início da palavra. Além disso, ela trata o caso em que as palavras possuem caracteres especiais " ” " e " “ " no final ou início, eliminando-os quando apropriado. A função também detecta se a palavra foi completamente esvaziada após essas operações de tratamento, indicando assim que a palavra não tem mais conteúdo significativo. Isso é útil para que a função de tokenização, pois esses tratamentos ajudam a normalizar as palavras, garantindo que a contagem de frequência seja precisa e livre de ruídos indesejados.

- ```Tokenizacao:``` Essa função transforma as linhas do texto em palavras individuais. Para isso, ela aplica o regex para identificar padrões de palavras, incluindo letras, números, apóstrofos, caracteres acentuados e hifens. Durante o processo, a função itera através dos resultados obtidos pelo regex e aplica a funçao ```tratamentos```. Se a palavra resultante não estiver vazia após os tratamentos, ela é convertida para minúsculas e verifica-se se não é uma ```StopWords```. Caso não seja uma, ela é contabilizada no unordered_map chamado ```wordCount```, para posteriormente calcular a frequência das palavras no texto. 

- ```topKWords:``` Desempenha um papel crucial na identificação das palavras mais frequentes no texto, usando uma abordagem baseada em heap. Ela percorre o unordered_map chamado ```wordCount```, que armazena as palavras e suas respectivas contagens de frequência. À medida que percorre esse mapa, a função insere cada par chave-valor em um vetor chamado ``vectortopKHeap``. Essa etapa inicial é acompanhada pelo gerenciamento do tamanho do vetor para garantir que ele não exceda o valor de k, que é o número desejado de palavras mais frequentes a serem encontradas. Se o tamanho do vetor `vectortopKHeap` ultrapassar o limite k, a função remove o elemento de menor contagem de frequência usando uma função lambda junto com min_element. Em seguida, a função procede a uma etapa de construção do heap máximo usando a função heapify, onde os elementos são reorganizados para que as maiores contagens de frequência ocupem as posições superiores. A última parte da função envolve a extração dos k elementos de maior valor do heap máximo.

- ```heapify:``` Ao receber um vetor de pares (cada par representando uma palavra e sua contagem de frequência) juntamente com um índice i, a função avalia os elementos nos índices correspondentes às posições dos filhos esquerdo e direito no heap. Ela determina qual desses filhos tem a maior contagem de frequência e, se essa contagem for maior do que a contagem do elemento no índice i, realiza uma troca entre esses elementos. Isso garante que o elemento na posição i seja maior do que seus filhos, mantendo a propriedade do heap máximo. A função, então, é chamada recursivamente para o filho que teve sua posição trocada, garantindo que a propriedade do heap máximo seja mantida em todas as etapas da construção e manipulação do heap.



<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/5526e951-28a0-4581-b269-52026a1bf3d1" alt="heapify max" style="width:500px;height:300px;">
</div>


- ```printTopK:``` Imprime as palavras e suas frequencias em ordem crescente.


## 🎯Resultados

<h3><b>Configurando</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/05509ca3-087b-490f-8460-3170da1e368f" width="500px" />
</div>

Configurando para ler apenas um arquivo usando a variável ```numFiles``` e a variável  ```k``` para selecionar os top 20 elementos.

<h3><b>Entrada</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/e4995ae5-f616-4b05-8822-e7c571db83ca" width="500px" />
</div>

<h3><b>Saída</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/34c50d87-5b73-44bd-9b7e-917fdf283994" width="500px" />
</div>

<h3><b>Saída com os dois textos fornecidos como testes</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/55244c4e-7955-4901-b1f8-227e098bcc5c" width="500px" />
</div>
A saída obtida é resultado da fusão das palavras mais comuns encontradas nos textos "Dom Casmurro" e "A semana Texto-fonte: Obra Completa de Machado de Assis", ambos fornecidos como entradas de teste pelo professor e presentes nos arquivos "input1.txt" e "input2.txt", localizados na pasta data deste código.

<h3><b>Tempo de execução</b></h3>


<h3><b>Custo assintotico</b></h3>


## ✔️Conclusão
Foi observado, um novo metodo mais otimizado para busca e pesquisa em textos e que podem ser tambem aplicado em diversas outras situaçoes. O heaps tendem a utilizar estruturas abstratas de dados cujas ações o permitem definir uma hierarquia em árvore dos elementos armazenados, e acessa-los de forma rápida.Além disso, consegui iniciar minha compreensão das estruturas de árvores e também apliquei no algoritmo outros conhecimentos que desenvolvi. Introduzi novas funções e estruturas que me proporcionaram abordagens mais avançadas para realizar as mesmas tarefas.

## 🚨Importante

- Antes de compilar o código, é essencial definir dois parâmetros no arquivo main.cpp localizados no início do código: o valor de k (linha 12), que representa o tamanho do heap, e o número de arquivos que serão lidos numFiles (linha 8). 

- Certifique-se de ter os textos desejados armazenados na pasta data, nomeados como input(numero do arquivo).txt, sendo que o número do arquivo deve começar a partir de 1 e incrementar sequencialmente. Na função main, escolha o número adequado de arquivos a serem lidos.

- O programa fornecerá uma única saída, apresentando as palavras mais frequentes encontradas nos arquivos especificados pelo parâmetro numFiles. Isso permitirá uma análise eficiente das palavras mais recorrentes nos textos fornecidos.


## 👾Compilação e execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Após temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## ✔️Referências
https://builtin.com/software-engineering-perspectives/heapify-heap-tree-cpp
https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
https://github.com/mpiress/HeapSort.git <br>
https://devdojo.com/algonoob/max-heap

## Contato

<div>
 <br><p align="justify"> Letícia de Oliveira Silva</p>
 <a href="https://t.me/letolsilva">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:letolsilva22@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>letolsilva22@gmail.com</i>
</a>



