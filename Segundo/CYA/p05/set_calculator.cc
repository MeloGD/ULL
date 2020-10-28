#include "set_calculator.h"

Set::Set(){
    size_ = sizeof(long);
    set_vector_.resize (size_);
}

Set::Set(int size) {
    size_ = size;
    set_vector_.resize (size_);
}

Set::~Set() {}

void Set::Print(void) {
    cout << "Tamaño del size_" << endl;
    cout << size_ << endl;
    cout << "Tamaño del set_vector_" << endl;
    cout << set_vector_.size() << endl;
}