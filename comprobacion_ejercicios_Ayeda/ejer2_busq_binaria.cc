// g++ -g ejer2_busq_binaria.cc -o ejer2
#include <iostream>
#include <vector>

int bus_binaria2(int x, std::vector<float>& v, int ini, int fin) {
  int maxindex = fin;
  int indice = 0;
  int indicefinal = fin;
  float value = 0;
  float valuefinal = 1;
  int medio = (ini + fin) / 2;
  int pos = ini;
  int cercano = 0;
  while (ini < fin) {
    pos = (ini + fin) / 2;
    if (v[pos] < x) {
      ini = pos + 1;
    } else {
      fin = pos;
    }      
  }
  if ((int)v[ini] == x) {
    //return ini;
    // hasta aqui seria busqueda binaria normal, lo que hacemos ahora es buscar el valor más cercano al entero especificado
    indice = ini;
    while ((int)v[indice] == x) {
      value = v[indice] - x;
      if (value < valuefinal ) {
        valuefinal = value;
        indicefinal = indice;
      }
      indice++;
    }
    //return indicefinal;
  }
  if ((int)v[ini] == x) {
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
    if ((int)v[ini] == x) {
    //return ini;
    // hasta aqui seria busqueda binaria normal, lo que hacemos ahora es buscar el valor más cercano al entero especificado
      indice = ini;
      while ((int)v[indice] == x) {
        value = v[indice] - x;
        if (value < valuefinal ) {
          valuefinal = value;
          indicefinal = indice;
        }
        indice++;
      }
    
    }
  }
  if ((int)valuefinal == 1) {
    return -1;
  } else {return indicefinal;}
  
  
}

int main(void) {
  std::vector<float> v{1.0, 1.38 , 1.4 , 3 , 1.1 , 1.00001 ,0};
  std::cout << bus_binaria2(1,v,0,6) << std::endl; 
  return 0;
}
