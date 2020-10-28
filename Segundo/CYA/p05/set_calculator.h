#include "iostream"
#include "vector"

using namespace std;

class Set {
private:
  int size_;
  vector<long> set_vector_;
public:
  Set();  // size_ = sizeof(long);
  Set(int);
  ~Set();
  // Getters
  string get_value(void);
  // Setters 
  void set_value(string);
  // Methods
  void Print(void);
};



