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
#include <time.h>


int main(void) {
  int size;
  bool random;
  bool trace;
  int type;
  int iterator = 0;
  int value = 0;
  std::vector<int> vector;
  srand(time(NULL));

  std::cout << "Es programa ordena vectores.\n";
  std::cout << "¿De que tamaño desea el vector?\n";
  std::cin >> size;
  std::cout << "¿Desea introducir los valores a mano o generados de manera aleatoria?\n";
  std::cout << "  - Esciba 1 en caso afirmativo.\n";
  std::cout << "  - Esciba 0 en caso negativo.\n";
  std::cin >> random;
  if (random) {
    do {
      vector.push_back(rand() % 1000);
      iterator++;
    } while (iterator != size);
  } else {
    do {
      std::cout << "Introduzca el valor nº "<< iterator << "en el vector\n";
      std::cin >> value;
      vector.push_back(value);
      iterator++;
    } while (iterator != size);
  }
  std::cout << "¿Qué metodo de ordenación desea usar?\n";
  std::cout << "  - Inserción, escriba un 1.\n";
  std::cout << "  - Selección, escriba un 2.\n";
  std::cout << "  - Shell Sort, escriba un 3.\n";
  std::cin >> type;
  std::cout << "¿Desea ver la traza o el resultado final?\n";
  std::cout << "  - Esciba 1 en caso afirmativo.\n";
  std::cout << "  - Esciba 0 en caso negativo.\n";
  std::cin >> trace;

  switch (type) {
  case 1:
    if (trace) {
      std::cout << "\nOriginal: \n";
      Display(vector);
      std::cout << "\nLa traza: \n";
      Sort_Vector_Insertion_Trace(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);      
    } else {
      std::cout << "\nOriginal: \n";
      Display(vector);
      Sort_Vector_Insertion(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
    }
    break;
  case 2:
    if (trace) {
      
    } else {
      std::cout << "\nOriginal: \n";
      Display(vector);
      Sort_Vector_Insertion(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
    }
    break;
  case 3:
    if (trace) {
      
    } else {
      std::cout << "\nOriginal: \n";
      Display(vector);
      Sort_Vector_ShellSort(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
    }    
    break;    

  default:
    break;
  }


 /* 
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
  */
  return 0;
}
