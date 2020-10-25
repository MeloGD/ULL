#include "fib.h"

Fibonacci::Fibonacci(vector<string> fibonaccisequence, vector<string> candidates) {
  fibonaccisequence_ = fibonaccisequence;
  candidates_ = candidates;
};

// Getters
vector<string>
Fibonacci::get_fibonaccisequence(void) {
  return fibonaccisequence_;
}

vector<string>
Fibonacci::get_candidates(void) {
  return candidates_;
}

// Setters
void
Fibonacci::set_fibonaccisequence() {

};
