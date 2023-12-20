#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"

/**
 * @class Array_Iterator
 *
 * Implementation of the iterator pattern for use in prefix to postfix and
 * to create evaluate the postfix.
 */
template <typename T>
class Array_Iterator {
public:

  /// Initialization Constructor
  Array_Iterator (Array<T> & a);

  /// Destructor
  ~Array_Iterator (void);

  /**
   * Method used to determined if the array has been fully 
   * iterated through.
   *
   * @return       True or False
   */
  bool is_done (void);

  /**
   * Method used to advance the iterator.
   */
  void advance (void);

  /**
   * @overload
   *
   * Provide access to the data inside the source array by
   * dereferencing the pointer.
   *
   * @return       The data at the current index
   */
  T & operator * (void);

  /**
   * @overload
   *
   * Provide access to the data inside the source array by
   * overloading the -> operator.
   *
   * @return       The data at the current index
   */
  T * operator -> (void);

private:

  /// Local instance of the source array
  Array <T> & arr_;

  /// The current location of the iterator
  size_t curr_;

};

#include "Array_Iterator.cpp"

#endif // !define _ARRAY_ITERATOR_H