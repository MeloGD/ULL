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
  if (typeworld == 'i') {
    Infinite_World world (rows, columns);
    std::cout << "¿Cuantas hormigas desea ejecutar?" << std::endl;
    std::cin >> antcount;
    std::vector<Infinite_Ant> antlist;
    do {
      Infinite_Ant dohormiga;
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
    Universe *universo;
    Infinite_Universe infiniteuniverse(world, antlist);
    universo = &infiniteuniverse;
    universo->Run_Universe();
  } else {
    Finite_World world (rows, columns);
    std::cout << "¿Cuantas hormigas desea ejecutar?" << std::endl;
    std::cin >> antcount;
    std::vector<Finite_Ant> antlist;
    do {
      Finite_Ant dohormiga;
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
      std::cout << "forhead1";
      antlist.push_back(dohormiga);
      std::cout << "forhead2";
      steps++;
      std::cout << "forhead";
    } while (steps < antcount);
    Universe *universo;
    Finite_Universe finiteuniverse(world, antlist);
    universo = &finiteuniverse;
    universo->Run_Universe();
    
  }
  
  

  

  /*  
  Universe universo(mundo,antlist);
  universo.Run_Universe(typeworld);
  */
  
  

  return 0;
}
