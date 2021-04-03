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
#include <vector>
#include "dispersion_function.h"
#include "sll.h"
#include <forward_list>
#ifndef HASH  
#define HASH
template<class Key>
class Hash_Table {
private:
  unsigned tablesize_;
  std::vector<std::forward_list<Key>*> datavector_;
  Dispersion_Function<Key>* dispersionfunction_;
public:
  Hash_Table(const unsigned size, Dispersion_Function<Key>& fuction);
  ~Hash_Table();

  // Getters
  const unsigned get_tablesize(void);
  // Setters
  void set_tablesize(const unsigned size);
  void set_datavector(void); 
  void set_dispersionfuction(const Dispersion_Function<Key>& fuction);
  // Functions
  bool Search(Key& x) const;
  bool Add(const Key& x) ;

};

// Constructor
template<class Key>
Hash_Table<Key>::Hash_Table(const unsigned size, Dispersion_Function<Key>& fuction) {
  set_tablesize(size);
  set_datavector(void);
  set_dispersionfuction(fuction);
}

// Getters
template<class Key>
const unsigned Hash_Table<Key>::get_tablesize(void) {
  return tablesize_;
}

// Setters
template<class Key>
void Hash_Table<Key>::set_tablesize(const unsigned size) {
  tablesize_ = size;
}

template<class Key>
void Hash_Table<Key>::set_datavector(void) {
  datavector_.resize(get_tablesize());
}

template<class Key>
void Hash_Table<Key>::set_dispersionfuction(const Dispersion_Function<Key>& fuction) {
  dispersionfunction_ = fuction;
}

// Functions
template<class Key>
bool Hash_Table<Key>::Search(Key& x) const {
  for (unsigned i = 0; i < datavector_.size(); i++) {
    datavector_[0];
  }
}

#endif