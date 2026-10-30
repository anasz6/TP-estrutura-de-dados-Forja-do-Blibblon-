# A Forja do Blibblon

Trabalho prático 1 de **Estruturas de Dados (DCC221)**, UFMG. Um jogo ambientado em uma forja, usado para praticar a construção e a manipulação de estruturas de dados e de algoritmos clássicos, tudo em **C++11 e sem usar a STL**.

## O que está implementado

- **Vetor dinâmico** (`vetor_dinamico.h`), com crescimento automático.
- **Fila** e **pilha**, implementadas do zero.
- **Matriz esparsa**, em duas versões:
  - vetor de tripletas (modo `T`);
  - lista cruzada (modo `L`).
- **Algoritmos de ordenação** (`src/ordenacao.cpp`): Quick Sort, Bubble Sort, etc. (ajuste conforme o que você implementou).
- **Métricas** (`src/metricas.cpp`) para comparar o desempenho das implementações.
- Entidades do jogo: atributos, itens, aventureiros, catálogo e a própria forja.

## Estrutura do projeto

```
include/   cabeçalhos (.h)
src/       implementações (.cpp) e main.cpp
testes/    testes unitários e exemplo de entrada/saída
Makefile
```

## Como compilar e executar

Requisitos: `g++` com suporte a C++11 e `make`.

```
make
./bin/tp1.out < testes/exemplo1.in
```

Para limpar os arquivos gerados:

```
make clean
```

## Testes

Os testes de cada estrutura (vetor, fila, pilha e entidades) ficam em `testes/`. O script `testes/rodar.sh` roda os casos de exemplo.

## Autoria

Ana Soza
