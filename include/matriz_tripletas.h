#ifndef MATRIZ_TRIPLETAS_H
#define MATRIZ_TRIPLETAS_H

#include "vetor_dinamico.h"
#include "celula.h"

class MatrizTripletas {
 public:
  MatrizTripletas();

  long long getvalor(int i, int a);
  void set(int i, int a, long long v);       
  void remove(int i, int a);

  Cursor iniciaLinha(int i);
  bool andaLinha(Cursor& c, Celula& saida);
  Cursor iniciaColuna(int a);
  bool andaColuna(Cursor& c, Celula& saida);

  long long produtoInternoLinhas(int i, int j);

  // usados na migracao entre modos
  void limpa();
  void adicionaNoFim(const Celula& c);       
  int numCelulas() const;
  Celula celulaEm(int pos) const;

  // instrumentacao
  long long bytesUsados() const;
  long long celulasPercorridas() const;
  void zeraContadores();

 private:
  VetorDinamico<Celula> v_;
  long long percorridas;
  int buscaPos(int i, int a, bool& achou) const;
  int primeiroComItemMaiorOuIgual(int i) const;
};

#endif
