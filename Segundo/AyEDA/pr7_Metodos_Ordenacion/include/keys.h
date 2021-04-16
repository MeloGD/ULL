/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 7: Metodos de ordenación
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/

#include <iostream>

#ifndef KEYS
#define KEYS
class Keys {
private:
  int value_;
  
public:
  Keys(int);
  ~Keys();

  // Getters
  int get_value(void); 

  // Overloads
  //friend std::
  //int& operator=(Keys &keys);
};

Keys::Keys(int value) {
  value_ = value;
}

Keys::~Keys() {

}

int Keys::get_value(void) {
  return value_;
}

/*
int& Keys::operator=(Keys &keys) {
  int value = keys.get_value();
  return value_;
}
*/
#endif
