#include "../include/ant.h"

// Constructor
Infinite_Ant::Infinite_Ant() {}

Infinite_Ant::Infinite_Ant(Infinite_World &mundo, int x, int y, string direction) {
  Place_Ant(mundo,x,y,direction);
}

// Destructor
Infinite_Ant::~Infinite_Ant() {}


// Overloads
Infinite_Ant& Infinite_Ant::operator=(Ant& ant) {
  set_currentstate(ant.get_currentstate());
  set_currentx(ant.get_currentx());
  set_currenty(ant.get_currenty());
  
  return *this;
}