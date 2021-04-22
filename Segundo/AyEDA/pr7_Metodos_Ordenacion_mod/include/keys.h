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

#include <iostream>


#ifndef KEYS
#define KEYS


class Keys {
private:
  char str1_;
  int value_;
  char str2_;
  
public:
  Keys();
  Keys(char str1, int value, char str2);
  ~Keys();

  // Getters
  char& get_str1(void); 
  int& get_value(void); 
  char& get_str2(void);


  // Setters
  void set_str1(char str); 
  void set_value(int value); 
  void set_str2(char str);

  // Overloads
  //friend std::
  //int& operator=(Keys &keys);
};


Keys::Keys() {
  
}

Keys::Keys(char str1, int value, char str2) {
  str1_ = str1;
  value_ = value;
  str2_ = str2;
}

Keys::~Keys() {

}


char& Keys::get_str1(void) {
  return str1_;
}


int& Keys::get_value(void) {
  return value_;
}

char& Keys::get_str2(void) {
  return str2_;
}


void Keys::set_str1(char str) {
  str1_ = str;
}


void Keys::set_value(int value) {
  value_ = value;
}

void Keys::set_str2(char str) {
  str2_ = str;
}

/*
int& Keys::operator=(Keys &keys) {
  int value = keys.get_value();
  return value_;
}
*/
#endif
