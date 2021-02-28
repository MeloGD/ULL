#include "jail.h"

// Constructor
Jail::Jail(void) {
  // By default is '0', which means white. '1' means black.
  set_state(0);
  set_direction(' ');
};

// Destrutor
Jail::~Jail() {} 

// Getters
const short
Jail::get_state(void) {
  return myvalues.state_;
}

const char
Jail::get_direction(void) {
  return myvalues.direction_;
}
// Setters
void
Jail::set_state(const short state) {
  assert(state == 0 || state == 1 );
  myvalues.state_ = state;
}

void
Jail::set_direction(const char direction) {
  assert(direction == '>' || direction == '<' || direction == '^' || 
        direction == 'v'|| direction == ' ');
  myvalues.direction_ = direction;
}



// Overloads
std::ostream& 
operator << (std::ostream &out, Jail &jail) {
  return out << jail.myvalues.state_ << jail.myvalues.direction_;
  //  Borrar cuando termine << jail.myvalues.state_
}