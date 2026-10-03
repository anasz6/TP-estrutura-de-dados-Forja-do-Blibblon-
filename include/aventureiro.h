#ifndef AVENTUREIRO_H
#define AVENTUREIRO_H

#include <string>
#include "pilha.h"

class Aventureiro {
 public:
  Aventureiro(int id, const std::string& nome);
  int getid() const;
  const std::string& getnome() const;

  void equipa(int item);
  bool desequipa(int& item);        
  int numEquipados() const;
  int itemEquipado(int k) const;    

 private:
  int id_;
  std::string nome_;
  Pilha build_;

  Aventureiro(const Aventureiro&) = delete;
  Aventureiro& operator=(const Aventureiro&) = delete;
};

#endif