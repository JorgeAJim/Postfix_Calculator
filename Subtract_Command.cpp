#include "Subtract_Command.h"

//
// Initialization Constructor
//
Subtract_Command :: Subtract_Command (Stack <int> & s) 
  : s_ (s) { }

//
// Execute
//
void Subtract_Command :: execute (void) {
  int n2 = s_.top();
  s_.pop();
  int n1 = s_.top();
  s_.pop();
  s_.push(n1 - n2);
}
