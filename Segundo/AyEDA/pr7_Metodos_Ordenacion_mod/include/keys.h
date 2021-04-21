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

template<class T>
class Keys {
private:
  T value_;
  
public:
  Keys();
  Keys(T);
  ~Keys();

  // Getters
  T& get_value(void); 

  // Overloads
  //friend std::
  //int& operator=(Keys &keys);
};

template<class T>
Keys<T>::Keys() {
  
}

template<class T>
Keys<T>::Keys(T value) {
  value_ = value;
}

template<class T>
Keys<T>::~Keys() {

}

template<class T>
T& Keys<T>::get_value(void) {
  return value_;
}

/*
int& Keys::operator=(Keys &keys) {
  int value = keys.get_value();
  return value_;
}
*/
#endif
