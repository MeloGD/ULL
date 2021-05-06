/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 7: Metodos de ordenación
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/

#include <iostream>
#include <string>

#ifndef KEYS
#define KEYS


class Keys {
private:
  std::string nombre_;
  std::string dni_;
  std::string nss_;
  std::string apellido1_;
  std::string apellido2_;
  std::string direccion_;
  std::string cp_;
  std::string email_;
  std::string fotografia_;
  std::string huella_;
  std::string fechanacimiento_;
  
public:
  Keys();
  Keys(std::string, std::string, std::string,
       std::string, std::string, std::string,
       std::string, std::string, std::string,
       std::string, std::string);
  ~Keys();

  // Getters
  std::string& get_dni(void);  


  // Setters
  


  // Overloads

};


Keys::Keys() {
  
}

Keys::Keys(std::string nombre, std::string dni, std::string nss,
           std::string apellido1, std::string apellido2,
           std::string direccion, std::string cp, std::string email,
           std::string fotografia, std::string huella,
           std::string fechanacimiento) {
  nombre_ = nombre;
  dni_ = dni;
  nss_ = nss;
  apellido1_ = apellido1;
  apellido2_ = apellido2;
  direccion_ = direccion;
  cp_ = cp;
  email_ = email;
  fotografia_ = fotografia;
  huella_ = huella;
  fechanacimiento_ = fechanacimiento;
}

Keys::~Keys() {

}


std::string& Keys::get_dni(void) {
  return dni_;
}




#endif
