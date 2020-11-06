#include "set_calculator.h"

#define kNum_Bits 64

Set::Set() {
  max_element_ = sizeof(long) * 8;
  set_vector_.resize(1);
  set_vector_copy_.resize(1);
  data_ = 0;
}

Set::Set(float size) { 
  max_element_ = size;
  set_vector_.resize(ceil(size/(sizeof(long) * 8))); 
  set_vector_copy_.resize(ceil(size/(sizeof(long) * 8)));
  data_ = 0;
}

Set::~Set() {}

// Getters
unsigned long int Set::Get_Data(void) {
  return data_;
}

unsigned long int Set::Get_SetVectorValue(int position) {
  return set_vector_[position];
}

char Set::Get_Operator(void) {
  return operator_;
}

int Set::Get_MaxValue(void) {
  return max_element_;
}

int Set::Get_SetVectorSize(void) {
  return set_vector_.size();
}

string Set::Get_ElementsOverload(void) {
  return elementsoverload_;
}

// Setters
void Set::Set_Data(unsigned long int data) {
  data_ = data;
}

void Set::Set_SetVectorValue(int position, unsigned long int value) {
  set_vector_[position] = value;
}
void Set::Set_Operator(char sign) {
  operator_ = sign;
}

void Set::Set_ElementsOverload(string elemments) {
  elementsoverload_ = elemments;
}


// Methods
void Set::ReadFile(string filename, string outputfile) {
  ifstream    file;
  string      information;
  file.open("input.txt");
  while (getline(file, information)) {
    Filter(information, outputfile);
  }
  file.close();
}

void Set::Filter(string information, string outputfile) {
  string candidates;
  bool next_set = false;
  bool erased = false;
  int digits = 0;
  fill(set_vector_.begin(), set_vector_.end(), 0);
  Set_Operator('0');
  for (int i = 0; i < information.size(); i++) {
    candidates.clear();
    digits = 0;
    if (information[i] != '{' && information[i] != ' ') {  
      for (int j = i; j < information.size(); j++) { 
        if (information[j] != ',' && information[j] != '}' 
            && information[j] != ' ' && !isOperator(information[j])) {
          candidates.push_back(information[j]);
          digits++;
        } else {
          i += digits;
          if (isOperator(information[j])) {
            Set_Operator(information[j]);
            i++; 
            if (!isUnary(information[j])) {
              next_set = true;
            }             
          }
          j = information.size();
        }
      }
      if (!candidates.empty()) {
        if (!next_set) { 
          WritetoSet(candidates);
        } else {
          if (!erased) {
            CopyMainSet();
            fill(set_vector_.begin(), set_vector_.end(), 0);
            erased = true; 
          }
          WritetoSet(candidates);
        }
      }   
    }
  }
  if (isOperator(operator_)) {
    Solve(outputfile);
  } else {
    WriteSettoFile(outputfile);
  }
}

void Set::ReadString(string element) {
  int leftshift = stoi(element) - 1;
  if (isdigit(element[0]) && leftshift < kNum_Bits) {
    Set_Data(pow (2 , leftshift)); 
  }
  if (isdigit(element[0]) && leftshift > kNum_Bits) {
    while (leftshift > kNum_Bits) {
      leftshift -= kNum_Bits;
    }
    Set_Data(pow (2 , leftshift));
  }
  if (leftshift == kNum_Bits) {
    Set_Data(pow(2, 0));
  }
}

void Set::WritetoSet(string element) {
  int number = stoi(element);
  int kCorrection = 1;
  if (number <= Get_MaxValue()) {
    ReadString(element);
    int position = (number / kNum_Bits);
    if (position == 0 ) {
      Set_SetVectorValue(position, Get_SetVectorValue(position) | Get_Data());
    } 
    if (number % kNum_Bits == 0) {
      Set_SetVectorValue(position - kCorrection, 
      Get_SetVectorValue(position - kCorrection) | Get_Data());
    } else {
      Set_SetVectorValue(position, Get_SetVectorValue(position) | Get_Data());
    }
  }
}

void Set::WriteSettoFile(string outputfile) {
  ofstream file;
  file.open(outputfile, ofstream::out | ofstream::app);
  // Element = Posicion del valor --> Coincide con el valor
  int element = 0;
  int iterator = 0;
  // Swap --> Para guardar el número del conjunto como string
  // y colocarlo en la string de solución
  string number;  
  string solution;
  string subset;  

  solution.push_back('{');
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    subset = std::bitset<kNum_Bits>(set_vector_[i]).to_string();
    reverse(subset.begin(), subset.end());
    for (int j = 0; j < subset.size(); j++) {
      element++;
      if(subset[j] == '1') {
        number = to_string(element);
        iterator = 0;
        while (number.size() > iterator) {
          solution.push_back(number[iterator]);
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
  int kCorrection = 1;
  if (number <= Get_MaxValue()) {
    ReadString(element);
    int position = (number / kNum_Bits);
    if (position >= 0 ) {
      Set_SetVectorValue(position, Get_SetVectorValue(position) ^ Get_Data());
      // set_vector_[position] = set_vector_[position] ^ data_;
    } 
    if (number % kNum_Bits == 0) {
      Set_SetVectorValue(position - kCorrection, Get_SetVectorValue(position - kCorrection) ^ Get_Data());
      // set_vector_[position-1] = set_vector_[position - 1] ^ data_;
    }
  }
}

void Set::WipeSet(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    fill(set_vector_.begin(), set_vector_.end(), 0);
  }
  
}

void Set::Solve(string outputfile) {
  if (Get_Operator() == '+') {
    Union();
    WriteSettoFile(outputfile);
  }
  if (Get_Operator() == '-') {
    RelativeComplement();
    WriteSettoFile(outputfile);
  }
  if (Get_Operator() == '*') {
    Intersection();
    WriteSettoFile(outputfile);
  }
  if (Get_Operator() == '!') {
    Complementation();
    WriteSettoFile(outputfile);
  }
  if (Get_Operator() == '=') {
    WriteSettoFile(outputfile);
  }
}

void Set::CopyMainSet(void) {
  for (int i = 0; i < Get_SetVectorSize(); i++) {
    set_vector_copy_[i] = set_vector_[i];
  }
}

bool Set::isInSet(string element) {
  bool isinset = false;
  int number = stoi(element);
  int position = (number / kNum_Bits);
  string subset;

  while (number > kNum_Bits) {
    number -= kNum_Bits;
  }
  subset = std::bitset<kNum_Bits>(set_vector_[position]).to_string();
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
ostream& operator <<( ostream &out, Set &set) {
    int element = 0;
    int iterator = 0;
    string swap;
    string solution;
    string subset;
    
    solution.push_back('{');
    for (int i = 0; i < set.set_vector_.size(); i++) {
      subset = std::bitset<64>(set.set_vector_[i]).to_string();
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
    out << solution;
    return out;
  }

istream& operator>>(istream& in, Set& subset) {
  string elements;
  cin >> elements;
  subset.Set_ElementsOverload(elements);
  subset.Filter(subset.Get_ElementsOverload(), "");
  return in;
}

bool operator==(const Set& set1, const Set& set2) {
  int notequals = 0;
  bool equal;
  for (int i = 0; i < set1.set_vector_.size(); i++) {
    if (set1.set_vector_[i] == set2.set_vector_[i]) {
      if (notequals == 0) {
        equal = true;
      }   
    } else {
      notequals++;
      equal = false;
    }
  }
  return equal;
}
