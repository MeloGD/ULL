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
#include <stdlib.h>

#include <iostream>

int main(void) {
  //World mundo(80,80);
  //Ant hormiga (mundo,25,25,'>');
  //int iterator = 0;

  //mundo.Print_World();
  
  Vector_T<Vector_T<char>> test;
  test.Resize(5);
  for (int i = 0; i < test.get_size(); i++) {
    test[i].Resize(5);
  }

  for (int i = 0; i < test.get_size(); i++) {
    for (int j = 0; j < test[i].get_size(); j++) {
      test[i][j] = 'p';
    }
  }



  for (int i = 0; i < test.get_size(); i++) {
    for (int j = 0; j < test[i].get_size(); j++) {
      std::cout << test[i][j];
    }
     std::cout << std::endl;
  }
  
  //test.set_value(5,4);

  /*
  getchar();
  do {  
    system("clear");
    mundo.Print_World();
    hormiga.Run_Ant(mundo);
    iterator++;
    //getchar();
  } while (iterator < 11000);
  */
  return 0;
}
