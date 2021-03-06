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
  bool menu = true;
  int value = 0;
  int option = 0;
  std::cout << "Práctica 9: Árboles Binarios Equilibrados\n"; 
  Node<int>* root = new Node<int>;
  do {
    std::cout << "¿Qué operación desea realizar?\n"; 
    std::cout << "  - Búsqueda.   (1)\n"; 
    std::cout << "  - Inserción.  (2)\n"; 
    std::cout << "  - Salir.      (3)\n"; 
    std::cin >> option;
    switch (option) {
    case 1:
      std::cout << "Inserte el valor a introducir en el árbol\n"; 
      std::cin >> value;
      if (Tree.Search(root, value)) {
        std::cout << "Se ha encontrado el valor.\n";
      } else {
        std::cout << "No se ha encontrado el valor.\n";
      }
      break;
    case 2:
      std::cout << "Inserte el valor a introducir en el árbol\n"; 
      std::cin >> value;
      Tree.Insert(root, value);
      Tree.Print_Tree(root);
      break;
    case 3:
      std::cout << "Ha escogido salir, saludos.\n"; 
      menu = false;
      break;  
    
    default:
      break;
    }
    value = 0;
  } while (menu);
  
  /*
  Node<int>* root = new Node<int>(5);
  root->left_ = new Node<int>(4);
  root->right_ = new Node<int>(3);*/
  return 0;
}
