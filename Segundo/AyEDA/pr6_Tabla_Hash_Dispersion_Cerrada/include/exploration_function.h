/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 6: Tabla hash con dispersión cerrada
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/

#ifndef EXPLORATION
#define EXPLORATION

#include <random>

template<class Key>
class Exploration_Function {
private:
    /* data */
public:
  virtual void set_size(const unsigned x) = 0;
  virtual unsigned operator() (const Key& k, unsigned i) const = 0;
};


template<class Key>
class Linear : public Exploration_Function<Key> {
private:
    unsigned datasize_;
public:
  Linear() {}
  Linear(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k, unsigned i) const {
    return i;
  }
};

template<class Key>
class Quadratic : public Exploration_Function<Key> {
private:
    unsigned datasize_;
public:
  Linear() {}
  Linear(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k, unsigned i) const {
    return i;
  }
};

template<class Key>
class Quadratic : public Exploration_Function<Key> {
private:
    unsigned datasize_;
public:
  Linear() {}
  Linear(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k, unsigned i) const {
    return i;
  }
};

template<class Key>
class Double_Dispersion : public Exploration_Function<Key> {
private:
    unsigned datasize_;
public:
  Double_Dispersion() {}
  Double_Dispersion(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k, unsigned i) const {
    return i;
  }
};

template<class Key>
class Redispersion : public Exploration_Function<Key> {
private:
    unsigned datasize_;
public:
  Double_Dispersion() {}
  Double_Dispersion(const unsigned n): datasize_(n) {}
  void set_size(const unsigned x) {
    datasize_ = x;
  }
  unsigned operator() (const Key& k, unsigned i) const {
    return i;
  }
};

#endif