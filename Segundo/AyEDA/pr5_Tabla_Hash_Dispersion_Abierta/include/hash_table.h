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

#ifndef HASH  
#define HASH
template<class Key>
class Hash_Table {
private:
  unsigned tablesize_;
  std::vector<Sll<int>> datavector_;
  Dispersion_Function<Key>* dispersionfunction_;
public:
  Hash_Table(const unsigned size, Dispersion_Function<Key>* fuction);
  ~Hash_Table();

  // Getters
  const unsigned get_tablesize(void);
  // Setters
  void set_tablesize(const unsigned size);
  void set_datavector(void); 
  void set_dispersionfuction(Dispersion_Function<Key>* fuction);
  // Functions
  bool Search(Key& x) const;
  bool Add(const Key& x) ;

};

// Constructor
template<class Key>
Hash_Table<Key>::Hash_Table(const unsigned size, Dispersion_Function<Key>* fuction) {
  set_tablesize(size);
  set_datavector();
  set_dispersionfuction(fuction);
}

// Destructor
template<class Key>
Hash_Table<Key>::~Hash_Table() {

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
  //datavector_.resize(get_tablesize());
  unsigned iterator = 0;
  
  while (iterator < get_tablesize()) {
    Sll<Key> aux;
    if (iterator == 2) {
      aux.Set_Value(2);
    }
    
    aux.Set_Value(1);
    datavector_.push_back(aux);
    iterator++;
  }
  
}

template<class Key>
void Hash_Table<Key>::set_dispersionfuction(Dispersion_Function<Key>* function) {
  dispersionfunction_ = function;
}

// Functions
template<class Key>
bool Hash_Table<Key>::Search(Key& x) const { 
  for (unsigned i = 0; i < datavector_.size(); i++) {
    if (datavector_[i].Search(x)) {
      return true;
    }
  }
}

#endif