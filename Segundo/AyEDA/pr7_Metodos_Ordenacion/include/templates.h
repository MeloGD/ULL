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
#include <string>
//#include "keys.h"

//class Keys;

#ifndef TEMPLATES
#define TEMPLATES

template<class T>
void Sort_Vector_Insertion(std::vector<T>& v, int size) {
    int  j;
    int key = 0;
    for (int i = 1; i < size; i++) {
      key = v[i];
      j = i;
      while (j > 0 && v[j - 1] > key) {
        v[j] = v[j - 1];
        j--;
      }
      // Insertion
      v[j] = key;
    }
} 


template<class T>
void Sort_Vector_Selection(std::vector<T>& v, int size) {
   int i, j, imin;
   for(i = 0; i < size - 1; i++) {
      imin = i;   //get index of minimum data
      for(j = i + 1; j < size; j++) {
        if(v[j] < v[imin]) {
          imin = j;
        }
      }
      Swap(v[i], v[imin]);
    }
}

template<class T>
void Sort_Vector(std::vector<T>& v, int size) {
  int delta, i,j;
  float alpha;
  T x;
  delta = size;
  std::cout << "Introduzca la constante de reducción: \n";
  std::cin >> alpha;
  for (delta = size * alpha ; delta > 0; delta = delta * alpha) {
    for (i = delta; i < size; i++) {
      for (j = i - delta; j >= 0; j -= delta) {
        if (v[j + delta] >= v[j]) {
          break;
        } else {
          Swap(v[j + delta], v[j]);
        }
      }
    }
  }
}

template<class T>
void Swap(T &value1, T &value2) {
    T temp(value1);
    value1 = value2;
    value2 = temp;
}

template<class T>
void Display(std::vector<T>& v) {  
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << "\n";
  }
} 


/*
    string test = "AB433AB";
    string integerpart = "";
    
    int intergervalue = 0;
    int alphavalue = 0;
    int finalvalue = 0;
    for (int i = 0; i < test.size(); i++) {
        if(isdigit(test[i])) {
            integerpart += test[i];
        } else {
            //cout << test.size() << endl;
            int power = (test.size() - 1) - i;
            alphavalue += test[i]  * (pow(10, power));
        } 
        
    }
    intergervalue = stoi(integerpart);
    finalvalue = intergervalue + alphavalue;
    cout << finalvalue << "\n";
*/

/* 
template<class T>
void Sort_Vector_Insertion(std::vector<T>& v, int size) {
    int  j;
    int value = 0;
    int value2 = 0;
    
    std::string key;
    for (int i = 1; i < size; i++) {
      for (unsigned k = 0; k < v[i].size(); k++) {
        value += v[i][k];
      }
      key = v[i];
      j = i;
      for (unsigned k = 0; k < v[j - 1].size(); k++) {
        value2 += v[j - 1][k];
      }
      while (j > 0 && value2 > value) {
        v[j] = v[j - 1];
        j--;
      }
      // Insertion
      v[j] = key;
    }
} 
*/


#endif