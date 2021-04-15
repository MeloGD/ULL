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

#include <string>
#ifndef KEYS
#define KEYS
class Keys {
private:
  int value_;
  
public:
  Keys(int, std::string);
  ~Keys();

  // Getters
  int get_value(void); 
};

Keys::Keys(int value, std::string letters) {
  value_ = value;
}

Keys::~Keys() {

}

int Keys::get_value(void) {
  return value_;
}

#endif
