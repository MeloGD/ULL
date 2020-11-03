#include "set_calculator.h"


Set::Set() {
  size_ = sizeof(long) * 8;
  set_vector_.resize(1);
  set_vector_copy_.resize(1);
  data_ = 0;
}

Set::Set(float size) { 
  size_ = size;
  set_vector_.resize(ceil(size/(sizeof(long) * 8))); // corregir para 63 elementos
  set_vector_copy_.resize(ceil(size/(sizeof(long) * 8)));
  data_ = 0;
}

Set::~Set() {}

// Getters
char Set::Get_Operator(void) {
  return operator_;
}

int Set::get_maxvalue(void) {
  return size_;
}

int Set::Get_SetVectorSize(void) {
  return set_vector_.size();
}
// Setters
void Set::Set_Operator(char sign) {
  operator_ = sign;
}

// Methods
void Set::ReadFile(string filename) {
  ifstream file;
  string information;
  string candidates;
  int digits;
  bool next_set = false;
  bool set_erased = false;
  file.open("input.txt");
  while (getline(file, information)) {
    for (int i = 0; i < information.size(); i++) {
      candidates.clear();
      digits = 0;
      if (information[i] != '{') {
        for (int j = i; j < information.size(); j++) { 
          if (information[j] != ',' && information[j] != '}' && !isOperator(information[j])) {
            candidates.push_back(information[j]);
            digits++;
          } else {
            i += digits;
            if (information[j] == '}') {
              //i++; 
            }
            if (isOperator(information[j])) {
              Set_Operator(information[j]);
              //i = information.size();
              i++; // esto puede crear problemas
              if (!isUnary(information[j])) {
                next_set = true;
              }             
            }
            j = information.size();
          }
        }
        if (!candidates.empty()) {
          if (!next_set) { //esto de aqui es lo nuevo, borrar el if si da problemas
            WritetoSet(candidates);
          } else {
            if (!set_erased) {
              CopyMainSet();
              fill(set_vector_.begin(), set_vector_.end(), 0);
              set_erased = true; 
            }
            WritetoSet(candidates);
          }
          
          /*
          WritetoSet(candidates);
          cout << candidates << endl;
          */
        }   
      }
    }
    /*
    next_set = false;
    set_erased = false;
    fill(set_vector_.begin(), set_vector_.end(), 0);*/
  }
}

void Set::ReadString(string element) {
  int number = stoi(element) - 1;
  if (isdigit(element[0]) && number < 63) {
    data_ = pow (2 , number);
  }
  if (isdigit(element[0]) && number > 63) {
    while (number > 63) {
      number -= 63;
    }
    data_ = pow (2 , number);
  }
  if (number == 63) {
    data_ = pow(2, 0);
  }
}

void Set::WritetoSet(string element) {
  int number = stoi(element);
  if (number <= get_maxvalue()) {
    ReadString(element);
    int position = (number / 63);
    if (position == 0 ) {
      set_vector_[position] = set_vector_[position] | data_;
    } 
    if (number % 63 == 0) {
      set_vector_[position-1] = set_vector_[position - 1] | data_;
    } else {
      set_vector_[position] = set_vector_[position] | data_;
    } 
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
    d = std::bitset<63>(set_vector_[i]).to_string();
    reverse(d.begin(), d.end());
    for (int j = 0; j < d.size(); j++) {
      count++;
      if(d[j] == '1') {
        file << count;
        if (count  != get_maxvalue()) {
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

void Set::Solve(void) {
  if (Get_Operator() == '+') {
    Union();
  }
  if (Get_Operator() == '-') {
    /* code */
  }
  if (Get_Operator() == '*') {
    /* code */
  }
  if (Get_Operator() == '!') {
    Complementation();
  }
  if (Get_Operator() == '=') {
    /* code */
  }
}

void Set::CopyMainSet(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    cout << "Vector copiado: " << endl;
    set_vector_copy_[i] = set_vector_[i];
    cout << set_vector_copy_[i] << endl;
  }
}

bool Set::isOperator(char symbol) {
  if (symbol == '!' || symbol == '+' || symbol == '*' || symbol == '-' 
      || symbol == '=') {
    return true;
  } else {
    return false;
  }
}

bool Set::isUnary(char symbol) {
  if (symbol == '!') {
    return true;
  } else {
    return false;
  }
  
}

void Set::Complementation(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_[i] = ~set_vector_[i] ;
  }
}

void Set::Union(void) { 
  cout << "Entre aquí" << endl;
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_[i] = set_vector_[i] | set_vector_copy_[i];
  }
}