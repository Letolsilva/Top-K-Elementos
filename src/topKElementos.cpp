#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "topKElementos.hpp"
#include <queue>
#include <algorithm>

void topKItems::init(const std::string &filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::string line;
    StopWords("stopwords.txt");

    while (std::getline(inputFile, line))
    {
        tokenizacao(line);
    }
    // std::cout << "Frequencia das palavras:\n";
    // for (const auto &entry : wordCount)
    // {
    //     std::cout << entry.first << ": " << entry.second << std::endl;
    // }
     inputFile.close();
}

void topKItems::StopWords(const std::string &stopWordsFilename)
{
    std::string fullPath = "data/" + stopWordsFilename;
    std::ifstream stopWordsFile(fullPath);
    if (!stopWordsFile)
    {
        std::cerr << "Erro ao abrir o arquivo de stop words: " << stopWordsFilename << std::endl;
        return;
    }

    std::string stopWord;
    while (std::getline(stopWordsFile, stopWord))
    {
        for (char &c : stopWord)
        {
            c = tolower(c);
        }
        unoderedStopWords.insert(stopWord);
    }
     stopWordsFile.close();
}
void topKItems::tratamentos(std::string &word, bool &stringVazia)
{
    if (!word.empty() && word.back() == '-')
    {
        word.pop_back();
    }

    if (!word.empty() && word.front() == '-')
    {
        if (word.length() >= 2 && word.substr(0, 2) == "--")
        {
            word.erase(0, 2);
        }
        else
        {
            word.erase(0, 1);
        }
    }

    if (word.length() >= 3 && word.substr(word.length() - 3) == "”")
    {
        word.erase(word.length() - 3);
    }

    if (word.length() >= 3 && word.substr(0, 3) == "“")
    {
        word.erase(0, 3);
    }
    if(word.empty()){
        stringVazia=true;
    }
}
void topKItems::tokenizacao(const std::string &line)
{
    std::string word;
    std::regex wordRegex("[a-zA-Z0-9'À-Ÿ\\-“”]+");
    std::sregex_iterator iterador(line.begin(), line.end(), wordRegex);
    std::sregex_iterator fim;

    while (iterador != fim)
    {
        word = iterador->str();
        bool stringVazia = false;
        tratamentos(word,stringVazia);
        if (stringVazia == false)
        {
            for (char &c : word)
            {
                c = tolower(c);
            }
            if (unoderedStopWords.find(word) == unoderedStopWords.end())
            {
                wordCount[word]++;
            }
        }
        ++iterador;
    }
    wordCount.erase("-");
    wordCount.erase("—");
}

void topKItems::topKWords(int k)
{
    int topKHeapSize = 0; 

    for (const auto &entry : wordCount)
    {
        vectortopKHeap.push_back(entry);
        topKHeapSize++;

        if (topKHeapSize > k) 
        {
            vectortopKHeap.erase(std::min_element(vectortopKHeap.begin(), vectortopKHeap.end(), [](const auto &a, const auto &b)
                                                  { return a.second < b.second; }));
            topKHeapSize--;
        }
    }
    if (topKHeapSize < k)
    {
        k = topKHeapSize;
    }

    for (int i = k / 2 - 1; i >= 0; --i)
    {
        heapify(vectortopKHeap, k, i);
    }

    // for (int i = 0; i < k; ++i)
    // {
    //     std::swap(vectortopKHeap.front(), vectortopKHeap[k - i - 1]);
    //     heapify(vectortopKHeap, k - i - 1, 0);
    // }
}

void topKItems::printTopK(int k)
{
    std::cout << "\nTop " << k << " maiores valores encontrados na hash (frequências) e suas respectivas palavras em ordem crescente:\n";
    int aux = vectortopKHeap.size();
    for (int i = 0; i < aux; ++i)
    {
        std::cout << vectortopKHeap[i].first << ": " << vectortopKHeap[i].second << std::endl;
    }
}

void topKItems::heapify(std::vector<std::pair<std::string, int>> &vectorAux, int n, int i)
{
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n && vectorAux[left_child].second > vectorAux[largest].second)
    {
        largest = left_child;
    }

    if (right_child < n && vectorAux[right_child].second > vectorAux[largest].second)
    {
        largest = right_child;
    }

    if (largest != i)
    {
        std::swap(vectorAux[i], vectorAux[largest]);
        heapify(vectorAux, n, largest);
    }
}