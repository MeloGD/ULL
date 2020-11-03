#include "set_calculator.h"


// int argc, char const *argv[]
int main() {
   Set A;
    
  /*
  A.WritetoSet("64"); // da problemas
  */
  
  A.ReadFile("input.txt");
  A.Solve();
  A.WriteSettoFile();
  

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
