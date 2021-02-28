#include "world.h"
#include "ant.h"
#include "jail.h"

int main(void) {
  
  World mundo;
  //Jail test2;
  mundo.Resize(10,10);
  Ant hormiga;
  hormiga.Place_Ant(mundo,0,9,'v');
  mundo.Print_World();
  hormiga.Run_Ant(mundo);
  std::cout << std::endl;
  mundo.Print_World();
  


  /*
  test2 = test.At(1,1);
  std::cout << test2.get_state() << std::endl;
  test.At(1,1).set_state(1);
  test2 = test.At(1,1);
  std::cout << test2.get_state() << std::endl;
  */
  

  return 0;
}
