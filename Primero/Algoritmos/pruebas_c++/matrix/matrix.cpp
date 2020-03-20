#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  // Recorrido de una matriz
  const int ro = 3, co = 4;
  int A[ro][co] = {
    {4,5,2,9},
    {1,7,4,2},
    {8,6,2,0}
  };
  cout << "La matriz A es:" << endl ;
  for (int i=0; i < ro; i++){
    for (int j=0; j < co; j++){
      cout << A[i][j] << " ";
    }
  cout << endl;
  }

  //
  //
  // Suma de los elementos u operaciones varias

  int suma = 0, sumpar = 0 , sumimp = 0;
  for (int i=0; i < ro; i++){
    for (int j=0; j < co; j++){
      suma += A[i][j];
      if (A[i][j] % 2 == 0){
        sumpar += A[i][j];
      }
      else{
      sumimp += A[i][j];
      }
    }
  }
  cout << endl;
  cout << "El valor de la suma de todos los elementos de A es: " << suma << endl;
  cout << "El valor de la suma de todos los elementos de A pares: " << sumpar << endl;
  cout << "El valor de la suma de todos los elementos de A impares: " << sumimp << endl;

  //
  //
  // Recorrido diagonales principal y secundaria

  cout << "Elementos de la diagonal principal: " ;
  for (int i = 0; i < ro; i++){
    cout << A[i][i] << " ";
  }
  cout << endl;
  cout << "Elementos de la diagonal secundaria: " ; // [j] = (co -1 - i) --> fórmula
  // hay otras dos formas más en las diapositivas
  for (int i = 0; i < ro; i++){
    cout << A[i][co -1 - i] << " "; // importante dar el valor de columnas con las que se trabaja --> co = 4 (podría seleccionar que diagonal coger cambiando el valor de co)
  }
  cout << endl;

  //
  //
  // Submatriz triangular superior e inferior
  cout << "Elementos de la submatriz triangular inferior (principal): " << endl;
  for (int i = 0; i < ro; i++){
    for (int j = 0 ; j <= i; j++){
      cout << A[i][j] << " ";
    }
  cout << endl;
  }

  cout << "Elementos de la submatriz triangular superior (principal): " << endl;
  for (int i = 0; i < ro; i++){
    for (int j = i ; j < co; j++){
        cout << A[i][j] << " ";
      }
  cout << endl;
    }

    cout << "Elementos de la submatriz triangular inferior (secundaria): " << endl;
    for (int i = 0; i < ro; i++){
      for (int j = co -1 - i ; j < co; j++){
        cout << A[i][j] << " ";
      }
    cout << endl;
    }

    cout << "Elementos de la submatriz triangular superior (secundaria): " << endl;
    for (int i = 0; i < ro; i++){
      for (int j = 0 ; j < co - i ; j++){
          cout << A[i][j] << " ";
        }
    cout << endl;
      }


      /*prueba para sobrecarga en práctica II
      template<class T>
      matrix_t<T>
      operator*(const matrix_t<T>& A, const matrix_t<T>& B){
        matrix_t<T> aux;
        (aux.multiply(A,B));
        return aux;
      }
  */

  //
  //
  // Multiplicación

  return 0;
}
