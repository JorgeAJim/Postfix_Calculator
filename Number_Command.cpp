#include "Number_Command.h"

//
// Initialization Constructor
//
Number_Command :: Number_Command (Stack <int> & s, int n) 
  : s_ (s),
  n_ (n) { }

//
// Execute
//
void Number_Command :: execute (void) {
  s_.push(this->n_);
}
