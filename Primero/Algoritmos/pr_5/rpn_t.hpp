// AUTOR: Jesús Carmelo González Domínguez
// FECHA: 09/05/2020
// EMAIL: alu0101267760@ull.edu.es
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

  const float evaluate(queue_l_t<char>&);	
  

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
const float 
rpn_t<T>::evaluate(queue_l_t<char>& q)
{
	int count = 0; //Para comprobar la modificación
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
		  stack_.push(i);

		  
		}
		else {
		  cout << " (es un operador)" << endl;
		  // poner código
		  operate_(c);
		   

		}
		//Comprobación de la modificación
		count = stack_.get_count_imp();	
		cout << "El número de elementos impares en la pila es  "  << count << endl;
	}

	// poner código
	const float result = stack_.top();
	return result;
}



template<class T>
void
rpn_t<T>::operate_(const char c)
{
  assert(c == '+' || c == '-' || c == '*' || c == '/'|| c == '^' || c == 'r' || c == 'l' || c == 'c');
  int op1 = 0;
  int op2 = 0;
  int op = 0;
  
  int count = 0;
  count = stack_.get_count_imp();
  cout << "El número de elementos impares es " << count << endl;

  if (c == '+' || c == '-' || c == '*' || c == '/') //para controlar si es de aridad 2 o 1
  {
	  op1 = stack_.top();
      stack_.pop();
      cout << "   Sacamos de la pila un operando: " << op1 << endl;
	  op2 = stack_.top();
      stack_.pop();
      cout << "   Sacamos de la pila otro operando: " << op2 << endl;
  }
  else
  {
	  op = stack_.top();
	  stack_.pop();
	  cout << "   Sacamos de la pila otro operando: " << op << endl;
  }
  
 
	switch (c)
	{
	  case '+': // código
	  			stack_.push(op2+op1);
	            break;
	  case '-':
	  			stack_.push(op2-op1); //hay que tener en cuenta el orden de inserción en la pila
				break;
	  case '*':
	  			stack_.push(op2*op1);
				break;  
	  case '/': 	
	  			stack_.push(op2/op1); //hay que tener en cuenta el orden de inserción en la pila
				break;
	  case '^': 	
	  			stack_.push(pow(op2,op1)); //hay que tener en cuenta el orden de inserción en la pila
				break;
	  case 'r':	
	  			stack_.push(sqrt(op));  
				break;
	  case 'l':
	  			stack_.push(log2(op));
				break;
	  case 'c':
	  			stack_.push(pow(op,2));
				break; 			  							  					
	  // resto de operadores
	}

	// código
	int res = stack_.top();
	cout << "   Metemos en la pila el resultado: " << res << endl;
}

}
