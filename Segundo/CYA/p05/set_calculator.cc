#include "set_calculator.h"


Set::Set() {
  size_ = sizeof(long);
  set_vector_.resize(size_);
  data_ = 0;
  max_ = 0;
}

Set::Set(int size) {
  size_ = size;
  set_vector_.resize(size_);
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
  cout << number << endl;
  if (isdigit(element[0]) && number <= 64) {
    int shift = stoi(element) - 1;
    cout << data_ << endl;
    data_ = (1 << shift);
    cout << "Entre aqui" << endl;
    cout << element[0] << endl;
    cout << shift << endl;
  }
  if (isdigit(element[0]) && number > 64) {
    while (number > 64) {
      number -= 64;
    }
    int shift = number - 1;
    data_ = (1 << shift);
    cout << "Pos aqui tambien" << endl;
  }
  cout << data_ << endl;
}

void Set::WritetoSet(string element) {
  ReadString(element);
  int number = stoi(element);
  // Dividimos entre 9 porque entre 64 no los coloca correctamente en su posicion
  int position = ((number / 64));
  if (position == 0 ) {
    set_vector_[position] = set_vector_[position] | data_;
  } 
  if (number % 64 == 0) {
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
    d = std::bitset<64>(set_vector_[i]).to_string();
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

