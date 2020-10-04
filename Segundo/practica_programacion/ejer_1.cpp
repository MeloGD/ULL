
#include "ejer_1.hpp"

Persona::Persona(string nom, int ed, string dni){
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
Persona::set_nombre(char nom){
    nombre_ =  nom;
}



void
Persona::set_edad(int ed){
    edad_ =  ed;
}



void
Persona::set_dni(char dni){
    dni_ =  dni;
}


void
Persona::mostrar(void){
    cout << "Nombre: " << get_nombre() << endl;
    cout << "Edad: " << get_edad() << endl;
    cout << "DNI: " << get_dni() << endl;
    
    if (esMayorDeEdad(get_edad()))
    {
        cout << "Es mayor de edad" << endl;
    }
    else
    {
        cout << "No es mayor de edad" << endl;
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
