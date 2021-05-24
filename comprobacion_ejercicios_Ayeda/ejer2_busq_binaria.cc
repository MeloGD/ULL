// g++ -g ejer2_busq_binaria.cc -o ejer2
#include <iostream>
#include <vector>
#include <math.h>

int bus_binaria2(int x, std::vector<float>& v, int ini, int fin) {
  int medio = (ini + fin) / 2;
  int pos = ini;
  int auxfin = medio;
  int cercano1 = 0;
  int cercano2 = 0;
  while (ini < fin) {
    pos = (ini + fin) / 2;
    if (v[pos] < x) {
      ini = pos + 1;
    } else {
      fin = pos;
    }
  }
  if (ini == 0) {
    cercano1 = ini;
  } else {
    if ((v[ini] - x) < (x - v[ini - 1])) {
      cercano1 = ini;
    } else {
      cercano1 = ini - 1;
    }
  }
  ini = medio + 1;
  pos = ini;
  while (ini < fin) {
    pos = (ini + fin) / 2;
    if (v[pos] < x) {
      ini = pos + 1;
    } else {
      fin = pos;
    }
  }
  if (ini == medio + 1) {
    cercano2 = ini;
  } else {
    if ((v[ini] - x) < (x - v[ini - 1])) {
      cercano2 = ini;
    } else {
      cercano2 = ini - 1;
    }
  }
  if (std::fabs(x - v[cercano1]) < std::fabs(x - v[cercano2])) {
    return cercano1;
  } else {
    return cercano2;
  }
}

int main(void) {
  std::vector<float> v{1.0, 1.38 , 1.4 , 8 , 1.5 , 1.00001 ,0};
  std::cout << bus_binaria2(3,v,0,6) << std::endl; 
  return 0;
}
