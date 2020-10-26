#include "fib.h"

Fibonacci::Fibonacci(const int size) {
  // fibonaccisequence_.resize(size);
  size_ = size;
}

Fibonacci::~Fibonacci() {

}

// Getters
int
Fibonacci::get_size(void) {
  return size_;
}

int
Fibonacci::get_index(string word) {
  for (int i = 0; i < get_size(); i++)
  {
      if (word == fibonaccisequence_[i]) {
      // cout << "Esta en Fibonacci y es la nº: " << i + 1 << endl;
      return i + 1;
    }
  }
  
}

string
Fibonacci::get_fibonaccisequence(int index) {
  return fibonaccisequence_[index];
}

string
Fibonacci::get_candidates(int index) {
  return candidates_[index];
}

// Setters
void
Fibonacci::set_fibonaccisequence(int index, string word) {
  fibonaccisequence_[index] = word;
}

void 
Fibonacci::set_candidates(int index, string word) {
  candidates_[index] = word;
}

// Functions
string
Fibonacci::WordFibonacci(int n) {
  if (n == 1) return "a";
  if (n == 2) return "b";
  return WordFibonacci(n - 2) + WordFibonacci(n - 1);
}

void
Fibonacci::BuildFibonacciSequence(void) {
  for (int i = 1; i <= get_size(); i++) {
    fibonaccisequence_.push_back(WordFibonacci(i));
    // fibonaccisequence_[i] = WordFibonacci(i); // usar el set
  } 
}

bool
Fibonacci::Check(string word) {
  for (int i = 0; i < get_size(); i++) {
    if (word == fibonaccisequence_[i]) {
      // cout << "Esta en Fibonacci y es la nº: " << i + 1 << endl;
      return true;
    }
  }
}

void Fibonacci::ReadFile(string name) {
  string sequence;
  ifstream file;
  file.open(name);
  while (file >> sequence) {
    candidates_.push_back(sequence); // cambiar por build candidates
  }
  file.close();
}

void
Fibonacci::WriteFile(string name) {
  ofstream file;
  file.open(name, ios::out | ios::app);
  for (int i = 0; i < candidates_.size(); i++) {
    if (Check(candidates_[i])) {
      file << candidates_[i] << "es la secuencia nº: " << get_index(candidates_[i]) << endl; // get index
    }
  }
  file.close();
}


