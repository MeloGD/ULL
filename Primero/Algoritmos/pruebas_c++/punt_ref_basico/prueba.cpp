#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int v;
  int *p;
  int  &n = v;

  v = 5;
  p = &v; //p contiene el valor de la dirreccion de memoria de v

  //punteros
  cout << "La dirección de memoria de la variable v es:" << p << endl;
  cout << "El valor de la dirección de memoria de v es:" << *p << endl; //aquí accedemos al valor de la dirección de memoria guarda en p
  cout << "La dirección de memoria del puntero p es:" << &p << endl;

  //referencias
  cout << "El valor de n haciendo referencia a v es:" << n << endl;
  n = 10;
  cout << "El valor de la dirección de memoria de v es:" << *p << endl; //aquí accedemos al valor de la dirección de memoria guarda en p
  cout << "El valor de n haciendo referencia a v es:" << n << endl;
  cout << "La dirección de memoria de la referencia n es:" << &n << endl; //será la misma que v



  return 0;
}
