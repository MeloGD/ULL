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

}

void Set::ReadString(string number) {
  int position = stoi(number);
  data_.erase(data_.begin() + position);
  // 8 porque es el nº maximo de bits
  data_.insert(8-position,"1"); 
}

// De momento hago couts aqui para comprobar como estan
// ejecutandose los valores
void Set::WritetoSet(void) {
  cout << "data_ es: " << endl;
  cout << data_ << endl;
  subset_ = stoi(data_);
  cout << "valor para la primera pos. del vector: " << endl;
  // Compruebo aqui como se escribe subset_ en el vector de conjuntos
  set_vector_[0] = subset_;
  cout << set_vector_[0] << endl;
}