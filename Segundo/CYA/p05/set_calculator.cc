#include "set_calculator.h"


Set::Set() {
  size_ = sizeof(long);
  set_vector_.resize(size_);
  data_ = "00000000";
}

Set::Set(int size) {
  size_ = size;
  set_vector_.resize(size_);
  data_ = "00000000";
}

Set::~Set() {}

void Set::Print(void) {
  /*
  cout << "Tamaño del size_" << endl;
  cout << size_ << endl;
  cout << "Tamaño del set_vector_" << endl;
  cout << set_vector_.size() << endl;

  cout << endl;
  cout << "data_" << endl;
  cout << data_ << endl;
  
  cout << "set_vector contiene: " << endl;
  for (int i = 0; i < set_vector_.size(); i++) {
  cout << set_vector_[i] << " ";
  }*/
}

void Set::ReadString(string number) {
  int position = stoi(number);
  data_.erase(data_.begin() + position);
  // 8 porque es el nº maximo de bits
  data_.insert(8-position,"1"); 
}

void Set::WritetoSet(void) {
  cout << "data_ es: " << endl;
  cout << data_ << endl;
  subset_ = stoi(data_);
  cout << "valor para la primera pos. del vector: " << endl;
  // Compruebo aqui como se escribe subset_ en el vector de conjuntos
  set_vector_[0] = subset_;
  cout << set_vector_[0] << endl;
}