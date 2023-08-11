#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "text_processor.hpp"

const int numFiles = 2; 

int main() {
    TextProcessor processor;
    int k = 20;

    for (int i = 1; i <= numFiles; ++i) {
        std::string filename = "data/input" + std::to_string(i) + ".txt";
        std::ifstream outputFile(filename);

        if (!outputFile) {
            std::cerr << "Erro ao criar o arquivo: " << filename << std::endl;
            return 1;
        }
       processor.init(filename);
    }
    processor.topKWords(k);
    processor.printTopK(k);

    return 0;
}
