/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 5: Tabla hash con dispersión abierta
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/
#ifndef SIMPLE_LIST
#define SIMPLE_LIST

#include <forward_list>
#include <iostream>

template<class Key>
class Sll : public std::forward_list<Key> {
private:
   
public:
  // Constructor
  Sll();

  // Functions
  bool Search(const Key& x) const;
  bool Add(const Key& x);


};

// Constructor
template<class Key>
Sll<Key>::Sll() {}

// Functions
template<class Key>
bool
Sll<Key>::Search(const Key& x) const {
  for (auto it = this->begin(); it != this->end(); it++ ) {
    std::cout << ' '  << *it << std::endl;
    if (*it == x) {
      return true;
    }   
  }
  return false;
}

template<class Key>
bool
Sll<Key>::Add(const Key& x) {
  if (Search(x)) {
    return false;
  } else {
    return true;
  }
}
#endif