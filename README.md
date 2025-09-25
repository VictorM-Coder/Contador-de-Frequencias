# Contador de Frequências de Palavras com Estruturas de Dados Avançadas

Este projeto foi desenvolvido como parte da disciplina **Estruturas de Dados Avançadas (QXD0115)** da Universidade Federal do Ceará – Campus Quixadá, sob orientação do professor **Atílio Gomes Luiz**.

O objetivo principal é implementar e comparar o desempenho de quatro estruturas de dados avançadas na contagem de frequência de palavras em textos extensos.

Os dados de execução e análises detalhadas estão disponíveis no arquivo [`EDA_Trabalho_final_relatorio.pdf`](https://github.com/VictorM-Coder/Contador-de-Frequencias/blob/master/EDA_Trabalho_final_relatorio.pdf) anexado. Este projeto é destinado para fins acadêmicos.

## 📋 Descrição do Projeto

O programa lê um arquivo de texto (.txt), processa seu conteúdo ignorando pontuações (exceto hífens em palavras compostas), converte todo o texto para minúsculas e conta a frequência de cada palavra utilizando uma das seguintes estruturas:

- **Árvore AVL**
- **Árvore Rubro-Negra**
- **Tabela Hash com Encadeamento Externo**
- **Tabela Hash com Endereçamento Aberto**

Além de gerar a lista de palavras e suas frequências (em ordem alfabética, no caso das árvores), o projeto também coleta métricas de desempenho:

- Tempo de execução
- Número de comparações de chaves
- Número de rotações (árvores)
- Número de colisões (tabelas hash)


## 🧠 Objetivos

- Implementar estruturas de dados genéricas e reutilizáveis em C++ usando templates.
- Comparar a eficiência das estruturas com base em métricas de tempo e operações.
- Processar textos grandes de forma eficiente, tratando entrada e saída de arquivos.
- Fornecer uma interface via linha de comando para facilitar a execução e testes.


## 🧩 Estrutura do Projeto

```
src/
├── structures/          # Implementações das estruturas de dados
│   ├── avl_tree.hpp
│   ├── rb_tree.hpp
│   ├── chained_hash_table.hpp
│   └── open_hash_table.hpp
├── utils/               # Utilitários (leitura de arquivo, processamento de texto)
├── dictionary.hpp       # Classe wrapper para usar qualquer estrutura
└── main.cpp            # Programa principal
```


## 🚀 Como Compilar e Executar

### Pré-requisitos
- Compilador C++ com suporte a C++17 (g++ ou clang++)
- CMake (versão 3.28 ou superior)
- Biblioteca ICU (Unicode)

No Debian/Ubuntu:
```bash
sudo apt install build-essential cmake pkg-config libicu-dev
```

### Compilação
```bash
mkdir build
cd build
cmake ..
make
```

### Uso
```bash
./TRABALHO_FINAL <estrutura> <arquivo_entrada> <arquivo_saída>
```

#### Exemplo
```bash
./TRABALHO_FINAL dictionary_avl biblia.txt saida_avl.txt
```

#### Estruturas válidas:
- `dictionary_avl`
- `dictionary_rb`
- `dictionary_cht` (Chained Hash Table)
- `dictionary_oht` (Open Hash Table)


## 📊 Conclusões Gerais

Com base na análise dos resultados obtidos com os seis textos utilizados (incluindo a Bíblia e obras literárias), foram observados os seguintes comportamentos:

- **Árvore AVL**: Apresentou um número elevado de comparações, especialmente em textos longos, devido ao balanceamento rigoroso que exige verificações contínuas durante as inserções.

- **Árvore Rubro-Negra**: Demonstrou desempenho superior em tempo de execução e número de comparações em relação à AVL, graças ao balanceamento mais "relaxado" característico desta estrutura.

- **Tabela Hash com Encadeamento Externo**: Mostrou números significativamente baixos de comparações em textos menores, mas em obras extensas como a Bíblia, o número de colisões aumenta consideravelmente, exigindo percorrer listas encadeadas nos *buckets*.

- **Tabela Hash com Endereçamento Aberto**: Obteve o melhor desempenho em tempo de execução entre todas as estruturas, destacando a importância do uso de um fator de carga baixo (0,5) e da técnica de *double hashing* para melhor espalhamento.

> Consulte o [`EDA_Trabalho_final_relatorio.pdf`](https://github.com/VictorM-Coder/Contador-de-Frequencias/blob/master/EDA_Trabalho_final_relatorio.pdf) para gráficos, tabelas detalhadas e análise aprofundada.
