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
#include "keys.h"

//class Keys;

#ifndef SORT
#define SORT

template<class T>
class Sort {
private:

public:
  
  // Functions
  virtual void Sort_Vector(std::vector<T>& v, int size) = 0;
  virtual void Display(std::vector<T>& v) {
    for (unsigned i = 0; i < v.size(); i++) {
      std::cout << v[i].get_value() << "\n";
    }
  }
};

template<class T>
class Insertion_Sort : public Sort<T> {
private:
  /* data */
public:
  
  // Functions
  void Sort_Vector(std::vector<T>& v, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
      key = v[i].get_value();
      j = i;
      while (j > 0 && v[j - 1].get_value() > key) {
        v[j] = v[j - 1];
        j--;
      }
      // Insertion
      v[j] = key;
    }
  }  
};

template<class T>
class Selection_Sort : public Sort<T> {
private:
  /* data */
public:
  
  // Functions
  void Sort_Vector(std::vector<T>& v, int size) {
   int i, j, imin;
   for(i = 0; i < size - 1; i++) {
      imin = i;   //get index of minimum data
      for(j = i + 1; j < size; j++) {
        if(v[j].get_value() < v[imin].get_value()) {
          imin = j;
        }
      }
      Swap(v[i], v[imin]);
    }
  }

  void Swap(T &value1, T &value2) {
    T temp(value1);
    value1 = value2;
    value2 = temp;
  }
};


template<class T>
class Shell_Sort : public Sort<T> {
private:
  /* data */
public:
  
  // Functions
  void Sort_Vector(std::vector<T>& v, int size) {
    int alpha,j;
    T x;
    std::cout << "Introduzca la constante de reducción: \n";
    std::cin >> alpha;
    while (alpha > 1) {
      alpha = alpha / 2;
      for (int i = alpha; i < size; i++) {
        x = v[i];
        j = i;
        while ((j >= alpha) && (x.get_value() < v[j - alpha].get_value())) {
          v[j] = v[j - alpha];
          j = j - alpha;
        }
      }
      v[j] = x;
    }
  }
  /*
  void Swap(T &value1, T &value2) {
    T temp(value1);
    value1 = value2;
    value2 = temp;
  }*/
};







#endif