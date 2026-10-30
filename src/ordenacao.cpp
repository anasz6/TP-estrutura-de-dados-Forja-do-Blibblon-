#include "ordenacao.h"

void insertionSort(int* ordem, int n, const long long* chave, ContOrd& c) {
  for (int i = 1; i < n; i++) {
    int pivo = ordem[i];
    int j = i - 1;
    while (j >= 0 && vemAntes(pivo, ordem[j], chave, c)) {
      ordem[j + 1] = ordem[j];
      j--;
    }
    ordem[j + 1] = pivo;
  }
}

static void merge(int* ordem, int esq, int meio, int dir, const long long* chave, int* aux, ContOrd& c) {
  int i = esq;
  int j = meio + 1;
  int k = esq;

  while (i <= meio && j <= dir) {
    if (vemAntes(ordem[i], ordem[j], chave, c)) {
      aux[k++] = ordem[i++];
    } else {
      aux[k++] = ordem[j++];
    }
  }

  while (i <= meio) {
    aux[k++] = ordem[i++];
  }
  while (j <= dir) {
    aux[k++] = ordem[j++];
  }

  for (int p = esq; p <= dir; p++) {
    ordem[p] = aux[p];
  }
}

static void mergeSortRec(int* ordem, int esq, int dir, const long long* chave, int* aux, ContOrd& c) {
  if (esq >= dir) return;
  int meio = esq + (dir - esq) / 2;
  mergeSortRec(ordem, esq, meio, chave, aux, c);
  mergeSortRec(ordem, meio + 1, dir, chave, aux, c);
  merge(ordem, esq, meio, dir, chave, aux, c);
}

void mergeSort(int* ordem, int n, const long long* chave, int* aux, ContOrd& c) {
  if (n <= 1) return;
  mergeSortRec(ordem, 0, n - 1, chave, aux, c);
}

static void troca(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

static void quickSortRec(int* ordem, int esq, int dir, const long long* chave, ContOrd& c) {
  if (esq >= dir) return;
  int pivo = ordem[(esq + dir) / 2];
  int i = esq;
  int j = dir;

  while (i <= j) {
    while (vemAntes(ordem[i], pivo, chave, c)) i++;
    while (vemAntes(pivo, ordem[j], chave, c)) j--;
    if (i <= j) {
      troca(ordem[i], ordem[j]);
      i++;
      j--;
    }
  }

  if (esq < j) quickSortRec(ordem, esq, j, chave, c);
  if (i < dir) quickSortRec(ordem, i, dir, chave, c);
}

void quickSort(int* ordem, int n, const long long* chave, ContOrd& c) {
  if (n <= 1) return;
  quickSortRec(ordem, 0, n - 1, chave, c);
}

void ordena(Algoritmo alg, int* ordem, int n, const long long* chave, int* aux, ContOrd& c) {
  if (alg == ALG_INSERTION) {
    insertionSort(ordem, n, chave, c);
  } else if (alg == ALG_MERGE) {
    mergeSort(ordem, n, chave, aux, c);
  } else {
    quickSort(ordem, n, chave, c);
  }
}

