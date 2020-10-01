/*Vamos a crear una clase llamada Persona. Sus atributos son: nombre, edad y DNI. Construye los siguientes métodos para la clase:

    Un constructor, donde los datos pueden estar vacíos.
    Los setters y getters para cada uno de los atributos. Hay que validar las entradas de datos.
    mostrar(): Muestra los datos de la persona.
    esMayorDeEdad(): Devuelve un valor lógico indicando si es mayor de edad.
*/

class Persona
{
private:
    char nombre;
    int edad;
    char dni;

public:
    Persona(char nombre , int edad, char dni); //constructor
    
    ~Persona() {}; //destructor

    //getters
    char    get_nombre(); //probar a ver si se puede poner un const
    int     get_edad();
    char    get_dni(); 

    //setters
    void     set_nombre(char);
    void     set_edad(int);
    void     set_dni(char);

    //metodos
    Persona mostrar();
    bool esMayorDeEdad(int);
};

 
 
