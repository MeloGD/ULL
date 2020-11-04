#include "set_calculator.h"


// int argc, char const *argv[]
int main() {
   Set A(128);
    
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
 cout << A << endl;
 //cout << A << endl;
 //cout << A.Get_Size() << endl;
 
 /*
  uint64_t prueba = pow(2,64);
  unsigned long int prueba2 = pow(2,64);
  cout << "Valor mas alto: " << endl;
  cout << prueba << endl;
  cout << prueba2 << endl;
  string subset;
  subset = bitset<128>(prueba).to_string();
  cout << subset << endl;
  */
  return 0;
}



 /*
  ifstream file;
  while(file !eof) {
    Read();
    Solve();
    Write();
  }
  */
