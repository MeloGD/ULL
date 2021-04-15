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

#ifndef SORT
#define SORT
template<class T>
class Sort {
private:

public:
  //Sort(std::vector<T>& v, unsigned size);
  //~Sort();
  
  // Functions
  virtual void Sort(std::vector<T> v, unsigned size) = 0;
  virtual void Display(void) = 0;
};

template<class T>
class Insertion_Sort : public Sort {
private:
  /* data */
public:
  Insertion_Sort();
  ~Insertion_Sort();
  
  // Functions
  void Sort(std::vector<T> v, unsigned size);
  void Display(void);

};







#endif