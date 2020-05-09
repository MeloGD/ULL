// AUTOR: Jesús Carmelo González Domínguez
// FECHA: 09/05/2020
// EMAIL: alu0101267760@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// PRÁCTICA Nº: 5
// COMENTARIOS: clase TAD pila implementada con una lista

#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.hpp"

using namespace std;

namespace AED {

template<class T>
class stack_l_t 
{
public:	
  // constructor y destructor
  stack_l_t(void);
  ~stack_l_t(void);

  // operaciones
	void push(const T&);
	void pop(void);
	const T& top(void) const;

	bool empty(void) const;

	//Modificación, getter para comprobación
	int get_count_imp(void);

  // E/S	
	void write(ostream& os = cout);

private:
	dll_t<T> l_;
	//Mod
	int count_odd_(void) const;
	
};
//Modifiación-->contar numero de valores impares en la pila
template<class T> 
int stack_l_t<T>::count_odd_(void) const{
	
	dll_node_t<T>* aux = l_.get_head();
	int count = 0;
	while (aux != NULL)
	{
		
		if (aux->get_data() % 2 != 0)
		{
			count++;
		}
		aux = aux->get_next();
	}
	return count;
};

template<class T> //para comprobar
int stack_l_t<T>::get_count_imp(void){
	return count_odd_();
}


template<class T>
stack_l_t<T>::stack_l_t(void):
l_() 
{}



template<class T>
stack_l_t<T>::~stack_l_t(void)
{}



template<class T>
void
stack_l_t<T>::push(const T& dato)
{
	dll_node_t<T>* nodo = new dll_node_t<T>(dato);
	assert(nodo != NULL);
	l_.insert_head(nodo);
}



template<class T>
void
stack_l_t<T>::pop(void)
{
	assert(!empty());
	delete l_.extract_head();
}



template<class T>
const T&
stack_l_t<T>::top(void) const
{
	assert(!empty());
	return l_.get_head()->get_data();
}


template<class T>
bool 
stack_l_t<T>::empty(void) const
{
	return l_.empty();
}


template<class T>
void
stack_l_t<T>::write(ostream& os)
{
	dll_node_t<T>* aux = l_.get_head();
	while (aux != NULL)
	{ 
		cout << " │ " << setw(2) << aux->get_data() << "  │" << endl;
		aux = aux->get_next();
	}

	cout << " └─────┘" << endl; 
}

} // namespace
