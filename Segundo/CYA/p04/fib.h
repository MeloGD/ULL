#include <iostream>
#include <vector>

using namespace std;

#define MAX 35

class Fibonacci {
private:
  string Fibonacciword;
  vector<string> fibonaccisequence_;
  vector<string> candidates_;
public:
  Fibonacci(vector<string>, vector<string>);
  ~Fibonacci();
  // Getters
  vector<string> get_fibonaccisequence();
  vector<string> get_candidates();
  // Setters
  void set_fibonaccisequence();
  void set_candidates();
  // Metodos
  void BuildFibonacci();
  void Check();
  void ReadFile();
  void WriteFile();

};


