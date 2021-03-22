/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 3: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/

#include "../include/universe.h"
#include "../include/world.h"
#include "../include/ant.h"
#include "../include/jail.h"

#include <stdlib.h>
#include <string>

int main(void) {
  char typeworld, anttype;
  int rows, columns, antcount, steps = 0;
  std::cout << "Bienvenido a la Hormiga de Langton" << std::endl;
  std::cout << "¿Desea un mundo finito o infinito? Especifique dimensiones" << std::endl;
  std::cout << " - Ejemplo: i 3 3 (infinito 3x3)" << std::endl;
  std::cin >> typeworld >> rows >> columns;
  if (typeworld == 'i') {
    Infinite_World world (rows, columns);
    std::cout << "¿Cuantas hormigas desea ejecutar?" << std::endl;
    std::cin >> antcount;
    std::vector<Ant*> antlist;
    do {
      std::cout << "¿Qué tipo de hormiga desea, normal o modificada?" << std::endl;
      std::cout << "Escriba 'n' para normal, 'r' para regular" << std::endl;
      std::cin >> anttype;
      if (anttype == 'n') {
        Regular_Ant *dohormiga1 = new Regular_Ant;
        int posx, posy = 0;
        std::string direction = " ";
        std::cout << "Introduzca las coordenadas x y, la oritación" << std::endl;
        std::cout << "de la hormiga: " << steps << std::endl;
        std::cout << "Ejemplo: 0 0 up (o right, left, down, upright, downright...)" << std::endl;
        std::cin >> posx >> posy >> direction;
        dohormiga1->set_currentx(posx);
        dohormiga1->set_currenty(posy);
        direction = dohormiga1->Fix_Direction(direction);
        dohormiga1->set_direction(direction);
        antlist.push_back(dohormiga1);
        //delete dohormiga1;
        
        steps++;
      } else {
        Modified_Ant *dohormiga2 = new Modified_Ant; 
        int posx, posy = 0;
        std::string direction = " ";
        std::cout << "Introduzca las coordenadas x y, la oritación" << std::endl;
        std::cout << "de la hormiga: " << steps << std::endl;
        std::cout << "Ejemplo: 0 0 up (o right, left, down, upright, downright...)" << std::endl;
        std::cin >> posx >> posy >> direction;
        dohormiga2->set_currentx(posx);
        dohormiga2->set_currenty(posy);
        direction = dohormiga2->Fix_Direction(direction);
        dohormiga2->set_direction(direction);
        antlist.push_back(dohormiga2);
        
        steps++;
      } 
    } while (steps < antcount); 
    
    Universe *universo;
    Infinite_Universe infiniteuniverse(world, antlist);
    universo = &infiniteuniverse;
    universo->Run_Universe();
  } else {
    /*
    Finite_World world (rows, columns);
    std::cout << "¿Cuantas hormigas desea ejecutar?" << std::endl;
    std::cin >> antcount;
    std::vector<Ant> antlist;
    do {
      Ant dohormiga;
      int posx, posy = 0;
      std::string direction = " ";
      std::cout << "Introduzca las coordenadas x y, la oritación" << std::endl;
      std::cout << "de la hormiga: " << steps << std::endl;
      std::cout << "Ejemplo: 0 0 up (o right, left, down)" << std::endl;
      std::cin >> posx >> posy >> direction;
      dohormiga.set_currentx(posx);
      dohormiga.set_currenty(posy);
      direction = dohormiga.Fix_Direction(direction);
      dohormiga.set_direction(direction);
      antlist.push_back(dohormiga);
      steps++;
    } while (steps < antcount);
    Universe *universo;
    Finite_Universe finiteuniverse(world, antlist);
    universo = &finiteuniverse;
    universo->Run_Universe();
    */
  }
  return 0;
}
