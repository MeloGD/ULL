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
#include <string>
#include "../include/keys.h"

int main(void) {
  int tablesize;
  int valueinsert;
  std::string letters;
  int valuesearch;
  int numvalues;
  int iterator = 0;
  bool nextstep = true;
  char type;
  bool keepsearching = true;
  char yesorno;
  std::cout << "Introduzca el tamaño de la Tabla Hash: " << std::endl;
  std::cout << "Recuerde que si quiere un rendimiento optimo, asigne un tamaño con valor primo para la funcion de modulo" << std::endl;
  std::cin >> tablesize;
  do {
    std::cout << "¿Desea usar funcion de modulo o aleatoria? Escriba 'm' para modulo, 'a' para aleatoria" << std::endl;
    std::cin >> type;
    if (type == 'm') {
      Module_Function<Clave> *func1 = new Module_Function<int>;
      Hash_Table<Clave> htable(tablesize, func1);
      std::cout << "Cuantos valores desea añadir" << std::endl;
      std::cin >> numvalues;
      do {
        std::cout << "¿Que valor desea añadir?" << std::endl;
        std::cin >> valueinsert >> letters;
        Keys claves(valueinsert, letters);
        htable.Insert(claves);
        iterator++;
      } while (iterator < numvalues);
      htable.Print();
      do {
        std::cout << "¿Desea buscar un valor? Escriba 'y' para si, 'n' para no" << std::endl;
        std::cin >> yesorno;
        if (yesorno == 'y'){
          std::cout << "¿Que valor?" << std::endl;
          std::cin >> valuesearch; 
          htable.Search(valuesearch);         
        } else {
          keepsearching = false;
          nextstep = false;
        }
      } while (keepsearching);
    } /* else {
      
      Pseudorandom_Function<int> *func2 = new Pseudorandom_Function<int>;
      Hash_Table<int> htable(tablesize, func2);
      std::cout << "Cuantos valores desea añadir" << std::endl;
      std::cin >> numvalues;
      do {
        std::cout << "¿Que valor desea añadir?" << std::endl;
        std::cin >> valueinsert;
        htable.Insert(valueinsert);
        iterator++;
      } while (iterator < numvalues);
      htable.Print();
      do {
        std::cout << "¿Desea buscar un valor? Escriba 'y' para si, 'n' para no" << std::endl;
        std::cin >> yesorno;
        if (yesorno == 'y'){
          std::cout << "¿Que valor?" << std::endl;
          std::cin >> valuesearch;
          htable.Search(valuesearch);
        } else {
          keepsearching = false;
          nextstep = false;
        }
      } while (keepsearching); 
    }   */
  } while (nextstep);
  return 0;
}
