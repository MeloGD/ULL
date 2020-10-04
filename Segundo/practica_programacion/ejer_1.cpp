
#include "ejer_1.hpp"
#include <cctype>

Persona::Persona(const string nom, const int ed, const string dni){
    nombre_ = nom;
    edad_ = ed;
    dni_ = dni;
}



string
Persona::get_nombre(void){
    return nombre_;
}



int
Persona::get_edad(void){
    return edad_;
}



string
Persona::get_dni(void){
    return dni_;
}



void
Persona::set_nombre(string nom){
    nombre_ =  nom;
}



void
Persona::set_edad(int ed){
    edad_ =  ed;
}



void
Persona::set_dni(string dni){
    dni_ =  dni;
}


void
Persona::mostrar(void){
    validar_dni(dni_);
    if (esMayorDeEdad(get_edad()))
    {
        cout << "Es mayor de edad" << endl;
    }
    else
    {
        cout << "No es mayor de edad" << endl;
    }

    cout << "Nombre: " << get_nombre() << endl;
    cout << "Edad: " << get_edad() << endl;
    cout << "DNI: " << get_dni() << endl;
}



void
Persona::validar_dni(string v_dni){
    string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int post = 0;
    if (v_dni.length() != 9)
    {
        cout << "El DNI está incorrecto, no tiene 9 campos." << endl;
        dni_ = "";
        return;
    }

    if (isalpha(v_dni[v_dni.length() - 1]))  //isalpha controla si esta en el alfabeto o no
    {
        cout << "DNI correcto" << endl;
        
    }
    else
    {
        cout << "Error en el DNI." << endl;
        dni_ = "";
    }
}



bool
Persona::esMayorDeEdad(int ed){
    if (ed < 18)
    {
        return false;
    }
    else
    {
        return true;
    }
        
}
