#ifndef TOPKELEMENTOS_HPP
#define TOPKELEMENTOS_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>


class topKItems {
public:
    void init(const std::string& filename); 
    void printTopK(int k);
    void topKWords(int k);


private:
    std::unordered_map<std::string, int> wordCount;
    std::unordered_set<std::string> unoderedStopWords;
    std::vector<std::pair<std::string, int>> vectortopKHeap; 
    //std::vector<std::pair<std::string, int>> itemsVector;
    // std::vector<std::string> sentences;
    // std::vector<std::string> paragraphs;

    void tokenizacao(const std::string& line);
    void StopWords(const std::string& stopWordsFilename);
    void heapify(std::vector<std::pair<std::string, int>>& arr, int n, int subtree_root_index);
    void tratamentos(std::string& word, bool& stringVazia);

};

#endif