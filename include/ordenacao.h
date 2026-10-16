#ifndef ORDENACAO_H
#define ORDENACAO_H

enum Algoritmo { ALG_INSERTION = 0, ALG_MERGE = 1, ALG_QUICK = 2 };

struct ContOrd {
  long long comparacoes;
};

// true se o item a deve vir antes do item b: chave maior primeiro; empate pelo menor id
inline bool vemAntes(int a, int b, const long long* chave, ContOrd& c) {
  c.comparacoes++;
  return chave[a] > chave[b] || (chave[a] == chave[b] && a < b);
}

void insertionSort(int* ordem, int n, const long long* chave, ContOrd& c);
void mergeSort(int* ordem, int n, const long long* chave, int* aux, ContOrd& c);
void quickSort(int* ordem, int n, const long long* chave, ContOrd& c);

void ordena(Algoritmo alg, int* ordem, int n, const long long* chave, int* aux, ContOrd& c);

#endif
