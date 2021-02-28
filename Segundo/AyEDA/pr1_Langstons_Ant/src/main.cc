#include "world.h"
#include "ant.h"
#include "jail.h"
#include <stdlib.h>

int main(void) {
  
  World mundo;
  Ant hormiga;
  int iterator = 0;
  
  mundo.Resize(1000,1000);
  hormiga.Place_Ant(mundo,10,10,'^');
  
  /*mundo.Print_World();
  hormiga.Run_Ant(mundo);
  mundo.Print_World();
  std::cout << std::endl;  
  */
  mundo.Print_World();
  getchar();
  do {
    
    system("clear");
    mundo.Print_World();
    hormiga.Run_Ant(mundo);
    std::cout << std::endl;
    iterator++;
  } while (iterator < 1000);
  

  /*
  test2 = test.At(1,1);
  std::cout << test2.get_state() << std::endl;
  test.At(1,1).set_state(1);
  test2 = test.At(1,1);
  std::cout << test2.get_state() << std::endl;
  */
  

  return 0;
}
