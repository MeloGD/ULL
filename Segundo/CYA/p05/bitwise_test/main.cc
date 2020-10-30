#include <iostream>
#include <bitset>
#include <bits/stdc++.h> 
  
using namespace std;

int main(void){
  // <<0 <- este valor de aqui es el string leido menos 1
  unsigned long x = (1<<0); // x = 1 --> {1}
  unsigned long y = (1<<3); // y = 1000 --> {4}
  
  unsigned long c = x | y;  // x + y
  cout << c << endl; //1001 --> {1,4}
  string d = std::bitset<8>(c).to_string(); // añade 0 delante hasta hacer los 8 bits
  cout << d << endl;

  // aqui si hago un reverse saco los datos de manera 
  // ordenada, sin tener que hacer este for
  reverse(d.begin(), d.end());
  for (int i = 0; i < d.size(); i++) {
    if (d[i] == '1') {
      cout << "EL numero es " << i + 1 << endl;
    } 
}