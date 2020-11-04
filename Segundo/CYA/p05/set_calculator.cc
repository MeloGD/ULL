#include "set_calculator.h"


Set::Set() {
  size_ = sizeof(long) * 8;
  set_vector_.resize(1);
  set_vector_copy_.resize(1);
  data_ = 0;
}

Set::Set(float size) { 
  size_ = size;
  set_vector_.resize(ceil(size/(sizeof(long) * 8))); // corregir para 64 elementos
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

int Set::Get_Size(void) {
  return size_;
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
  if (elementsoverload_.empty()) {
    file.open("input.txt");
    while (getline(file, information)) {
      next_set = false;
      set_erased = false;
      fill(set_vector_.begin(), set_vector_.end(), 0);
      // vaciar el operator_
      operator_ = '0';
      for (int i = 0; i < information.size(); i++) {
        candidates.clear();
        digits = 0;
        if (information[i] != '{') {  //aqui es posible que tenga que añadir != " " para poder poner espacios
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
      if (isOperator(operator_)) {
        Solve();
      } else {
        WriteSettoFile();
      }
    }
  } else {
    next_set = false;
    set_erased = false;
    fill(set_vector_.begin(), set_vector_.end(), 0);
    // vaciar el operator_
    operator_ = '0';
    for (int i = 0; i < elementsoverload_.size(); i++) {
      candidates.clear();
      digits = 0;
      if (elementsoverload_[i] != '{') {  //aqui es posible que tenga que añadir != " " para poder poner espacios
        for (int j = i; j < elementsoverload_.size(); j++) { 
          if (elementsoverload_[j] != ',' && elementsoverload_[j] != '}' && !isOperator(elementsoverload_[j])) {
            candidates.push_back(elementsoverload_[j]);
            digits++;
          } else {
            i += digits;
            if (elementsoverload_[j] == '}') {
              //i++; 
            }
            if (isOperator(elementsoverload_[j])) {
              Set_Operator(elementsoverload_[j]);
              //i = elementsoverload_.size();
              i++; // esto puede crear problemas
              if (!isUnary(elementsoverload_[j])) {
                next_set = true;
              }             
            }
            j = elementsoverload_.size();
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
        }   
      }
    }
    if (isOperator(operator_)) {
      Solve();
    } else {
      WriteSettoFile();
    }
    
  }
  
  

}

void Set::ReadString(string element) {
  int number = stoi(element) - 1;
  if (isdigit(element[0]) && number < 64) {
    data_ = pow (2 , number);
  }
  if (isdigit(element[0]) && number > 64) {
    while (number > 64) {
      number -= 64;
    }
    data_ = pow (2 , number);
  }
  if (number == 64) {
    data_ = pow(2, 0);
  }
}

void Set::WritetoSet(string element) {
  int number = stoi(element);
  if (number <= get_maxvalue()) {
    ReadString(element);
    int position = (number / 64);
    if (position == 0 ) {
      set_vector_[position] = set_vector_[position] | data_;
    } 
    if (number % 64 == 0) {
      set_vector_[position-1] = set_vector_[position - 1] | data_;
    } else {
      set_vector_[position] = set_vector_[position] | data_;
    }
  }
}

void Set::WriteSettoFile(void) {
  ofstream file;
  file.open("output.txt", ofstream::out | ofstream::app);
  int element = 0;
  int iterator = 0;
  string swap;
  string solution;
  string subset;  
  solution.push_back('{');
  for (int i = 0; i < set_vector_.size(); i++) {
    subset = std::bitset<64>(set_vector_[i]).to_string();
    reverse(subset.begin(), subset.end());
    for (int j = 0; j < subset.size(); j++) {
      element++;
      if(subset[j] == '1') {
        swap = to_string(element);
        iterator = 0;
        while (swap.size() > iterator) {
          solution.push_back(swap[iterator]);
          iterator++;
        }
        solution.push_back(',');
        solution.push_back(' ');
      }
    }
  }
  solution.erase(solution.size() - 1);
  solution.erase(solution.size() - 1);
  solution.push_back('}');
  solution.push_back('\n');
  file << solution;
  file.close();
}

void Set::RemoveElement(string element) {
  int number = stoi(element);
  if (number <= get_maxvalue()) {
    ReadString(element);
    int position = (number / 64);
    if (position >= 0 ) {
      cout << "Data_" << data_ << endl;
      set_vector_[position] = set_vector_[position] ^ data_;
    } 
    if (number % 64 == 0) {
      cout << "Entre en el segundo if" << endl;
      set_vector_[position-1] = set_vector_[position - 1] ^ data_;
    }
  }
}

void Set::WipeSet(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    fill(set_vector_.begin(), set_vector_.end(), 0);
  }
  
}

void Set::Solve(void) {
  if (Get_Operator() == '+') {
    Union();
    WriteSettoFile();
  }
  if (Get_Operator() == '-') {
    RelativeComplement();
    WriteSettoFile();
  }
  if (Get_Operator() == '*') {
    Intersection();
    WriteSettoFile();
  }
  if (Get_Operator() == '!') {
    Complementation();
    WriteSettoFile();
  }
  if (Get_Operator() == '=') {
    WriteSettoFile();
  }
}

void Set::CopyMainSet(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    cout << "Vector copiado: " << endl;
    set_vector_copy_[i] = set_vector_[i];
    cout << set_vector_copy_[i] << endl;
  }
}

bool Set::isInSet(string element) {
  bool isinset = false;
  int number = stoi(element);
  int position = (number / 64);
  string subset;

  while (number > 64) {
    number -= 64;
  }
  subset = std::bitset<64>(set_vector_[position]).to_string();
  reverse(subset.begin(), subset.end());
  if(subset[number - 1] == '1') {
        isinset = true;
  }
  return isinset;
}

bool Set::isEmpty(void) {
  bool empty = false;
  int countnonzeros = 0;
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    if (set_vector_[i] != 0) {
      countnonzeros++;
      empty = false;
    } else {
      if (countnonzeros == 0) {
        empty = true;
      }
    }
  }
  return empty;
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

// Operations
void Set::Union(void) { 
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_[i] = set_vector_[i] | set_vector_copy_[i];
  }
}

void Set::RelativeComplement(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_[i] = set_vector_[i] ^ set_vector_copy_[i] ;
  }
}

void Set::Intersection(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_[i] = set_vector_[i] & set_vector_copy_[i] ;
  }  
}

void Set::Complementation(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_[i] = ~set_vector_[i] ;
  }
}

// Overloads

istream& operator>>(istream& in, Set& subset) {
  cin >> subset.elementsoverload_;
  subset.ReadFile(subset.elementsoverload_);
  return in;
}