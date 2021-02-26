#include <assert.h>
#include <iostream>
class Jail {
private:
  short state_;
    
public:
  Jail(void);
  ~Jail();

  // Getters
  const short get_state(void);
  
  // Setters
  void set_state(const short state);

  // Overloads
  friend std::ostream & operator << (std::ostream &out, Jail &jail);
};
