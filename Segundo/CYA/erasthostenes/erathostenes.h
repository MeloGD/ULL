/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Computabilidad y Algoritmia.

Práctica 1: Criba de Erastótenes
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
*/

#include <iostream>
#include <vector>

using namespace std;

// Vector de numeros enteros
vector<int> v_numwhole;
// Vector de bools de los numeros primos                  
vector<bool> v_bprime;
// Vector de copia de v_bprime. Lo necesitamos para sacar la solución
// no modificada.                  
vector<bool> v_bprimecop;

char debvar;
bool debugvar;
int stopvar;

void Build(int n);
void Sieve(int n);
void Remove(int n);
void Quit(void);
void Copy(int n);
void Show(void);
bool Debug(char);



// De ser true, para la construcción de primos en un número que se le haya
// especificado.
bool Debug(char debvar) {
  if (debvar == 'y') {
    debugvar = true;
    return true; 
  } else {
    debugvar = false;
    return false;
  }
}



// Construye el vector de enteros
void Build(int n) {
  for (int i = 1 ; i <= n ; i++) {
    v_numwhole.push_back(i);
  }
}



// Recorre los enteros y marca si son primos o no.
void Sieve(int n) {
  v_bprime.resize(n);
  // La primera posición del vector coincide con el 1, por lo tanto,
  // no va a ser primo y lo marcamos como false;             
  v_bprime[0] = false;

  for(int i = 1 ; i <= n ; ++i) {
    v_bprime[i] = true;
  }   
  for (int i = 2 ; i * i <= n ; ++i) {        
    if (v_bprime[i - 1]) {
      if (debugvar){
        if (i <= stopvar) {
          Remove(i);
        }
      }
      else{
        Remove(i);
      }
    }
  }
  // Llamamos a la función Copy para poder copiar la solucíon 
  // que deseamos en Mostrar(), dado que vamos a modificar 
  // el tamaño y las posiciones del vector v_bprime.
  Copy(n);     
}



// Recorre los multiplos (2x2,2x3,...) y los marca como
// no primos si se cumple la condición.
void Remove(int n) {
  for (int h = 2 ; n * h <= v_bprime.size() ; ++h) {     
    v_bprime[n * h - 1] = false;                    
  }
}



// Quita del vector de enteros y primos los resultados
// que no sean primos.
void Quit(void) {
  for (int i = 0 ; i < v_numwhole.size() ; i++) {   
    if (!v_bprime[i]) {   
      v_numwhole.erase(v_numwhole.begin() + i);
      v_bprime.erase(v_bprime.begin() + i);
      i--;
    } 
  }
}



void Copy(int n) {
  v_bprimecop.resize(n);
  for (int i = 0 ; i < n ; i++) {
    v_bprimecop[i] = v_bprime[i];
  }  
}



// Muestra la solución por pantalla.
void Show(void) {
  cout << "La lista de números es la siguiente: " << endl;
  for (int i = 0 ; i < v_bprimecop.size() ; i++) {
    cout << i + 1 << ":";
    if (v_bprimecop[i] == true) {
      cout << "Es primo.  ";
    } else {
      cout << "No es primo.  ";
    }
  }
  cout << endl;
  cout << endl;
  cout << "La lista de números primos resultante es: " << endl;
  for (int i = 0 ; i < v_numwhole.size() ; i++) {
    cout << v_numwhole[i] << " ";
  }
  cout << endl;  
}
