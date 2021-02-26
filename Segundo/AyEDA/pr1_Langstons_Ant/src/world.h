#include "jail.h"
#include <vector>


class World {
private:
  int row_;
  int column_;
  Jail** mesh_;
  int position(int i, int j) const {
    return (i - 1) * column_ + j - 1;
  }
  std::vector<std::vector<Jail>> mesh2;
public:
  World();
  ~World();

  // Getters
  const int get_row(void);
  const int get_column(void);

  // Setters
  void set_row(const int row);
  void set_column(const int column);

  // Functions
  void Resize(int row, int column);
  // Jail& At(int row, int column);

  // Overloads
  // friend std::ostream & operator << (std::ostream &out, World &world);
};
