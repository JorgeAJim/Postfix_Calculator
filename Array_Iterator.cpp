#include "Array_Iterator.h"

//
// Initialization Constructor
//
template <typename T>
Array_Iterator<T>::Array_Iterator (Array<T> & a)
  :arr_ (a),
  curr_ (0) { }

//
// Deconstructor
//
template <typename T>
Array_Iterator<T>::~Array_Iterator (void) { };

//
// is_done
//
template <typename T>
bool Array_Iterator<T>::is_done (void) {
  return this->curr_ >= this->arr_.size();
}

//
// advance
//
template <typename T>
void Array_Iterator<T>::advance (void) {
  this->curr_++;
}

//
// operator * overload
//
template <typename T>
T & Array_Iterator <T>::operator* (void) {
  return this->arr_[this->curr_];
}

//
// operator -> overload
//
template <typename T>
T * Array_Iterator<T>::operator-> (void) {
  return &this->arr_[this->curr_];
}