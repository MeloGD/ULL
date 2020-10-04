/*Vamos a crear una clase llamada Persona. Sus atributos son: nombre, edad y DNI. Construye los siguientes métodos para la clase:

    Un constructor, donde los datos pueden estar vacíos.
    Los setters y getters para cada uno de los atributos. Hay que validar las entradas de datos.
    mostrar(): Muestra los datos de la persona.
    esMayorDeEdad(): Devuelve un valor lógico indicando si es mayor de edad.
*/

#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    string nombre_;
    int edad_;
    string dni_;

public:
    Persona(string, const int, string); //constructor
    
    ~Persona() {}; //destructor

    //getters
    string    get_nombre(); //probar a ver si se puede poner un const
    int     get_edad();
    string    get_dni(); 

    //setters
    void     set_nombre(char);
    void     set_edad(int);
    void     set_dni(char);

    //metodos
    void mostrar(void);
    bool esMayorDeEdad(int);
};

 
 
