#ifndef VECTOR_T
#define VECTOR_T

template<class T>

class Vector_T {
private:
  T* vector_;
  int size_;
public:
  Vector_T();
  ~Vector_T();

  // Getters
  const int get_size(void);
  // Setters
  void set_size(int size);
  // Functions
  void Resize(int size);
  T& At(int position);
};

template<class T>
Vector_T<T>::Vector_T(){};


#endif