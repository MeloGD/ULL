/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 5: Tabla hash con dispersión abierta
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/
#ifndef DISPERSION
#define DISPERSION

#include <random>

template<class Key>
class Dispersion_Function {
private:
    /* data */
public:
  virtual void set_size(const unsigned x) = 0;
  virtual unsigned operator() (const Key& k) const = 0;
};

template<class Key>
class Module_Function : public Dispersion_Function<Key> {
private:
    unsigned datasize_;
public:
  Module_Function() {}
  Module_Function(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k) const {
    return k % datasize_;
  }
};

template<class Key>
class Pseudorandom_Function : public Dispersion_Function<Key> {
private:
    unsigned datasize_;
public:
  Pseudorandom_Function() {}
  Pseudorandom_Function(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k) const {
    //srand la puedo llamar desde el main, cambiar 
    srand(time(NULL));
    return rand() % datasize_;
  }
};







#endif