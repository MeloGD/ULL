/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 9: Arbones Binarios
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menú de configuracion para generar el árbol)
$ make clean
*/
#include <stddef.h>

#ifndef NODE
#define NODE

template<class T>
class Node {
private:

public:
  Node();
  Node(T* data);
 ~Node();

  T* data_;
  Node* left_;
  Node* right_;

};

// Constructor
template<class T>
Node<T>::Node() {
  data_ = nullptr;
  left_ = nullptr;
  right_ = nullptr;
}


template<class T>
Node<T>::Node(T* data) {
  data_ = nullptr;
  left_ = nullptr;
  right_ = nullptr;
}

// Destructor
template<class T>
Node<T>::~Node() {
}


#endif