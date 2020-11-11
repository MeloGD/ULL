#include "dfa.h"

// int argc, char const *argv[]
int main(void) {
  Dfa dfasimulator1;
  dfasimulator1.BuildAlphabet();
  dfasimulator1.BuildStates();
  dfasimulator1.BuildInitialState();
  dfasimulator1.BuildFinalStates();
  dfasimulator1.BuildTrasitions();


  
  
  
  return 0;
}
