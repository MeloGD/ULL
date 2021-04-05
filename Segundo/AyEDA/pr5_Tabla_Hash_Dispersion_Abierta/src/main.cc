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

  //Module_Function<int> *test2 = new Module_Function<int>;
  Pseudorandom_Function<int> *test2 = new Pseudorandom_Function<int>;
  
  Hash_Table<int> test(5, test2);
  int x = 1;
  bool y;
  y = test.Search(x);
  std::cout << "Puedo poner un 4? " << y << std::endl;
  return 0;
}
