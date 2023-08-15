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

O propósito deste projeto é construir uma tabela de dispersão (hash) para registrar a frequência de cada elemento tokenizado na coleção de dados de entrada. Além disso, visa-se criar uma árvore (heap) com capacidade para k elementos mais frequentes no texto.

<strong><h4>Condições impostas: </h4></strong>
- Inicialmente, este código realiza a leitura de um arquivo de entrada denominado ```data/input(x).txt```. O arquivo contém o texto que será submetido à análise. No contexto, o valor de x é o valor de uma variável ajustável no início do arquivo ```main```, denominada numFiles. Por exemplo, se houver a necessidade de processar dois arquivos de entrada, os nomes dos arquivos seriam data/input1.txt e data/input2.txt, e assim sucessivamente, de acordo com a quantidade de arquivos definida na variável numFiles. Lembrando que ```data``` é a pasta criada para os arquivos de entrada.
- As sentenças são definidas pelos sinais de pontuação (".", "?", "!").
- Cada parágrafo é separado por uma linha em branco.
- Existe um arquivo de ```stop words``` para análise. Sendo as stop words artigos e conjunções que podem ser alteradas de acordo com a preferência do usuário. As palavras presentes neste arquivo serão desconsideradas da contagem das top k palavras.
- Ao término da execução, a estrutura de heap conterá os k elementos com os maiores valores (frequências) na coleção de dados. Posteriormente, esses elementos são impressos na ordem que se encontram no heap.
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

`std:unordered_map` é um contêiner associativo que contém pares chave-valor com chaves exclusivas. Pesquisa, inserção e remoção de elementos têm complexidade de tempo constante média. Internamente, os elementos não são classificados em nenhuma ordem específica, mas organizados em baldes. Em qual balde um elemento é colocado depende inteiramente do hash de sua chave. Chaves com o mesmo código hash aparecem no mesmo bucket. Isso permite acesso rápido a elementos individuais, pois uma vez que o hash é calculado, ele se refere ao balde exato em que o elemento é colocado.

Neste código emprega se uma tabela de hash para armazenar as palavras e suas frequencias, resultando em inserções e buscas rápidas com complexidade média de O(1). Isso é benéfico quando é crucial, pois torna possível utilizar palavras como chaves para contabilizar suas frequências e acessa-las para obter as top K elementos.

<h3><b>Unodered_set</b></h3>

`std::unordered_set` é um contêiner associativo que contém um conjunto de objetos exclusivos do tipo Key. Pesquisa, inserção e remoção têm complexidade de tempo constante média. Internamente, os elementos não são classificados em nenhuma ordem específica, mas organizados em baldes. Em qual balde um elemento é colocado depende inteiramente do hash de seu valor. Isso permite acesso rápido a elementos individuais, pois uma vez que um hash é calculado, ele se refere ao balde exato em que o elemento é colocado.

Os elementos do contêiner não podem ser modificados (mesmo por não const iteradores), pois a modificação pode alterar o hash de um elemento e corromper o contêiner. Portanto, optou-se por armazenar as stopWords, que foram carregadas de um arquivo de texto. Essa abordagem permite uma comparação otimizada para determinar se palavras são stopwords ou não. Isso se deve ao fato de que todas as operações no unordered_set têm uma complexidade de tempo constante em média (O(1)), embora em casos extremos possam chegar a uma complexidade de tempo linear (O(n)).

<h3><b>Heapify_min</b></h3>

`Heapify` é um método de converter um conjunto de valores em um heap. A lógica por trás do algoritmo heapify determinará em que tipo de heap o conjunto de valores se tornará.

Neste algoritmo foi utilizado o heapify_min, que é uma Árvore Binária Completa contendo o menor valor no nó raiz, seguido por valores maiores no próximo nível, seguido por valores ainda maiores no próximo nível e assim por diante. Assim, o último nível desta árvore binária deve conter os maiores valores presentes no array de valores que estamos inserindo. Neste código, um heap é utilizado para armazenar palavras e suas frequências dos K maiores elementos dos textos lidos. No entanto, é importante observar que, entre esses K maiores elementos, o menor deles é mantido no nó raiz. 
Imagine que o vetor contém as maiores frequências encontradas, o heap fica assim:
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/de15ef20-39f3-4be0-8364-93eb9306bb63" width="500px" />
</div>
É possível acessar os filhos esquerdo e direito de um nó através das fórmulas 2 * i + 1 e 2 * i + 2, respectivamente.<br>
Obs: i recebeu o nome de subtree_root_index neste código.

Heapify um único nó leva complexidade de tempo O(log N), onde N é o número total de nós. Portanto, construir todo o Heap levará N operações de heapify e a complexidade de tempo total será O(N*logN).

<h3><b>Regex</b></h3>

Uma `expressão regular`, também conhecida como regex, é uma sequência de caracteres que define um padrão de busca específico. Isso pode ser usado em algoritmos de pesquisa de strings, localização ou substituição, entre outros. As regex também são empregadas para validar entradas.

O `std::regex_iterator` é um iterador somente leitura que permite acessar correspondências individuais de uma expressão regular dentro de uma sequência de caracteres. O iterador é construído com base no padrão da expressão regular. Quando um std::regex_iterator válido é incrementado após ter alcançado a última correspondência (quando std::regex_search retorna falso), ele se torna igual ao iterador de fim de sequência. No entanto, ao desreferenciar ou incrementar ainda mais esse iterador, ocorre um comportamento indefinido.


## 🔨 Funções 
<div align="justify">

- `init ` é responsável por iniciar o processo de processamento de um arquivo de texto, assim ela inicia abrindo o arquivo de entrada ```data/input(x).txt```, assegura-se de que a abertura tenha ocorrido sem problemas e, em seguida, aciona a função ```StopWords``` para carregar palavras que devem ser excluídas da contagem de frequência. Após essa etapa, ela procede à leitura de cada linha do arquivo de entrada e direciona cada linha para a função ```tokenizacao ```.

- ```StopWords:``` Após abrir o arquivo e verificar a abertura bem-sucedida, ela lê cada linha do arquivo e converte cada palavra em minúsculas para garantir uniformidade. As palavras processadas dessa maneira são então inseridas em uma unodered_set chamada ```unorderedStopWords```, permitindo uma rápida verificação de pertencimento durante a  função tokenização. Ao final, o arquivo é fechado.

- ```Tratamentos:``` Esta funçao realiza tratamentos especificos para caracteres especias encontrados durante os testes. Primeiramente, verifica se a palavra termina em hífen e remove-o. Em seguida, verifica se a palavra começa com hífen e, dependendo das circunstâncias, remove um ou dois hífens do início da palavra. Além disso, ela trata o caso em que as palavras possuem caracteres especiais " ” " e " “ " no final ou início, eliminando-os quando apropriado. A função também detecta se a palavra foi completamente esvaziada após essas operações de tratamento, indicando assim que a palavra não tem mais conteúdo significativo. Isso é útil para que a função de tokenização, pois esses tratamentos ajudam a normalizar as palavras, garantindo que a contagem de frequência seja precisa e livre de ruídos indesejados.

- ```Tokenizacao:``` Essa função transforma as linhas do texto em palavras individuais. Para isso, ela aplica o regex para identificar padrões de palavras, incluindo letras, números, apóstrofos, caracteres acentuados e hifens. Durante o processo, a função itera através dos resultados obtidos pelo regex e aplica a funçao ```tratamentos```. Se a palavra resultante não estiver vazia após os tratamentos, ela é convertida para minúsculas e verifica-se se não é uma ```StopWords```. Caso não seja uma, ela é contabilizada no unordered_map chamado ```wordCount```, para posteriormente calcular a frequência das palavras no texto. 

- ```topKWords:``` A função desempenha um papel central na identificação das palavras mais frequentes no texto, usando uma abordagem baseada em heap. Durante a iteração pelo mapa não ordenado chamado `wordCount`, que mantém as palavras e suas contagens, essa função constrói um heap. O objetivo é armazenar os "k" elementos com as maiores contagens. A cada iteração, ela verifica se um novo elemento tem uma contagem maior do que o elemento de menor contagem no heap, e, se essa condição for verdadeira, substitui o elemento mínimo e, em seguida, reorganiza o heap para manter a propriedade de heap. Ao final do processamento, o heap é montado de forma inicial, contendo os "k" elementos de maior contagem, permitindo identificar eficientemente as palavras mais frequentes no texto.

- ```heapify:``` Ela recebe como entrada um vetor de pares representando palavras e suas contagens, o tamanho do heap (n) e o índice da raiz da subárvore sendo analisada. A função compara as contagens dos elementos presentes no índice da raiz e seus filhos esquerdo e direito, identificando o menor entre eles. Se o menor não for a raiz da subárvore, a função troca os elementos e chama recursivamente heapify na subárvore afetada, assegurando que a hierarquia e a propriedade de heap mínima sejam mantidas em toda a estrutura. 

- ```printTopK:``` Imprime as palavras e suas frequências na ordem que esta no heap.


## 🎯Resultados

<h3><b>Configurando</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/208e52e6-f803-4895-a435-490c49f9fe97" width="500px" />
</div>

Configurando para ler apenas um arquivo usando a variável ```numFiles``` e a variável  ```k``` para selecionar os top 20 elementos, no arquivo `main.cpp`.

<h3><b>Entrada</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/Labirinto-Recorrente/assets/109817570/e4995ae5-f616-4b05-8822-e7c571db83ca" width="500px" />
</div>

<h3><b>Saída</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/b27e321f-c84b-4907-9d3d-816240d57293" width="500px" />
</div>

<h3><b>Saída com os dois textos fornecidos como testes</b></h3>
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/61cad8ff-77ca-4b37-9b3c-0e6a06edfd84" width="500px" />
</div>
A saída obtida é resultado da fusão das palavras mais comuns encontradas nos textos "Dom Casmurro" e "A semana Texto-fonte: Obra Completa de Machado de Assis", ambos fornecidos como entradas de teste pelo professor e presentes nos arquivos "input1.txt" e "input2.txt", localizados na pasta data deste código.<br>

Pode-se confirmar que as sáidas estão corretas analisando os filhos esquerdos e direitos, com 2 * i + 1 e 2 * i + 2.<br>
Obs: Novamente i recebeu o nome de subtree_root_index neste codigo.


<h3><b>Tempo de execução</b></h3>
O código foi executado em um notebook Acer Nitro 5 com processador Ryzen 7.
<div align="center">
<img src="https://github.com/Letolsilva/AEDS---Caminho-guloso/assets/109817570/5bc326ce-66a9-4398-a6f3-d6345201b159" width="200px" />
</div>


## ✔️Conclusão
Foi observado, um novo metodo mais otimizado para busca e pesquisa em textos e que podem ser tambem aplicado em diversas outras situações. Entender sobre o heap que tende a utilizar estruturas abstratas de dados cujas ações o permitem definir uma hierarquia em árvore dos elementos armazenados, e acessa-los de forma rápida. Além disso, consegui iniciar minha compreensão das estruturas de árvores e também apliquei no algoritmo outros conhecimentos que desenvolvi. Introduzi novas funções e estruturas que me proporcionaram abordagens mais avançadas para realizar as mesmas tarefas.

## 🚨Importante

- Antes de compilar o código, é essencial definir dois parâmetros no arquivo main.cpp localizados no início do código: o valor de `k` (linha 12), que representa o tamanho do heap, e o número de arquivos que serão lidos numFiles (linha 8). 

- Certifique-se de ter os textos desejados armazenados na pasta data, nomeados como input(numero do arquivo).txt, sendo que o número do arquivo deve começar a partir de 1 e incrementar sequencialmente. Na pasta main, escolha o número adequado de arquivos a serem lidos.

- O programa fornecerá uma única saída, apresentando as palavras mais frequentes encontradas nos arquivos especificados pelo parâmetro numFiles. Isso permitirá uma análise eficiente das palavras mais recorrentes nos textos fornecidos.


## 👾Compilação e execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Após temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## ✔️Referências
https://builtin.com/software-engineering-perspectives/heapify-heap-tree-cpp <br>
https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/ <br>
https://github.com/mpiress/HeapSort.git <br>
https://devdojo.com/algonoob/max-heap <br>

## Contato

<div>
 <br><p align="justify"> Letícia de Oliveira Silva</p>
 <a href="https://t.me/letolsilva">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:letolsilva22@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>letolsilva22@gmail.com</i>
</a>



