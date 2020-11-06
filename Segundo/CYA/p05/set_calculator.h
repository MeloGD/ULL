#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h> 
#include <math.h>


using namespace std;


class Set {
private:
  vector<unsigned long int>  set_vector_;
  vector<unsigned long int>  set_vector_copy_;

  unsigned long int          data_;
  int                        max_element_;
  char                       operator_;
  string                     elementsoverload_;                         

public:
  Set();  
  Set(float);
  ~Set();

  // Getters
  unsigned long int Get_Data(void);
  unsigned long int Get_SetVectorValue(int); 
  char Get_Operator(void);
  int Get_MaxValue(void);
  int Get_SetVectorSize(void);
  string Get_ElementsOverload(void);
  
  // Setters
  void Set_Data(unsigned long int);
  void Set_SetVectorValue(int, unsigned long int);
  void Set_Operator(char);
  void Set_ElementsOverload(string);
  
  // Methods
  void ReadFile(string,string);    
  void Filter(string, string);
  void ReadString(string);  
  void WritetoSet(string); 
  void WriteSettoFile(string); 
  void RemoveElement(string);
  void WipeSet(void);
  void CopyMainSet(void);
  bool isInSet(string);
  bool isEmpty(void);
  bool isOperator(char);
  bool isUnary(char);
  void Solve(string);
  
  // Operations
  void Union(void);
  void RelativeComplement(void);
  void Intersection(void);
  void Complementation(void);
  void Asignation(void);

  // Overloads 
  friend ostream & operator <<( ostream &out, Set &set);
  friend istream& operator>>(istream&, Set&);
  friend bool operator==(const Set&, const Set&); 
};      


