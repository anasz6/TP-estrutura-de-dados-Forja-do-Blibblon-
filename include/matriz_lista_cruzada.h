#ifndef MATRIZ_LISTA_CRUZADA_H
#define MATRIZ_LISTA_CRUZADA_H

#include "vetor_dinamico.h"
#include "celula.h"

class MatrizListaCruzada {
 public:
  MatrizListaCruzada();
  ~MatrizListaCruzada();                       
  void cresceItens(int n);                    
  void cresceAtributos(int n);                

  long long getvalor(int i, int a);
  void set(int i, int a, long long v);         
  void remove(int i, int a);

  Cursor iniciaLinha(int i);
  bool andaLinha(Cursor& c, Celula& saida);
  Cursor iniciaColuna(int a);
  bool andaColuna(Cursor& c, Celula& saida);

  long long produtoInternoLinhas(int i, int j);

  // usados na migração entre modos
  void limpa();                                
  void iniciaConstrucao();                     
  void anexaOrdenado(int i, int a, long long v);  
  void finalizaConstrucao();                   // descarta os auxiliares
  int numCelulas() const;

  // instrumentação
  long long bytesUsados() const;
  long long celulasPercorridas() const;
  void zeraContadores();

 private:
  struct No {
    int item;
    int atributo;
    long long valor;
    No* proxLinha;
    No* proxColuna;
  };

  VetorDinamico<No*> cabecaLinha;
  VetorDinamico<No*> cabecaColuna;
  VetorDinamico<No*> ultimoLinha;              // só durante a construção em massa
  VetorDinamico<No*> ultimoColuna;
  int numNos;
  long long percorridas;
};

#endif