#ifndef FORJA_H
#define FORJA_H

#include "vetor_dinamico.h"
#include "atributo.h"
#include "item.h"
#include "aventureiro.h"
#include "fila.h"
#include "catalogo.h"
#include "ordenacao.h"

class Forja {
 public:
  Forja();
  ~Forja();
  void executa(char* linha);
  void setAlgoritmo(Algoritmo a);

 private:
  VetorDinamico<Atributo*> atributos;
  VetorDinamico<Item*> itens;
  VetorDinamico<Aventureiro*> aventureiros;
  Fila fila;
  Catalogo catalogo;
  Algoritmo algoritmo;

  void cmdE(char* resto);
  void cmdA(char* resto);
  void cmdI(char* resto);
  void cmdH(char* resto);
  void cmdM(char* resto);
  void cmdLI(char* resto);
  void cmdLA(char* resto);
  void cmdF(char* resto);
  void cmdZ(char* resto);
  void cmdD(char* resto);
  void cmdLH(char* resto);
  void cmdQ(char* resto);

  // preenche 'build' (já com tamanho T) com a soma dos itens equipados por av
  void calculaBuild(Aventureiro* av, VetorDinamico<long long>& build);
};

#endif