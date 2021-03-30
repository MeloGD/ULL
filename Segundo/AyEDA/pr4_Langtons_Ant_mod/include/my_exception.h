/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 4: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/

#ifndef EXCEPTION_1
#define EXCEPTION_1

#include <exception>
#include <iostream>

class my_exception : public std::exception {
private:
    /* data */
public:
    my_exception(const char* err);
    ~my_exception();
    const char* what() const throw () {
        return "Hormiga fuera del rango de la matriz.";
    };

    
};





#endif