#include "set_calculator.h"


Set::Set() {
  size_ = sizeof(long);
  set_vector_.resize(sizeof(long) * 8);
  data_ = 0;
  max_ = 0;
}

Set::Set(int size) {
  size_ = size;
  set_vector_.resize((size/sizeof(long) * 8));
  data_ = 0;
  max_ = 0;
}

Set::~Set() {}

// Getters

// Setters
void Set::set_lastvalue(int n) {
  if (n > max_) {
    max_ = n;
  }  
}


// Methods
//string Set::String
void Set::ReadString(string element) {
  int number = stoi(element);
  if (isdigit(element[0]) && number <= 32) {
    int shift = number - 1;
    data_ = (1 << shift);
    cout << "data vale esto"<< data_ << endl;
  }
  if (isdigit(element[0]) && number > 32) {
    while (number > 32) {
      number -= 32;
    }
    int shift = number - 1;
    data_ = (1 << shift);
  }
}

void Set::WritetoSet(string element) {
  ReadString(element);
  int number = stoi(element);
  // Dividimos entre 9 porque entre 32 no los coloca correctamente en su posicion
  int position = (number / 32);
  if (position == 0 ) {
    set_vector_[position] = set_vector_[position] | data_;
  } 
  if (number % 32 == 0) {
    set_vector_[position-1] = set_vector_[position - 1] | data_;
  } else {
    set_vector_[position] = set_vector_[position] | data_;
  }
}

void Set::WriteSettoFile(void) {
  ofstream file;
  string d; // cambiar d por algo descriptivo
  string setsolution;
  file.open("output.txt");
  file << "{";
  int count = 0;
  for (int i = 0; i < set_vector_.size(); i++) {
    d = std::bitset<32>(set_vector_[i]).to_string();
    reverse(d.begin(), d.end());
    for (int j = 0; j < d.size(); j++) {
      count++;
      if(d[j] == '1') {
        file << count;
        if (count  != max_) {
          file << ",";
        }
      }
    }
  }
  file << "}" << endl;
  file.close();
  for (int i = 0; i < set_vector_.size(); i++) {
    cout << set_vector_[i] << endl;
  }
}

