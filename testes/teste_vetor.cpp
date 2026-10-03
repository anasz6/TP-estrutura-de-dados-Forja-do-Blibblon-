#include <cstdio>
#include "vetor_dinamico.h"

#define CHECA(cond) do { if (!(cond)) { printf("FALHOU linha %d: %s\n", __LINE__, #cond); return 1; } } while (0)

int main() {
  VetorDinamico<int> v;
  CHECA(v.tamanho() == 0);

  for (int i = 0; i < 1000; i++) v.adiciona(i);
  CHECA(v.tamanho() == 1000);
  for (int i = 0; i < 1000; i++) CHECA(v[i] == i);

  v.insereEm(0, -1);              // no começo
  CHECA(v.tamanho() == 1001 && v[0] == -1 && v[1] == 0);
  v.insereEm(500, 777);           // no meio
  CHECA(v[500] == 777 && v[501] == 499);
  v.insereEm(v.tamanho(), 42);    // no fim
  CHECA(v[v.tamanho() - 1] == 42);

  v.removeEm(500);
  CHECA(v[500] == 499);
  v.removeEm(0);
  CHECA(v[0] == 0);

  v.limpa();
  CHECA(v.tamanho() == 0);
  v.adiciona(5);
  CHECA(v.tamanho() == 1 && v[0] == 5);

  VetorDinamico<int> w;
  w.redimensiona(10, 0);
  CHECA(w.tamanho() == 10 && w[9] == 0);
  w.redimensiona(100, 7);
  CHECA(w.tamanho() == 100 && w[9] == 0 && w[10] == 7 && w[99] == 7);
  w.redimensiona(2, 0);
  CHECA(w.tamanho() == 2);

  CHECA(v.bytesReservados() > 0);

  printf("OK: teste_vetor\n");
  return 0;
}
