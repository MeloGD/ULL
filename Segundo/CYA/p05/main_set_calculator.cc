#include "set_calculator.h"

int main(int argc, char const *argv[]) {
  Set A, B(105);
  string help = "--help";
  if (argc > 3) {
    cout << "[Error]" << endl;
    cout << "Ha colocado el número incorrecto de argumentos." << endl;
    cout << "Para más información sobre como usar el programa:" << endl;
    cout << "./set_calculator --help" << endl;
    exit(1);
  }
  if (argc == 3) {
    A.ReadFile(argv[1], argv[2]); 
    exit(0);
  }
  if (argc == 1 ) {
    cout << "Introduzca un conjunto o una operación:" << endl;
    cout << "Ejemplo: {1,2}+{3}" << endl;
    cin >> A;
    cout << "El resultado es: " << endl;
    cout <<  A << endl;
    exit(0);
  }
  if (argv[1] == help) {
    cout << "[help]" << endl;
    cout << "El programa debe ejecutarse de la siguiente manera:" << endl;
    cout << "./set_calulator input.txt output.txt" << endl;
    cout << "   - input.txt contiene las operaciones a realizar." << endl;
    cout << "   - output.txt contiene el resultado de las operaciones." << endl;
    cout << endl;
    cout << "Si ejecuta ./set_calculator sin argumentos, podrá " << endl;
    cout << "escribir un conjunto o una operación de conjuntos, " << endl;
    cout << "mostrando el resultado por pantalla." << endl;
    exit(0);
  }
  return 0;
}


