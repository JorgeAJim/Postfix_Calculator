#include "Add_Command.h"

//
// Initialization Constructor
//
Add_Command :: Add_Command (Stack <int> & s) 
  : s_ (s) { }

//
// Execute
//
void Add_Command :: execute (void) {
  int n2 = s_.top();
  s_.pop();
  int n1 = s_.top();
  s_.pop();
  s_.push(n1 + n2);
}
