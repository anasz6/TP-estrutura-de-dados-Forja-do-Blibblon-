#ifndef PILHA_H
#define PILHA_H
#include "vetor_dinamico.h"

class Pilha {
 public:
  void empilha(int item);
  bool desempilha(int& item);   // false se vazia; senão devolve o item por referência
  bool topo(int& item) const;   // false se vazia
  bool vazia() const;
  int tamanho() const;
  int elemento(int k) const;    // k-ésimo da base (0) até o topo, sem remover

 private:
  VetorDinamico<int> itens_;
};

#endif