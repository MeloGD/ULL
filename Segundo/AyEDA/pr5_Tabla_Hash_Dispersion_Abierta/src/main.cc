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
  int tablesize;
  int valueinsert;
  int valuesearch;
  int numvalues;
  bool nextstep = true;
  char type;
  char keepruning;
  char search;
  std::cout << "Introduzca el tamaño de la Tabla Hash: " << std::endl;
  std::cout << "Recuerde que si quiere un rendimiento optimo, asigne un tamaño con valor primo para el caso aleatorio" << std::endl;
  std::cin >> tablesize;
  do {
    std::cout << "¿Desea usar funcion de modulo o aleatoria? Escriba 'm' para modulo, 'a' para aleatoria" << std::endl;
    std::cin >> type;
    if (type == 'm') {
      Module_Function<int> *func1 = new Module_Function<int>;
      Hash_Table<int> htable(tablesize, func1);
      std::cout << "Cuantos valores desea añadir" << std::endl;
      std::cin >> numvalues;
      std::cout << "¿Que valor desea añadir?" << std::endl;
      std::cin >> valueinsert;
      htable.Insert(valueinsert);
    } else {
      Pseudorandom_Function<int> *func2 = new Pseudorandom_Function<int>;
      Hash_Table<int> htable(tablesize, func2);
      std::cout << "¿Que valor desea añadir?" << std::endl;
      std::cin >> valueinsert;
      htable.Insert(valueinsert);
    }

    std::cout << "¿Desea seguir introduciendo/buscando valores? (y/n)" << std::endl;
    std::cin >> keepruning;
    if (keepruning == 'n') {
      nextstep = false;
    } 
    
    
  } while (nextstep);
  
  /*
  //Module_Function<int> *test2 = new Module_Function<int>;
  Pseudorandom_Function<int> *test2 = new Pseudorandom_Function<int>;
 
  int x = 1;
  bool y;
  y = test.Add(x);
  std::cout << "Puedo poner un 1? " << y << std::endl;
  test.Insert(x);
  y = test.Add(x);
  std::cout << "Puedo poner un 1? " << y << std::endl;
  */
  return 0;
}
