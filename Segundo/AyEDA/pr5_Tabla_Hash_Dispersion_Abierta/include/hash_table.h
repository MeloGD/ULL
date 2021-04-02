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
  std::vector<Sll<Key>*> datavector_;
  Dispersion_Function<Key>* dispersionfuntion_;
public:
  Hash_Table(const unsigned size, Dispersion_Function<Key>& fuction);
  ~Hash_Table();

  // Functions
  bool Search(Key& x) const;
  bool Add(const Key& x) ;

};



#endif