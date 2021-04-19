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
#include "../include/templates.h"


int main(void) {

  std::vector<int> vector;
  //Shell_Sort<Keys<int>> vector_sort;
  vector.push_back(12);
  vector.push_back(213);
  vector.push_back(1);
  vector.push_back(1);
  vector.push_back(34);
  std::cout << "Desordenado: \n";
  Display(vector);

  std::cout << "Ordenado: \n";
  
  Sort_Vector_Insertion(vector,5);
  Display(vector);
  return 0;
}
