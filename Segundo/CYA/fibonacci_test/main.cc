#include <iostream> 
#include <vector>

#define Max 35

using namespace std; 
  
// Returns n-th Fibonacci word 
vector<string> vFibSeq;

string wordFib(int n) {
  if (n == 1) return "a";
  if (n == 2) return "b";
  return wordFib(n - 2) + wordFib(n - 1);
}

void build(void) {
  for (int i = 1; i <= Max; i++) {
    vFibSeq.push_back(wordFib(i));
  }
}

void Check(string str) {
  bool check = false;
  for (int i = 0; i < vFibSeq.size(); i++) {
    if (str == vFibSeq[i]) {
      cout << "Esta en Fibonacci y es la nº: " << i + 1 << endl;
      check = true;
    }
  }
  if (check == false) {
    cout << "No está en Fibonacci." << endl;
  } 
}

int main(int argc, char const *argv[]) {
  string test = argv[1];
  build();
  Check(test); 
     
  return 0;
}
