/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 6: Tabla hash con dispersión cerrada
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
   std::forward_list<Key> list_;
public:
  // Constructor
  Sll();

  // Functions
  bool Search(const Key& x) const;
  bool Add(const Key& x);
  void Set_Value(const Key& x);
  void Print_List(void);

};

// Constructor
template<class Key>
Sll<Key>::Sll() {}

// Functions
template<class Key>
bool
Sll<Key>::Search(const Key& x) const { 
  for (auto it = list_.begin(); it != list_.end(); it++ ) {
    if (*it == x) {
      return true;
    }   
  }
  return false;
}

// Functions
template<class Key>
void
Sll<Key>::Set_Value(const Key& x) { 
  list_.push_front(x);
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

template<class Key>
void
Sll<Key>::Print_List(void) {
  for (auto const& i : list_) {
    std::cout << "->" << i << "";
  }
}


#endif