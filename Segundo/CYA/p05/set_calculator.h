#include <iostream>
#include <vector>
#include <bits/stdc++.h> 


using namespace std;


class Set {
private:
  vector<unsigned long> set_vector_;

  unsigned long         data_;
  int                   size_;
public:
  Set();  
  Set(int);
  ~Set();
  // Getters
  string get_value(void);
  // Setters 
  void set_value(string);
  // Methods
  void Print(void);
  void ReadString(string);
  void WritetoSet(string);
  void WriteFile(void);
};



