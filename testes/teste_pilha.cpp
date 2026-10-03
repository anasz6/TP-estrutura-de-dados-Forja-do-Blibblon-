#include <cstdio>
#include "pilha.h"

#define CHECA(cond) do { if (!(cond)) { printf("FALHOU linha %d: %s\n", __LINE__, #cond); return 1; } } while (0)

int main() {
  Pilha p;
  int x = 100;

  // pilha vazia
  CHECA(p.vazia());
  CHECA(p.tamanho() == 0);
  CHECA(!p.desempilha(x));
  CHECA(x == 100);              // x não pode ser alterado
  CHECA(!p.topo(x));
  CHECA(x == 100);

  // ordem LIFO
  p.empilha(1);
  p.empilha(2);
  p.empilha(3);
  CHECA(!p.vazia());
  CHECA(p.tamanho() == 3);
  CHECA(p.topo(x) && x == 3);
  CHECA(p.tamanho() == 3);      // topo não remove
  CHECA(p.elemento(0) == 1);    // base
  CHECA(p.elemento(2) == 3);    // topo

  CHECA(p.desempilha(x) && x == 3);
  CHECA(p.desempilha(x) && x == 2);
  CHECA(p.tamanho() == 1);
  CHECA(p.desempilha(x) && x == 1);
  CHECA(p.vazia());
  CHECA(!p.desempilha(x));

  // volume (passa da capacidade inicial do vetor interno)
  for (int i = 0; i < 1000; i++) p.empilha(i);
  CHECA(p.tamanho() == 1000);
  for (int k = 0; k < 1000; k++) CHECA(p.elemento(k) == k);
  for (int i = 999; i >= 0; i--) {
    CHECA(p.desempilha(x) && x == i);
  }
  CHECA(p.vazia());

  // reaproveitar depois de esvaziar
  p.empilha(42);
  CHECA(p.topo(x) && x == 42);

  printf("OK: teste_pilha\n");
  return 0;
}
