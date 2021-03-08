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
#include "../include/vector_t_2.h"
//#include <stdlib.h>
#include<bits/stdc++.h>
#include <iostream>

int main(void) {
  //World mundo(80,80);
  //Ant hormiga (mundo,25,25,'>');
  //int iterator = 0;

  //mundo.Print_World();
  
  Vector_t<Vector_t<int>> test;
  
  test.resize(5);
  
  for (int i = 0; i < test.get_size() ; i++) {
    test[i].resize(5);
  }
  //test[-1][-1] = 55;

  Vector_t<int> prueba;
  prueba.resize(1);
  prueba[-1] = 2;
  std::cout << prueba[-1] << std::endl;
  //std::cout << test[-1][-1] << std::endl;
  /*
  for (int i = -2; i < test.get_size() - 5; i++) {
    for (int j = -2; j < test[i].get_size() - 5; j++) {
      test[i][j] = i;
    }
  }
  */
  /*
  test.resize(6);
  for (int i = 0; i < test.get_size(); i++) {
    test[i].resize(5);
  }
  */ 
  /*
  for (int i = -5; i < copia.get_size() - 5; i++) {
    for (int j = -5; j < copia[i].get_size() - 5; j++) {
      test[i][j] = copia[i].get_val(j);
    }
  }
  */
  /*
  for (int i = -5; i < test.get_size() - 5; i++) {
    for (int j = -5; j < test[i].get_size() - 5; j++) {
      std::cout << test[i][j];
    }
     std::cout << std::endl;
  }
  */
  return 0;
}
