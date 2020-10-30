#include "set_calculator.h"


Set::Set() {
  size_ = sizeof(long);
  set_vector_.resize(size_);
  data_ = 0;
}

Set::Set(int size) {
  size_ = size;
  set_vector_.resize(size_);
  data_ = 0;
}

Set::~Set() {}

void Set::Print(void) {

}

// Hay que hacer un reverse() de data_ cuando vaya a trabajar con el
void Set::ReadString(string element) {
  int number = stoi(element);
  if (isdigit(element[0]) && number <= 8) {
    int shift = stoi(element) - 1;
    data_ = (1 << shift);
  }
  if (isdigit(element[0]) && number > 8) {
    while (number > 8) {
      number -= 8;
    }
    int shift = number - 1;
    data_ = (1 << shift);
  }
}

// De momento hago couts aqui para comprobar como estan
// ejecutandose los valores
void Set::WritetoSet(string element) {
  ReadString(element);
  int number = stoi(element);
  cout << "Number vale: " << number << endl;
  int position = ((number / 9));
  if (position == 0) {
    cout << "Position vale: " << position << endl;
    set_vector_[position] += data_;
  } else {
    cout << "Position vale: " << position << endl;
    set_vector_[position] += data_;
  }

  cout << "El vector de sets queda asi: "  << endl;
  for (int i = 0; i < set_vector_.size(); i++) {
    cout << set_vector_[i] << endl;
  }
  
}