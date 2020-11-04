#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h> 
#include <math.h>

using namespace std;


class Set {
private:
  vector<unsigned long long int>  set_vector_;
  vector<unsigned long long int>  set_vector_copy_;

  unsigned long long int          data_;
  int                             size_;
  char                            operator_;
  string                          elementsoverload_;                         
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
  int Get_Size(void);
  // hacer un getter para el size del set_vector_
  // Setters 
  void Set_Operator(char);
  // Methods
  void ReadFile(string);    // lee el fichero y me da los valores que me interesan
  void ReadString(string);  // me escribe el data_
  void WritetoSet(string); // ADD to set
  void WriteSettoFile(void); // recorre el conjunto y lo escribe en el fichero
  void RemoveElement(string);
  void WipeSet(void);
  void Solve(void);
  void CopyMainSet(void);
  bool isInSet(string);
  bool isEmpty(void);
  bool isOperator(char);
  bool isUnary(char);
  // Operations
  void Union(void);
  void RelativeComplement(void);
  void Intersection(void);
  void Complementation(void);
  void Asignation(void);

  // Overloads 
  
  friend ostream & operator <<( ostream &out, Set &set) {
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
  friend istream& operator>>(istream&, Set&);
  friend bool operator==(const Set&, const Set&);
  
  
};      


