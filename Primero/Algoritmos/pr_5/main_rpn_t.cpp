// AUTOR: Jesús Carmelo González Domínguez
// FECHA: 09/05/2020
// EMAIL: alu0101267760@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// COMENTARIOS: programa principal para probar la calculadora de expresiones 
//              en notaión polaca inversa (RPN, Reverse Polish Notation)
// Compilar con:
// g++ main_rpn_t.cpp -o main_rpn_t

#include <iostream>

#include "stack_l_t.hpp"
#include "queue_l_t.hpp"
#include "rpn_t.hpp"

using namespace std;
using namespace AED;



int main(void)
{
	rpn_t<stack_l_t<int>> calculadora;
	queue_l_t<char> cola;
	
	while (!cin.eof())
	{
		cin >> ws; // lee los espacios en blanco, que dan problemas
		if (!cin.eof())
		{	char c;
		  cin >> c;
			cola.push(c);
		}
	}
	
    cout << "Expresión a evaluar: ";	
	cola.write();

    int r = calculadora.evaluate(cola);
	cout << "Resultado : " << r << endl;
	
	/* La practica trabaja con numeros enteros. Si se quisiera obtener decimales con 5 r, por ejemplo, sería solo cambiar el tipo de dato 
	del programa de int a float, pero para evitar problemas, lo dejo como se ha entregado originalmente*/

	return 0;
}
