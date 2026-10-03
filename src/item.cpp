#include "item.h"

Item::Item(int id, const std::string& nome){
      id_ = id;
      nome_ = nome;
}

int Item::getid() const{
    return id_;
}
const std::string& Item::getnome() const{
    return nome_;
}