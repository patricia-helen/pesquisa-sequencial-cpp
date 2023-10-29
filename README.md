# Projeto de Pesquisa Sequencial em C++

Este é um projeto de demonstração de pesquisa sequencial em C++ que inclui a geração de arquivos de dados aleatórios, pesquisa sequencial em arquivos e um exemplo de saída. O projeto foi desenvolvido como parte da matéria de Algoritmos e Estruturas de Dados III.

## Instruções de Uso

Para usar este projeto, siga as etapas abaixo:

1. Clone o repositório em seu diretório local usando o comando:

    ```bash
    git clone https://github.com/patricia-helen/pesquisa-sequencial-cpp
    ```

## Trabalho de Pesquisa Sequencial

Este é um projeto de exemplo para demonstrar a pesquisa sequencial em um conjunto de registros usando C++. O projeto cria arquivos de entrada contendo dados aleatórios desordenados e ordenados em vários tamanhos e realiza pesquisas sequenciais nesses arquivos. Os resultados das pesquisas são registrados em arquivos de saída.

## Objetivo

O objetivo deste projeto é demonstrar o funcionamento da pesquisa sequencial e medir o desempenho das pesquisas em diferentes tamanhos de dados desordenados e ordenados.

## Pré-requisitos

- Compilador C++ (ex: g++)
- Ambiente Linux (ou outro sistema operacional compatível com a biblioteca \<filesystem>)
- Git (para clonar o repositório)

## Instruções

Siga as instruções abaixo para executar o projeto em seu ambiente:

1. Clone o repositório para sua máquina local:

    ```bash
    git clone https://github.com/patricia-helen/pesquisa-sequencial-cpp
    ```

2. Acesse o diretório do projeto:

    ```bash
    cd pesquisa-sequencial-cpp
    ```

3. Compile o código-fonte:

    ```bash
    g++ -o pesquisa_sequencial pesquisa_sequencial.cpp
    ```

4. Execute o programa:

    ```bash
    ./pesquisa_sequencial
    ```

Após a execução, você encontrará os resultados da pesquisa sequencial em arquivos na pasta "Arquivos Saida". Os resultados são formatados da seguinte maneira:

```yaml
Resultados da pesquisa sequencial para arquivos Desordenados de tamanho 100:
Chave (000003) não encontrada na árvore. Tempo de busca: 0.000000100 segundos. Interações: 1
Chave (000030) encontrada na árvore. Tempo de busca: 0.000000110 segundos. Interações: 2
Chave (000062) encontrada na árvore. Tempo de busca: 0.000000130 segundos. Interações: 3
...
Total de comparações em 10 pesquisas: 45

## Estrutura do Projeto

A estrutura do projeto inclui os seguintes arquivos e pastas:

- `pesquisa_sequencial.cpp`: O código-fonte principal que realiza a pesquisa sequencial.
- `Arquivos de Entrada/`: Pasta onde os arquivos de dados desordenados e ordenados são criados.
- `Arquivos Saida/`: Pasta onde os resultados das pesquisas sequenciais são armazenados.

## Autores

- Daniel Rodrigues
- Patricia Helen
- Fernando Maia
- Osiel Junior
- Raul Rodrigues




 
