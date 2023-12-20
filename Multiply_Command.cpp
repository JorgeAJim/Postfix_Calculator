#include "Multiply_Command.h"

//
// Initialization Constructor
//
Multiply_Command :: Multiply_Command (Stack <int> & s) 
  : s_ (s) { }

//
// Execute
//
void Multiply_Command :: execute (void) {
  int n2 = s_.top();
  s_.pop();
  int n1 = s_.top();
  s_.pop();
  s_.push(n1 * n2);
}
