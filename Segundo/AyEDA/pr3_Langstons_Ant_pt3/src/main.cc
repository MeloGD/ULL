/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 2: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará el tablero en blanco con la hormiga, esperando
que una tecla sea pulsada para inicializar)
$ make clean
*/

#include "../include/universe.h"
#include "../include/world.h"
#include "../include/ant.h"
#include "../include/jail.h"

#include <stdlib.h>
#include <string>

int main(void) {
  char typeworld;
  int rows, columns, antcount, steps = 0;
  std::cout << "Bienvenido a la Hormiga de Langton" << std::endl;
  std::cout << "¿Desea un mundo finito o infinito? Especifique dimensiones" << std::endl;
  std::cout << " - Ejemplo: i 3 3 (infinito 3x3)" << std::endl;
  std::cin >> typeworld >> rows >> columns;
  World mundo(rows,columns);
  std::cout << "¿Cuantas hormigas desea ejecutar?" << std::endl;
  std::cin >> antcount;
  std::vector<Ant> antlist;
  do {
    Ant dohormiga;
    int posx, posy = 0;
    std::string direction = " ";
    std::cout << "Introduzca las coordenadas x y, la oritación" << std::endl;
    std::cout << "de la hormiga: " << steps << std::endl;
    std::cout << "Ejemplo: 0 0 up" << std::endl;
    std::cin >> posx >> posy >> direction;
    dohormiga.set_currentx(posx);
    dohormiga.set_currenty(posy);
    direction = dohormiga.Fix_Direction(direction);
    dohormiga.set_direction(direction);
    antlist.push_back(dohormiga);
    steps++;
  } while (steps < antcount);
  
    
  Universe universo(mundo,antlist);
  universo.Run_Universe(typeworld);
  
  

  return 0;
}
