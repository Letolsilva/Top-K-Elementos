#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "topKElementos.hpp"
int numFiles = 2; //Escolha a quantidade de arquivos de entrada

int main() {
    topKItems processor;
    int k = 20; //Escolha o valor de K
    auto start = std::chrono::high_resolution_clock::now();

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
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Tempo de execucao: " << duration.count() << " ms" << std::endl;

    return 0;
}
