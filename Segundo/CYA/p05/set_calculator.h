#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h> 
#include <math.h>

using namespace std;


class Set {
private:
  vector<unsigned long long int> set_vector_;
  vector<unsigned long long int> set_vector_copy_;

  unsigned long long int         data_;
  int                            size_;
  char                           operator_;
  // Esto de aqui es para realizar operaciones 
  // vector<unsigned long> set_vector2_;
  // bool isunary_;
  // char operator_;
public:
  Set();  
  Set(float);
  ~Set();
  // Getters
  char Get_Operator(void);
  int get_maxvalue(void);
  int Get_SetVectorSize(void);
  // hacer un getter para el size del set_vector_
  // Setters 
  void Set_Operator(char);
  // Methods
  void ReadFile(string);    // lee el fichero y me da los valores que me interesan
  void ReadString(string);  // me escribe el data_
  void WritetoSet(string); // ADD to set
  void WriteSettoFile(void); // recorre el conjunto en el fichero
  void Solve(void);
  void CopyMainSet(void);
  bool isOperator(char);
  bool isUnary(char);
  // Operations
  void Union(void);
  void RelativeComplement(void);
  void Intersection(void);
  void Complementation(void);
  void Asignation(void);
};



