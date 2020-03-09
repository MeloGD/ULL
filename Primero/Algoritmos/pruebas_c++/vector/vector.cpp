#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  //Recorrido simple de un vector con memoria dinámica
  const int n = 10;
  int *A = new int[n]; // la MEMORIA DINÁMICA funciona con PUNTEROS

  for (int i = 0; i < n; i++) {
    A[i] = i;
  }

  cout << "A: ";
  for (int i = 0; i < n; i++) {
    cout << A[i] << " " ;
  }
  cout << endl;
  delete[] A;

  //
  //
  //Busqueda de un valor y contabilización
  int *B = new int[n]; //

  for (int i = 0; i < n; i++) {
    B[i] = i;
  }

  cout << "B: ";
  int v5 = 5; // valor a encontrar
  int v0 = 0;
  bool found5 = false;
  bool found0 = false;
  int count5 = 0;
  int count0 = 0;

  B[0] = 5;
  B[2] = 5;
  B[3] = 5;
  for (int i = 0; i < n; i++) {
    cout << B[i] << " " ;
    if (B[i] == v5) {
      found5 = true;
      count5++;
    if (B[i] == v0) {
      found0 = true;
      count0++;
    }
    }
  }
  cout << endl;
  cout << "El valor " << v5 << (found5 ? " aparece: " : " no aparece. ") << count5 << " vez/veces."<< endl;
  cout << "El valor " << v0 << (found0 ? " aparece: " : " no aparece. ") << count0 << " vez/veces."<< endl;
  delete[] B;

  //
  //
  // Valor máximo y mínimo de un vector
  int C[n] = { 5, 3, 2, 1, -5, 1, 4, 2, 1, 6 };
  int min = INFINITY , max = -INFINITY;

  for (int i = 0; i < n; i++) {
    if (C[i] < min) min = C[i];
    if (C[i] > max) max = C[i];
  }


  cout << "C: ";
  for (int i = 0; i < n; i++) {
    cout << C[i] << " " ;
  }
  cout << endl;
  cout << "min= " << min << endl;
  cout << "max= " << max << endl;


  //
  //
  // Operaciones con vectores
  int sum = 0;
  int sumpar = 0;
  int sumimp = 0;
  int prodes = 0;
  for (int i = 0; i < n; i++) {
    sum += C[i];
    prodes += C[i] * A[i];
    if (C[i] % 2 == 0){
      sumpar += C[i];
    }
    else {
      sumimp += C[i];
    }
  }
  cout << endl;
  cout << "Valor de la suma de C: " << sum << endl;
  cout << "Valor de la suma de pares de C: " << sumpar << endl;
  cout << "Valor de la suma de impares de C: " << sumimp << endl;
  cout << "Producto escalar de C x A: " << prodes << endl;

  //
  //
  // Implementación de matriz sobre vector
  const int ro = 2 , co = 3; //filas y columnas
  int *M = new int [ro * co];

  for (int i = 0; i < ro * co; i++) {
    M[i] = (i + 1) * 10;
  }

  cout << endl;
  cout << "La matriz M es: " ;
  for (int i = 0; i < ro * co; i++) {
    cout << M[i] << " ";  // si lo dejamos aquí, muestra solo 10 20 30 40 50 60
  }
    // Indexación --> pos = (i-1) * co + (j-1);
    cout << endl;
    int i = 1, j = 2, pos = (i-1) * co + (j-1);
    cout << "M[" << i << "," << j << "]=M[" << pos << "]=" << M[pos] << endl;
    i = 2, j = 3, pos = (i-1) * co + (j-1);
    cout << "M[" << i << "," << j << "]=M[" << pos << "]=" << M[pos] << endl;
    cout << endl;
    delete[] M;

  return 0;
}
