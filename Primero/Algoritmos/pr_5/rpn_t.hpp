// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: clase que implementa la clase RPN (Reverse Polish Notation)

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>
#include "queue_l_t.hpp"

using namespace std;

namespace AED {

template <class T>
class rpn_t
{
public:
  rpn_t(void);
  ~rpn_t();

  const int evaluate(queue_l_t<char>&);

private: 
  T stack_;
	void operate_(const char operador);
};



template<class T>
rpn_t<T>::rpn_t():
stack_()
{}



template<class T>
rpn_t<T>::~rpn_t()
{}



template<class T>
const int 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	while (!q.empty())
	{
    char c = q.front();
    q.pop();
    cout << "Sacamos de la cola un carácter: " << c;

		if (isdigit(c))
		{
		  int i = c - '0';
		  // poner código
		  cout << " (es un dígito) " << endl << "   Lo metemos en la pila..." << endl;
		}
		else {
		  cout << " (es un operador)" << endl;
		  // poner código
		}
	}

	// poner código
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert(c == '+' || c == '-' || c == '*' || c == '/');
  
  // código
  cout << "   Sacamos de la pila un operando: " << endl;
  
  // código
  cout << "   Sacamos de la pila otro operando: " << endl;
  
	switch (c)
	{
	  case '+': // código
	            break;
	  // resto de operadores
	}

	// código
	cout << "   Metemos en la pila el resultado: " << endl;
}

}
