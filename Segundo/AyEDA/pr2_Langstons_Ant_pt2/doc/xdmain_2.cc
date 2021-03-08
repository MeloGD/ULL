/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 1: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará el tablero en blanco con la hormiga, esperando
que una tecla sea pulsada para inicializar)
$ make clean
*/

//#include "../include/world.h"
//#include "../include/ant.h"
//#include "../include/jail.h"
#include "../include/vector_t.h"
//#include <stdlib.h>
#include<bits/stdc++.h>
#include <iostream>

int main(void) {

  Vector_T<Vector_T<int>> test;
  Vector_T<Vector_T<int>> copia;
  
  test.Resize(5);
  copia.Resize(5);
  
  for (int i = 0; i < test.get_size(); i++) {
    test[i].Resize(5);
    copia[i].Resize(5);
  }
  
  for (int i = 0; i < test.get_size(); i++) {
    for (int j = 0; j < test[i].get_size(); j++) {
      test[i][j] = i;
      copia[i][j] = test[i][j];
    }
  }
  
  test.Resize(6);
  for (int i = 0; i < test.get_size(); i++) {
    test[i].Resize(5);
  }
   
  for (int i = 0; i < copia.get_size(); i++) {
    for (int j = 0; j < copia[i].get_size(); j++) {
      test[i+1][j] = copia[i][j]; 
    }
  }
  
  std::cout << "Vector original" << std::endl;
  for (int i = 0; i < test.get_size(); i++) {
    for (int j = 0; j < test[i].get_size(); j++) {
      std::cout << test[i][j];
    }
     std::cout << std::endl;
  }
  
  std::cout << "Vector de copia" << std::endl;
  for (int i = 0; i < copia.get_size(); i++) {
    for (int j = 0; j < copia[i].get_size(); j++) {
      std::cout << copia[i][j];
    }
     std::cout << std::endl;
  }
  
  return 0;
}
