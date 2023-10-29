#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <filesystem>
using namespace std;

namespace fs = std::filesystem;

struct Tiporeg {
    int chave;
    int dado1;
    char dado2[1000];
};

// Função para gerar um registro aleatório
Tiporeg gerarRegistroAleatorio(int chave) {
    Tiporeg registro;
    registro.chave = chave;
    registro.dado1 = rand(); // Gera um valor inteiro aleatório
    for (int i = 0; i < 999; ++i) {
        registro.dado2[i] = 'A' + (rand() % 26); // Gera um caractere aleatório de 'A' a 'Z'
    }
    registro.dado2[999] = '\0'; // Termina a cadeia de caracteres
    return registro;
}

// Função para realizar pesquisa sequencial em um vetor de registros
bool pesquisaSequencial(Tiporeg registros[], int tamanho, int chaveBusca, int &comparacoes) {
    for (int i = 0; i < tamanho; ++i) {
        comparacoes++;
        if (registros[i].chave == chaveBusca) {
            return true;
        }
    }
    return false;
}

// Função para criar e salvar registros aleatórios em um arquivo
void criarArquivoDadosAleatorios(int tamanho, bool ordenado) {
    string tipo = ordenado ? "Ordenados" : "Desordenados";
    string nomeArquivo = "Arquivos de Entrada/dados" + tipo + to_string(tamanho) + ".txt";
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        Tiporeg *registros = new Tiporeg[tamanho];
        for (int i = 0; i < tamanho; ++i) {
            registros[i] = gerarRegistroAleatorio(i);
        }

        if (ordenado) {
            // Ordena os registros com base nas chaves
            for (int i = 0; i < tamanho - 1; ++i) {
                for (int j = i + 1; j < tamanho; ++j) {
                    if (registros[i].chave > registros[j].chave) {
                        swap(registros[i], registros[j]);
                    }
                }
            }
        }

        for (int i = 0; i < tamanho; ++i) {
            arquivo << registros[i].chave << ";" << registros[i].dado1 << ";" << registros[i].dado2 << "\n";
        }

        arquivo.close();
        delete[] registros;

        cout << "Arquivo de dados " << tipo << " criado: " << nomeArquivo << endl;
    } else {
        cerr << "Erro ao criar o arquivo de dados " << tipo << "." << endl;
    }
}

// Função para realizar pesquisa sequencial e salvar resultados em arquivo de saída
void pesquisaSequencialESaida(int tamanho, const string &tipo) {
    string nomeArquivoDesordenado = "Arquivos de Entrada/dadosDesordenados" + to_string(tamanho) + ".txt";
    Tiporeg registros[tamanho];
    ifstream arquivo(nomeArquivoDesordenado);

    if (arquivo.is_open()) {
        for (int j = 0; j < tamanho; ++j) {
            string linha;
            if (getline(arquivo, linha)) {
                // Converte a linha do arquivo para a estrutura Tiporeg
                size_t pos = linha.find(";");
                if (pos != string::npos) {
                    registros[j].chave = stoi(linha.substr(0, pos));
                    registros[j].dado1 = stoi(linha.substr(pos + 1));
                    // Você pode implementar o processamento de dado2, se necessário
                }
            }
        }
        arquivo.close();

        // Realize pesquisas sequenciais em chaves aleatórias
        const int numBuscas = 10; // Altere para o número desejado de pesquisas

        string nomeArquivoSaida = "Arquivos Saida/saida" + tipo + to_string(tamanho) + ".txt";
        ofstream saida(nomeArquivoSaida);

        if (saida.is_open()) {
            saida << "Resultados da pesquisa sequencial para arquivos " << tipo << " de tamanho " << tamanho << ":\n";
            int comparacoesTotal = 0;

            for (int j = 0; j < numBuscas; ++j) {
                int chaveBusca = rand() % tamanho; // Gera uma chave aleatória
                int comparacoes = 0;

                auto start_time = chrono::high_resolution_clock::now();
                bool encontrada = pesquisaSequencial(registros, tamanho, chaveBusca, comparacoes);
                auto end_time = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_time = end_time - start_time;

                comparacoesTotal += comparacoes;

                saida << "Chave (" << setw(6) << setfill('0') << chaveBusca << ") " << (encontrada ? "encontrada" : "não encontrada") << " na árvore. Tempo de busca: " << scientific << setprecision(9) << elapsed_time.count() << " segundos. Interações: " << comparacoes << "\n";
            }

            saida << "Total de comparações em " << numBuscas << " pesquisas: " << comparacoesTotal << "\n";
            saida.close();
            cout << "Arquivo de saída criado: " << nomeArquivoSaida << endl;
        } else {
            cerr << "Erro ao criar o arquivo de saída." << endl;
        }
    } else {
        cerr << "Erro ao abrir o arquivo de dados desordenados." << endl;
    }
}

int main() {
    // Crie a pasta "Arquivos de Entrada" se ela não existir
    fs::create_directory("Arquivos de Entrada");
    // Crie a pasta "Arquivos Saida" se ela não existir
    fs::create_directory("Arquivos Saida");

    // Inicializa o gerador de números aleatórios com uma semente baseada no tempo atual
    srand(static_cast<unsigned>(time(0)));

    const int tamanhos[] = {100, 500, 1000, 10000}; // Tamanhos dos arquivos
    const int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    // Crie arquivos de dados desordenados
    for (int i = 0; i < numTamanhos; i++) {
        criarArquivoDadosAleatorios(tamanhos[i], false);
    }

    // Crie arquivos de dados ordenados
    for (int i = 0; i < numTamanhos; i++) {
        criarArquivoDadosAleatorios(tamanhos[i], true);
    }

    // Realize pesquisa sequencial e salve os resultados em arquivos de saída
    for (int i = 0; i < numTamanhos; i++) {
        pesquisaSequencialESaida(tamanhos[i], "Desordenados");
        pesquisaSequencialESaida(tamanhos[i], "Ordenados");
    }

    return 0;
}
