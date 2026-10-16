#ifndef VETOR_DINAMICO_H
#define VETOR_DINAMICO_H

template <typename T>
class VetorDinamico {
 public:
  VetorDinamico() {
    cap = 8;
    tam = 0;
    dados = new T[cap];
  }

  ~VetorDinamico() {
    delete[] dados;
  }

  int tamanho() const { return tam; }

  T& operator[](int i) { return dados[i]; }
  const T& operator[](int i) const { return dados[i]; }

  void adiciona(const T& x) {
    if(cap == tam){
      cresce(2*cap);
    }
    dados[tam]=x;
    tam++;
  }

  void insereEm(int pos, const T& x) {
    if(tam == cap){
        cresce(2*cap);
    }
    for(int i = tam-1; i >= pos; i--){
        dados[i+1] = dados [i];
    }
    dados[pos] = x;
    tam++;
  }

  void removeEm(int pos) {
    for(int i = pos; i<tam-1; i++){
        dados[i] = dados[i+1];
    }
    tam--;
  }

  void limpa() {
    tam = 0;
  }

  void reserva(int novaCap) {
    cresce(novaCap);
  }

  void redimensiona(int novoTam, const T& preenchimento) {
    if(novoTam>cap){
        cresce(novoTam);
    }
        for(int i = tam; i<novoTam;i++){
            dados[i] = preenchimento;
    } 
    tam = novoTam;
  }
//não sei por que é assim , ENTENDER
  long long bytesReservados() const {
    return (long long)cap * sizeof(T);
  }

 private:
  T* dados;
  int tam;
  int cap;

  VetorDinamico(const VetorDinamico&) = delete;
  VetorDinamico& operator=(const VetorDinamico&) = delete;

  void cresce(int novaCap) {
   if(novaCap <= cap){
    return;
   } else {
    T* novo = new T[novaCap];
    for(int i= 0; i<tam ; i++){
        novo[i] = dados[i];
    }
    delete[] dados;
    dados = novo;
    cap = novaCap;
   }
  }
};

#endif