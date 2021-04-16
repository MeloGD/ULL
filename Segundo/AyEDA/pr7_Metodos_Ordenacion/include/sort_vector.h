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

class Keys;

#ifndef SORT
#define SORT
template<class T>
class Sort {
private:

public:
  //Sort(std::vector<T>& v, unsigned size);
  //~Sort();
  
  // Functions
  virtual void Sort_Vector(std::vector<T>& v, unsigned size) = 0;
  virtual void Display(std::vector<T>& v) = 0;
};

template<class T>
class Insertion_Sort : public Sort<T> {
private:
  /* data */
public:
  //Insertion_Sort();
  //~Insertion_Sort();
  
  // Functions
  void Sort_Vector(std::vector<T>& v, unsigned size) {
    int key, j;
    for (unsigned i = 1; i < size; i++) {
      key = v[i].get_value();
      j = i;
      while (j > 0 && v[j - 1].get_value() > key) {
        v[j] = v[j - 1];
        j--;
      }
      v[j] = key;
    }
    
  }

  void Display(std::vector<T>& v) {
    for (unsigned i = 0; i < v.size(); i++) {
      std::cout << v[i].get_value() << "\n";
    }
  }
  
};







#endif