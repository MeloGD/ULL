// g++ -g ejer1_busq_binaria.cc -o ejer1
#include <iostream>
#include <vector>

int bus_binaria2(int x, std::vector<int>& v, int ini, int fin, int primero, int ultimo) {
  int pos = ini;
  while (ini < fin) {
    pos = (ini + fin) / 2;
    if (v[pos] < x) {
      ini = pos + 1;
    } else {
      fin = pos;
    }      
  }
  if (v[ini] == x) {
    primero = ini;
    while (v[primero] == x) {
      std::cout << primero << '\n';
      primero++;
    }
    return 0;
  } 
  else {return -1;}
}

int main(void) {
  std::vector<int> v{0,1,1,2,2,4,4,4};
  bus_binaria2(4,v,0,7,0,7);
  return 0;
}
