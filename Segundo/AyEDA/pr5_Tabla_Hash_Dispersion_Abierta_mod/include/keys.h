#include <string>
#ifndef KEYS
#define KEYS
class Keys {
private:
  int value_;
  std::string letters_;
public:
  Keys(int, std::string);
  ~Keys();


  // Getters
  int get_value(void);
  std::string get_letters(void);
};

Keys::Keys(int value, std::string letters) {
  value_ = value;
  letters_ = letters;
}

Keys::~Keys() {

}

int Keys::get_value(void) {
  return value_;
}

std::string Keys::get_letters(void) {
  return letters_;
}

#endif
