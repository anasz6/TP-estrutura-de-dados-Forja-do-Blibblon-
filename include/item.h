#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
 public:
  Item(int id, const std::string& nome);
  int getid() const;
  const std::string& getnome() const;

 private:
  int id_;
  std::string nome_;
};

#endif