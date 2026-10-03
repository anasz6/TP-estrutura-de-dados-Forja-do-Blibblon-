#ifndef FILA_H
#define FILA_H

struct Encomenda {
  int aventureiro;
  int item;
};

class Fila {
 public:
  Fila();
  ~Fila();
  int enfileira(const Encomenda& e);     
  bool desenfileira(Encomenda& saida);   
  bool vazia() const;
  int tamanho() const;

 private:
  struct No {
    Encomenda dado;
    No* prox;
  };
  No* inicio;
  No* fim;
  int tam;

  Fila(const Fila&) = delete;
  Fila& operator=(const Fila&) = delete;
};

#endif