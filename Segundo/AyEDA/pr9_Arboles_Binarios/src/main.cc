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
#include "../include/binary_tree.h"

int main() {
  BinaryTree<int> Tree;
  Node<int>* root = new Node<int>;
  Tree.Print_Tree(root);
  Tree.Insert(root, 10);
  Tree.Insert(root, 15);
  Tree.Insert(root, 21);
  Tree.Insert(root, 33);
  Tree.Print_Tree(root);
  
  /*
  Node<int>* root = new Node<int>(5);
  root->left_ = new Node<int>(4);
  root->right_ = new Node<int>(3);*/
  return 0;
}
