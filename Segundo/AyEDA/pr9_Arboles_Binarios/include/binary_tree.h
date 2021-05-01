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
#include "node.h"
#include <queue>
#include <iostream>

#ifndef AB
#define AB

template<class T>
class BinaryTree {
private:
 Node<T>* root_;
 int counter_;
public:
  // Constructor
  BinaryTree();
  // Destructor
  ~BinaryTree();

  // Functions
  void Insert(Node<T>* root, T data);
  void Print_Tree(Node<T>* root);
};

// Constructor
template<class T>
BinaryTree<T>::BinaryTree() {
  root_ = new Node<T>;
  counter_ = 0;
  //Print_Tree(root_);
}

// Destructor
template<class T>
BinaryTree<T>::~BinaryTree() {
}

// Functions
template<class T>
void BinaryTree<T>::Insert(Node<T>* root, T data) {
  if (root_->data_ == NULL) {
    root_ = root;
    root_->data_ = data; 
    //std::cout << "entre aqui";
    return;
  } else {
    Node<T>* auxiliarnode;
    std::queue<Node<T>*> nodequeue;
    nodequeue.push(root);
    while (!nodequeue.empty()) {
      auxiliarnode = nodequeue.front();
      nodequeue.pop();
      if (auxiliarnode->left_ == nullptr) {
        auxiliarnode->left_ = new Node<T>(data);
        return;
      } else {
        nodequeue.push(auxiliarnode->left_);
      }
      if (auxiliarnode->right_ == nullptr) {
        auxiliarnode->right_ = new Node<T>(data);
        return;
      } else {
        nodequeue.push(auxiliarnode->right_);
      }
    }
  }
}

template<class T>
void BinaryTree<T>::Print_Tree(Node<T>* root) {
  
  if (root == NULL) {
    return;
  }
  std::queue<Node<T>*> printqueue;
  printqueue.push(root);
  int level = 0;
  while (!printqueue.empty()) {
    int deep = printqueue.size();
    std::cout << "Nivel " << level << ": ";
    while (deep > 0) {
      Node<T>* auxiliarnode = printqueue.front();
      std::cout << " [" << auxiliarnode->data_ << "] ";
      printqueue.pop();
      if (auxiliarnode->left_ != NULL) {
        printqueue.push(auxiliarnode->left_);
      } 
      if (auxiliarnode->right_ != NULL) {
        printqueue.push(auxiliarnode->right_);
      }
      deep--;
    }
    std::cout << "\n";
    level++;
  }
    
};
#endif