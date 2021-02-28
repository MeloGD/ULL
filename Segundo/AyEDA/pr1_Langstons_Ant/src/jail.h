#ifndef JAIL
#define JAIL

#include <assert.h>
#include <iostream>
class Jail {
private:
  struct values {
    short state_;
    char direction_;  
  } myvalues;
    
public:
  Jail(void);
  ~Jail();

  // Getters
  const short get_state(void);
  const char get_direction(void);
  
  // Setters
  void set_state(const short state);
  void set_direction(const char direction);
  

  // Overloads
  friend std::ostream & operator << (std::ostream &out, Jail &jail);
};

#endif