#ifndef VECTOR_T
#define VECTOR_T

#include <iostream>
#include <cassert>


template<class T>
class Vector_t {
private:
  T *vector_;
  int size_;
  
  void build(void);
  void destroy(void);
public:
  Vector_t(const int = 0);
  Vector_t(const Vector_t&); // constructor de copia
  Vector_t<T>& operator=(const Vector_t<T>&); // operador de asignación
  ~Vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;
  
  void write(std::ostream& = std::cout) const;
  void read(std::istream& = std::cin);

};

template<class T>
Vector_t<T>::Vector_t(const int n):
vector_(NULL),
size_(n) {
  build();
}

// constructor de copia
template<class T>
Vector_t<T>::Vector_t(const Vector_t<T>& w) {
  *this = w;
}

// operador de asignación
template<class T>
Vector_t<T>& Vector_t<T>::operator=(const Vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); ++i)
    at(i) = w.at(i);
  
  return *this;
}

template<class T>
Vector_t<T>::~Vector_t() {
  destroy();
}

template<class T>
void Vector_t<T>::build() {
  vector_ = NULL;
  if (size_ != 0) {
    vector_ = new T[size_];
    assert(vector_ != NULL);
  }
}

template<class T>
void Vector_t<T>::destroy() {
  if (vector_ != NULL) {
    delete[] vector_;
    vector_ = NULL;
  }
  size_ = 0;
}

template<class T>
void Vector_t<T>::resize(const int n) {
  destroy();
  size_ = n;
  build();
}

template<class T>
inline T Vector_t<T>::get_val(const int i) const {
  return vector_[i];
}

template<class T>
inline int Vector_t<T>::get_size() const {
  return size_;
}

template<class T>
void Vector_t<T>::set_val(const int i, const T d) {
  vector_[i] = d;
}

template<class T>
T& Vector_t<T>::at(const int i) {
  return vector_[i];
}

template<class T>
T& Vector_t<T>::operator[](const int i) {
  return at(i);
}

template<class T>
const T& Vector_t<T>::at(const int i) const {
  return vector_[i];
}

template<class T>
const T& Vector_t<T>::operator[](const int i) const {
  return at(i);
}

template<class T>
void Vector_t<T>::write(std::ostream& os) const { 
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

template<class T>
void
Vector_t<T>::read(std::istream& is) {
  is >> size_;
  resize(size_);
  for (int i = 0; i < size_; ++i)
    is >> at(i);
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Vector_t<T>& v) {
  v.write(os);
  return os;
}

template<class T>
std::istream& operator>>(std::istream& is, Vector_t<T>& v) {
  v.read(is);
  return is;
}

#endif