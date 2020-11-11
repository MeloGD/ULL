/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Computabilidad y Algoritmia.

Práctica 1: Criba de Erastótenes
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
*/

#include "erathostenes.h"

int main(int argc, const char** argv) {
  // Convertimos la string a un entero con atoi y la depositamos 
  // en la variable num.
  const int num = atoi(argv[1]);
    
  cout << "¿Desea detener la construcción de la lista en un número en concreto? (y/n)" << endl;
  cin >> debvar;
    
  // Ejecución del programa, que controla si se ha activado o no la función
  // de Debug().
  if (Debug(debvar)) {
    cout << "Introduzca hasta que número: " << endl;
    cin >> stopvar;  
    Build(num);
    Sieve(num);
    Quit();
    Show(); 
    } else {
    Build(num);
    Sieve(num);
    Quit();
    Show();
    }
return 0;
}





/*
void criba(bool m[], int tam){
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i) 
        m[i] = true;

    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
}
*/