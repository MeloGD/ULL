#include <iostream>
#include <iomanip>

using namespace std;

const int MAXIMO = 4;

int main(void)
{ int    a[MAXIMO];
  double b[MAXIMO];
  int    *a_ptr = NULL;
  double *b_ptr = NULL;

  a_ptr = a;
  b_ptr = b;

  for(int i = 0; i < MAXIMO; i++) {
    a[i] = i;
    b[i] = i + 0.85;
  }

  for(int i = 0; i < MAXIMO; i++) {
    cout << setw(5) << a[i] << setw(5) << *(a_ptr + i) << endl;
    cout << setw(5) << b[i] << setw(5) << (b_ptr + i) << endl;
  }
  return 0;
}
