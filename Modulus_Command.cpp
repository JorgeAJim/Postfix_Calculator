#include "Modulus_Command.h"

//
// Initialization Constructor
//
Modulus_Command :: Modulus_Command (Stack <int> & s) 
  : s_ (s) { }

//
// Execute
//
void Modulus_Command :: execute (void) {
  int n2 = s_.top();
  s_.pop();
  int n1 = s_.top();
  s_.pop();

  if (n2 == 0){
    throw std::runtime_error("Mod by zero error");
  }

  s_.push(n1 % n2);
}
