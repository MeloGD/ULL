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
(una vez compilado, se mosntrará un menú de configuracion para generar el vector y el metodo de ordenación a usar.)
$ make clean
*/
#include <vector>
#include <iostream>
#include "../include/templates.h"
#include "../include/keys.h"
#include <string>
#include <time.h>


int main(void) {
  int size;
  bool random;
  bool trace;
  int type;
  int iterator = 0;
  std::string value;
  
  std::vector<Keys<std::string>> vector;
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
      //vector.push_back(rand() % 1000);
      Keys<std::string> key(Build_String());
      vector.push_back(key);
      iterator++;
    } while (iterator != size); 
  } else {
    do {
      std::cout << "Introduzca el valor nº "<< iterator << " en el vector\n";
      std::cin >> value;
      Keys<std::string> key(value);
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
      Display_Values(vector);
      std::cout << "\nLa traza: \n";
      //Sort_Vector_Insertion_Trace(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
      Display_Values(vector);      
    } else {
      std::cout << "\nOriginal: \n";
      Display(vector);
      Display_Values(vector);
      Sort_Vector_Insertion(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
      Display_Values(vector);
    }
    break;
  case 2:
    if (trace) {
      std::cout << "\nOriginal: \n";
      Display(vector);
      std::cout << "\nLa traza: \n";
      //Sort_Vector_Selection_Trace(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);        
    } else {
      std::cout << "\nOriginal: \n";
      Display(vector);
      //Sort_Vector_Insertion(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
    }
    break;
  case 3:
    if (trace) {
      std::cout << "\nOriginal: \n";
      Display(vector);
      std::cout << "\nLa traza: \n";
      //Sort_Vector_ShellSort_Trace(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);          
    } else {
      std::cout << "\nOriginal: \n";
      Display(vector);
     // Sort_Vector_ShellSort(vector,size);
      std::cout << "\nOrdenado: \n";
      Display(vector);
    }    
    break;    

  default:
    break;
  }

  return 0;
}
