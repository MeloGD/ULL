#include "set_calculator.h"


// int argc, char const *argv[]
int main() {
   Set A(100);
  // A.ReadString("1");
  // A.ReadString("4");
  // A.ReadString("6");
  // A.ReadString("7");
  
  
  A.WritetoSet("1");
  A.WritetoSet("4");
  A.WritetoSet("8");
  A.WritetoSet("10");
  A.WritetoSet("11");
  A.WritetoSet("31");
  A.WritetoSet("31");
  A.WritetoSet("64");
  A.WritetoSet("65");
  A.WritetoSet("85");
  A.WritetoSet("89");
  A.set_lastvalue(89);
  

  A.WriteSettoFile();

  

  
  return 0;
}