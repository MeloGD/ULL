#include <stdio.h>



  
int main() {

  int vector[8] = { 5, 44, 45, 2, 1, 33, 22, 12};
  int m = 8;
  int n, c;
  n=m;
  do {
    for (int i = 0; i < n - 1; i++) {
      if (vector[i] > vector[i + 1]) {
        vector[i] = vector[i] + vector[i + 1];
        vector[i + 1] = vector[i] - vector[i + 1];
        vector[i] = vector[i] - vector[i + 1];
      }
    }
    n = n - 1;
    for (int i=m-1, c = 0; i >= c; i--) {
      if(vector[i] < vector[i - 1]) {
        vector[i] = vector[i] + vector[i - 1];
        vector[i - 1] = vector[i] - vector[i - 1];
        vector[i] = vector[i] - vector[i - 1];
      }
    }
    c = c + 1;
   } while (n != 0 && c != 0);



  for (int i = 0; i < 8; i++) {
    printf("%d\n",vector[i]);
  }
  
  return 0;
}
