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
(una vez compilado, se mosntrará un menú de configuracion para generar el vector y el metodo de ordenación a usar.)
$ make clean
*/
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <random>
#include <typeinfo>

#ifndef TEMPLATES
#define TEMPLATES

template<class T>
void Swap(T &value1, T &value2) {
    T temp(value1);
    value1 = value2;
    value2 = temp;
}

template<class T>
void Display(std::vector<T>& v) {  
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << "Pos: " << i << " = " << v[i].get_value() << "   ";
  }
  std::cout << "\n";
} 


template<class T>
long String_Value(T data) { 
  std::string integerpart = "";
  long intergervalue = 0;
  long alphavalue = 0;
  long finalvalue = 0;
  long auxiliar = 0;
  for (unsigned i = 0; i < data.size(); i++) {
      if(isdigit(data[i])) {
          integerpart += data[i];
      } else {
          int power = (data.size() - 1) - i;
          alphavalue += int(data[i]) * (pow(10, power));
      } 
  }
  intergervalue = stoi(integerpart);
  finalvalue = intergervalue + alphavalue;
  return finalvalue;
} 

template<class T>
void Display_Values(std::vector<T>& v) {  
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << "Pos: " << i << " = " << String_Value(v[i].get_value()) << "   ";
  }
  std::cout << "\n";
} 

std::string Build_String() {
  std::string key = "";
  std::string str1 = "";
  std::string str2 = "";
  std::string str3 = "";
  std::string alphab("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  std::string num("0123456789");
  std::random_device rd;
  std::mt19937 generator(rd());
  shuffle(alphab.begin(), alphab.end(), generator);
  shuffle(num.begin(), num.end(), generator);
  str1 = "DNI";
  str2 = num.substr(0,8);
  shuffle(alphab.begin(), alphab.end(), generator);
  str3 = alphab.substr(0,1);
  key = str1 + str2 + str3;
  return key;  
}

template<class T>
void Sort_Vector_Insertion(std::vector<T>& v, int size) {
  int  j;
  T key;
  for (int i = 1; i < size; i++) {
    key = v[i];
    j = i;
    while (j > 0 && String_Value(v[j - 1].get_value()) > String_Value(key.get_value())) {
      v[j] = v[j - 1];
      j--;
    }
    v[j] = key;
  }
}

/*
template<class T>
void Sort_Vector_Insertion_Trace(std::vector<T>& v, int size) {
    int  j;
    int key = 0;
    for (int i = 1; i < size; i++) {
      std::cout << "\nPara la iteración, " << i << " guardamos el valor de v[" << i << "] = "<< v[i] <<", en una variable 'key' para no perder su valor.\n";
      key = v[i];
      j = i;
      while (j > 0 && v[j - 1] > key) {
        std::cout << "Examinamos el nuevo segmento dado que se cumple que:\n";
        std::cout << "  - v[" << j-1 << "] = " << v[j-1] << " > " << " v[" << i << "]" << " = " << key << "\n";
        std::cout << "A v[" << j << "] le asignamos entonces el valor de v[" << j-1 << "] : " << v[j] << " <- " << v[j-1] << "\n";
        v[j] = v[j - 1];
        j--;
      }
      std::cout << "Ahora, no se cumple la condición para examinar el segmento, porque:\n";
      std::cout << "  - v[" << j - 1 << "] = " <<  v[j-1] << " < v[" << i << "] = " << v[i]  << "\n";
      v[j] = key;
      std::cout << "A v[" << j << "] le asignamos entonces el valor de de 'key' para completar el intercambio:  v[" << j << "] " << " -> " << key << "\n";
      std::cout << "El vector queda así: \n";
      Display(v);
      std::cout << "\n";
    }
} */

/*
template<class T>
void Sort_Vector_Selection(std::vector<T>& v, int size) {
   int i, j, imin;
   for(i = 0; i < size - 1; i++) {
      imin = i;   
      for(j = i + 1; j < size; j++) {
        if(v[j] < v[imin]) {
          imin = j;
        }
      }
      Swap(v[i], v[imin]);
    }
}*/
/*
template<class T>
void Sort_Vector_Selection_Trace(std::vector<T>& v, int size) {
   int i, j, imin;
   for(i = 0; i < size - 1; i++) {
      std::cout << "\nPara la iteración " << i << ", inicializamos en una variable auxiliar el valor de la iteración (imin = " << i << ") como el indice minimo. \n";
      imin = i;   
      for(j = i + 1; j < size; j++) {
        std::cout << "Miramos en el segundo bucle las posiciones siguientes, en este caso v[" << j << "], comparando con la anterior v[" << imin << "]\n";
        if(v[j] < v[imin]) {
          std::cout << "Se cumple que v[" << j << "] < v[" << imin << "] --> " << v[j] << " < " << v[imin] << "\n";
          imin = j;
          std::cout << "Actualizamos la variable imin con el indice del nuevo valor minimo (imin = " << imin << ")\n";
        }
      }
      std::cout << "Intecambiamos v[" << i << "] por v[" << imin << "] --> " << v[i] << " <--> " << v[imin] << "\n";
      Swap(v[i], v[imin]);
      std::cout << "El vector queda así: \n";
      Display(v);
      std::cout << "\n";
    }
}
*/
/*
template<class T>
void Sort_Vector_ShellSort(std::vector<T>& v, int size) {
  int delta, i,j;
  float alpha;
  //T x;
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
}*/

/*
template<class T>
void Sort_Vector_ShellSort_Trace(std::vector<T>& v, int size) {
  int delta, i,j;
  float alpha;
  //T x;
  delta = size;
  std::cout << "Introduzca la constante de reducción (funciona mejor con un valor de 0.45):  \n";
  std::cin >> alpha;
  for (delta = size * alpha ; delta > 0; delta = delta * alpha) {
    std::cout << "Pasada delta = " << delta << " \n";
    for (i = delta; i < size; i++) {
      for (j = i - delta; j >= 0; j -= delta) {
        if (v[j + delta] >= v[j]) {
          break;
        } else {
          std::cout << "Se cumple que para una distancia " << delta << ", v[" << j + delta << "] < v[" << j << "] --> " <<  v[j + delta] << " <--> " << v[j] << "\n";
          std::cout << "Intecambiamos v[" << j + delta << "] por v[" << j << "] --> " << v[j + delta] << " <--> " << v[j] << "\n";
          Swap(v[j + delta], v[j]);
        }
      }
    }
  }
}
*/

#endif