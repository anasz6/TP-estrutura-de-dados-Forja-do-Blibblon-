#ifndef ATRIBUTO_H
#define ATRIBUTO_H

#include <string>

class Atributo {
 public:
  Atributo(int id, const std::string& nome);
  int getid() const;
  const std::string& getnome() const;

 private:
  int id_;
  std::string nome_;
};

#endif