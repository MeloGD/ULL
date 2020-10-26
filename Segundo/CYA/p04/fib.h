#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Fibonacci {
private:
  vector<string> fibonaccisequence_;
  vector<string> candidates_;

  int size_;
public:
  Fibonacci(const int);
  ~Fibonacci();
  // Getters
  string get_fibonaccisequence(int);
  string get_candidates(int);
  int get_size(void);
  int get_index(string);
  // Setters
  void set_fibonaccisequence(int, string);
  void set_candidates(int, string);
  void set_size(int);
  // Metodos
  string WordFibonacci(int);
  void BuildFibonacciSequence(void);
  bool Check(string);
  void ReadFile(string); // es esta
  void WriteFile(string);
};


