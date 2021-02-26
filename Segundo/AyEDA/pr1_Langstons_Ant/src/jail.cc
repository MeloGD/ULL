#include "jail.h"

// Constructor
Jail::Jail(void) {
  // By default is '0', which means white. '1' means black.
  set_state(0);
};

// Destrutor
Jail::~Jail() {} 

// Getters
const short
Jail::get_state(void) {
  return state_;
}

// Setters
void
Jail::set_state(const short state) {
  assert(state == 0 || state == 1);
  state_ = state;
}

// Overloads
std::ostream& 
operator << (std::ostream &out, Jail &jail) {
  return out << jail.get_state();
}