#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h> 
#include <math.h>

using namespace std;


class Set {
private:
  vector<unsigned long long int> set_vector_;

  unsigned long long int         data_;
  int                   size_;
  int                   max_;
  // Esto de aqui es para realizar operaciones 
  // vector<unsigned long> set_vector2_;
  // bool isunary_;
  // char operator_;
public:
  Set();  
  Set(int);
  ~Set();
  // Getters
  string get_value(void);
  // Setters 
  void set_value(string);
  void set_lastvalue(int);
  // Methods
  string ReadFile(string);
  void ReadString(string);
  void WritetoSet(string); // ADD to set
  void WriteSettoFile(void); // recorre el conjunto en el fichero
  // void WriteFile(int n); // escribe output.txt
};



