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

void Set::WritetoSet(string element) {
  ReadString(element);
  int number = stoi(element);
  // Dividimos entre 9 porque entre 8 no los coloca correctamente en su posicion
  int position = ((number / 8));
  if (position == 0 ) {
    set_vector_[position] = set_vector_[position] | data_;
  } 
  if (number % 8 == 0) {
    set_vector_[position-1] = set_vector_[position - 1] | data_;
  } else {
    set_vector_[position] = set_vector_[position] | data_;
  }
}

void Set::WriteFile(void) {
  string d;
  int count = 0;
  for (int i = 0; i < set_vector_.size(); i++) {
    d = std::bitset<8>(set_vector_[i]).to_string();
    reverse(d.begin(), d.end());
    for (int j = 0; j < d.size(); j++) {
      count++;
      if(d[j] == '1') {
        cout << "De la posicion del vector " << i << " sale el numero: " << count << endl;
      }
    }
  }
}