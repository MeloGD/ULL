#include "set_calculator.h"


// int argc, char const *argv[]
int main() {
   Set A, B;
    
  /*
  A.WritetoSet("64"); // da problemas
  */
  
  //A.ReadFile("input.txt");
  //A.Solve();
  //A.WriteSettoFile();
  /*
  A.WritetoSet("1");
  A.WritetoSet("2");
  A.WritetoSet("3");
  A.WritetoSet("64");
  A.WritetoSet("100");
  A.WriteSettoFile();
  cout << A << endl;
  */
 // cout << A.Get_Size() << endl;
 cin >> A;
 cin >> B;
 if (A==B) {
   cout << "Son iguales!!!" << endl;
 } else
 {
   cout << "No son iguales :(" << endl;
 }
 
 
 //cout << A << endl;
 //cout << A.Get_Size() << endl;
 
  return 0;
}


