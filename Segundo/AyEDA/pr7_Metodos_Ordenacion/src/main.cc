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

#include <vector>
#include <iostream>
#include "../include/keys.h"
#include "../include/sort_vector.h"


int main(void) {
  /*
  int vectorsize;
  int valueinsert;
  int iterator = 0;
  bool nextstep = true;
  char type;
  char yesorno;
  std::cout << "Introduzca el tamaño de la Tabla Hash: " << std::endl;
  std::cout << "Recuerde que si quiere un rendimiento optimo, asigne un tamaño con valor primo para la funcion de modulo" << std::endl;
  std::cin >> vectorsize;
  do {
    std::cout << "¿Desea usar funcion de modulo o aleatoria? Escriba 'm' para modulo, 'a' para aleatoria" << std::endl;
    std::cin >> type;

  } while (nextstep);
  */
  std::vector<Keys<int>> vector;
  Shell_Sort<Keys<int>> vector_sort;
  Keys<int> Clave1(12);
  Keys<int> Clave2(213);
  Keys<int> Clave3(1);
  Keys<int> Clave4(34);
  vector.push_back(Clave1);
  vector.push_back(Clave2);
  vector.push_back(Clave3);
  vector.push_back(Clave4);
  std::cout << "Desordenado: \n";
  vector_sort.Display(vector);

  std::cout << "Ordenado: \n";
  
  vector_sort.Sort_Vector(vector,4);
  vector_sort.Display(vector);
  return 0;
}
