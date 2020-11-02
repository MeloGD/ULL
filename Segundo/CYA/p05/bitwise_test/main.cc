#include <iostream>
#include <bitset>
#include <bits/stdc++.h> 
#include <math.h>
  
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
// long f = (1<<63);

string hoa = "1000000000000000000000000000000000000000000000000000000000000000";
bitset<128> bset1(hoa);
cout << bset1 << endl;
unsigned long long int f = bset1.to_ullong();
unsigned long long int hehehe = pow(2 , 64);
unsigned long long int container = hehehe | 1;

cout << f << endl;
cout << container << endl;

/* ESTO NO SIRVE
string hoa = "100000000000000000000000000000000000000000000000000000000000000";
unsigned long long int f = stoll(hoa,nullptr,2);
cout << f << endl;
*/

unsigned long long int test = ;

}


