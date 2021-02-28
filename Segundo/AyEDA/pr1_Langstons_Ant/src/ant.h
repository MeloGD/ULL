#ifndef ANT
#define ANT
#include "world.h"
#include "jail.h"

class Ant {
private:
  short currentstate_;
  short oldstate_;
  short currentx_;
  short currenty_;
  short oldx_;
  short oldy_;
public:
  Ant(/* args */);
  ~Ant();

  // Getter
  const short get_currentstate(void);
  const short get_oldstate(void);
  const short get_currentx(void);
  const short get_currenty(void);
  const short get_oldx(void);
  const short get_oldy(void);
  // const short get_currentstate(void);
  // Setter
  void set_currentstate(const short state);
  void set_oldstate(const short oldstate);
  void set_currentx(const short currentx);
  void set_currenty(const short currenty);
  void set_oldx(const short oldx);
  void set_oldy(const short oldy);

  // Functions 
  void Place_Ant(World &mesh, int x, int y, char dir);
  void Run_Ant(World &mesh);
  void Move_Up(World &mesh);
  void Move_Left(World &mesh);
  void Move_Right(World &mesh);
  void Move_Down(World &mesh);
  
};

#endif
