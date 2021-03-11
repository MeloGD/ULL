/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 2: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará el tablero en blanco con la hormiga, esperando
que una tecla sea pulsada para inicializar)
$ make clean
*/

#ifndef VECTOR_T
#define VECTOR_T

#include <assert.h>
#include <cstddef>

template<class T>

class Vector_T {
private:
  T* vector_;
  int size_;

  void Build(void);
  void Destroy(void);
public:
  Vector_T(const int size = 0);
  ~Vector_T();

  // Getters
  const int get_size(void);

  // Setters
  void set_size(const int size);
  void set_value(const int index, const int value);

  // Functions
  T& At(int position);
  void Resize(const int size);
  
  // Overloads
  T& operator[](const int);
  Vector_T<T>& operator=(const Vector_T<T>&);
};

// Constructor
template<class T>
Vector_T<T>::Vector_T(const int size):
vector_ (NULL),
size_(size) {
  Build();
}

template<class T>
void Vector_T<T>::Build() {
  vector_ = NULL;
  if (size_ != 0) {
    vector_ = new T[size_];
    assert(vector_ != NULL);
  }
}

// Destructor
template<class T>
Vector_T<T>::~Vector_T() {
  Destroy();
}

template<class T>
void Vector_T<T>::Destroy() {
  if (vector_ != NULL) {
    delete[] vector_;
    vector_ = NULL;
  }
  size_ = 0;
}

// Getters
template<class T>
const int Vector_T<T>::get_size() {
  return size_; 
}

// Setters
template<class T>
void Vector_T<T>::set_size(const int size) {
  size_ = size;
}

template<class T>
void Vector_T<T>::set_value(const int index, const int value) {
  return vector_[index] = value; 
}

// Functions
template<class T>
T& Vector_T<T>::At(int position) {
  return vector_[position]; 
}

template<class T>
void Vector_T<T>::Resize(const int size) {
  Destroy();
  size_ = size;
  Build(); 
}

// Overloads
template<class T>
T& Vector_T<T>::operator[](const int position) {
  return At(position); 
}

#endif