#include "atributo.h"

Atributo::Atributo(int id, const std::string& nome){
      id_ = id;
      nome_ = nome;
}

int Atributo::getid() const{
    return id_;
}
const std::string& Atributo::getnome() const{
    return nome_;
}