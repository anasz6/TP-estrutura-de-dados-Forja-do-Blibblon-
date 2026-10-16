#ifndef CATALOGO_H
#define CATALOGO_H

#include "matriz_tripletas.h"
#include "matriz_lista_cruzada.h"
#include "celula.h"

enum Modo { MODO_T = 0, MODO_L = 1 };

class Catalogo {
 public:
  Catalogo();                                  

  void cresceItens(int n);                      
  void cresceAtributos(int n);                 
  int getNumItens() const;
  int getNumAtributos() const;
  Modo getModo() const;

  long long getvalor(int i, int a);
  void set(int i, int a, long long v);
  void remove(int i, int a);

  Cursor iniciaLinha(int i);
  bool andaLinha(Cursor& c, Celula& saida);
  Cursor iniciaColuna(int a);
  bool andaColuna(Cursor& c, Celula& saida);

  long long produtoInternoLinhas(int i, int j);

  void trocaModo(Modo novo);                    
  long long bytesUsados() const;               
  long long celulasPercorridas() const;         
  void zeraContadores();                       

 private:
  MatrizTripletas matrizT;
  MatrizListaCruzada matrizL;
  Modo modoAtual;
  int numItens;
  int numAtributos;
};

#endif