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

#include "../include/dispersion_function.h"
#include "../include/hash_table.h"
#include "../include/sll.h"
#include <iostream>

int main(void) {
  /*
  Sll<int> test;
  test.push_front(1);
  test.push_front(2);
  test.push_front(3);
  
  //test.insert_after(test.be - 1, 5);
  //std::forward_list<int>::iterator it;
  test.reverse();
  //test.pop_front();
  /*
  for (auto it = test.begin(); it != test.end(); it++ ) {
    std::cout << ' '  << *it << std::endl;
  }

  int x = 1;
  bool y;
  y = test.Add(x);
  Sll<int> test2;
  std::cout << "Puedo añadir? " << y << std::endl;
  */
  
  Module_Function<int> *test2 = new Module_Function<int>;
  


  Hash_Table<int> test(5, test2);
  int x = 3;
  bool y;
  y = test.Search(x);
  std::cout << "Puedo poner un 4? " << y << std::endl;
  return 0;
}
