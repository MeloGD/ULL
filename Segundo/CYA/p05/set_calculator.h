#include "iostream"
#include "vector"

using namespace std;

class Set {
private:
  vector<long> set_vector_;

  string       data_;
  int          size_;
  unsigned     subset_;
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
  void WritetoSet(void);
};



