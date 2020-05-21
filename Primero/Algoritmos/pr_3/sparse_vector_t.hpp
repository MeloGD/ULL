// AUTOR: Jesús Carmelo González Dominguez
// FECHA: 30/03/2020
// EMAIL: alu0101267760@ull.edu.es
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"
#include "pair_t.hpp"

using namespace std;


typedef vector_t<pair_t<double>> pair_vector_t;

class sparse_vector_t
{
public:
  sparse_vector_t(const vector_t<double>&); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  sparse_vector_t& operator=(const sparse_vector_t&); // operador de asignación

  ~sparse_vector_t();

  // getters
   int get_nz(void) const;
   int get_n(void) const;

   // operaciones
   double scal_prod(const vector_t<double>&);
   double scal_prod(const sparse_vector_t&);

   // Modificación
   double max(void);

   // curiosidad
   pair_vector_t par(void);

   // E/S
   void write(ostream& = cout) const;

private:
  pair_vector_t pv_; // valores + índices
  int     nz_;       // nº de valores distintos de cero = tamaño del vector
  int     n_;        // tamaño del vector original

  bool is_not_zero(double, double = 1e-6) const;
};



// FASE II
sparse_vector_t::sparse_vector_t(const vector_t<double>& v):
pv_(),
nz_(0),
n_(0)
{
  for (int i = 0; i < v.get_size(); i++ ){
    if (is_not_zero(v[i])){
      nz_++;
    }
  }

  pv_.resize(nz_);

  int j=0;
  for(int i=0; i < v.get_size(); i++){
    if(is_not_zero(v[i])){
      pv_[j].set(v[i],i);
      j++;
    }
  }
}



// constructor de copia
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w)
{
  *this = w; // invocamos directamente al operator=
}



// operador de asignación
sparse_vector_t&
sparse_vector_t::operator=(const sparse_vector_t& w)
{
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}



sparse_vector_t::~sparse_vector_t()
{}



inline int
sparse_vector_t::get_nz() const
{
  return nz_;
}



inline int
sparse_vector_t::get_n() const
{
  return n_;
}



void
sparse_vector_t::write(ostream& os) const
{
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << endl;
}



ostream&
operator<<(ostream& os, const sparse_vector_t& sv)
{
  sv.write(os);
  return os;
}



bool
sparse_vector_t::is_not_zero(double v, double eps) const
{
  return fabs(v) > eps;
}



// operaciones
// FASE III
double
sparse_vector_t::scal_prod(const vector_t<double>& v)
{
  double s = 0;
  for (int i = 0; i < nz_; i++){    //nz_ porque es el tamaño del vector escaso, no tiene sentido coger el tamaño del denso
    s += pv_[i].get_val() * v[pv_[i].get_inx()]; // cogemos el valor del escaso y multiplicamos por el denso
  }                                              // usamos el indice del ligero para escoger el valor correcto en el vector denso
  return s;
}



/// FASE IV
double
sparse_vector_t::scal_prod(const sparse_vector_t& sv)
{
  double s = 0;
  int i,j;
  while (i < nz_ && j < sv.nz_) {  //mientras-->tamaño de los vectores dispersos
    if ( pv_[i].get_inx() == sv.pv_[j].get_inx()){
      s += pv_[i].get_val() * sv.pv_[j].get_val(); // si tienen mismo indice, multiplicamos
      i++;
      j++;
    }
    else if (pv_[i].get_inx() > sv.pv_[j].get_inx()){ //si el indice del primero es mayor, aumentamos j para pasar al siguiente valor de j
      j++;
    }
    else {  //si el indice del segundo es mayor, aumentamos i para saltar al siguiente valor de primer vector escaso
      i++;
    }
  }

  return s;
}


// Modificación

double
sparse_vector_t::max(){
  double max = 0;
  int ind = pv_[0].get_inx();

  for (int i = 0 ; i < nz_; i++){
    if (ind <= pv_[i].get_inx()){
      ind = pv_[i].get_inx();
      max = pv_[i].get_val();
    }
}
 return max;
}

double
sparse_vector_t::max(){
  double max = pv_[0].get_val();

  for (int i = 0 ; i < nz_; i++){
    if (max > pv_[i].get_val()){
            max = pv_[i].get_val();
    }
}
 return max;
}




  //curiosidad: solo valores de indices pares de un vector disperso
  pair_vector_t
  sparse_vector_t::par(){
    pair_vector_t p;
    int j = 0;
    int size_p = 0;

    for (int i = 0; i < pv_.get_size(); i++){
      if (((pv_[i]).get_inx() % 2) == 0){
        size_p++;
      }
    }
    p.resize(size_p);

    for (int i = 0; i < pv_.get_size(); i++){
      if (((pv_[i]).get_inx() % 2) == 0){
        p[j].set(pv_[i].get_val(), pv_[i].get_inx());
        j++;
      }
    }
    return p;
  }
