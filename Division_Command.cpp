#include "Division_Command.h"

//
// Initialization Constructor
//
Division_Command :: Division_Command (Stack <int> & s) 
  : s_ (s) { }

//
// Execute
//
void Division_Command :: execute (void) {
    // COMMENT: Your code will crash if you have divide by 0.

    // REPLY: I added a if-statement to check if the second number is zero. If it is,
    // then throw an exception.

  int n2 = s_.top();
  s_.pop();
  int n1 = s_.top();
  s_.pop();

  if (n2 == 0){
    throw std::runtime_error("Divide by zero error");
  }

  s_.push(n1 / n2);
}

