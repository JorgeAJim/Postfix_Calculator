#include "Stack_Expr_Command_Factory.h"

//
// Initialization Constructor
//
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack<int> & stack)
  :stack_ (stack) { }

//
// Deconstructor
//
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void) { }

//
// create_number_command
//
Number_Command * Stack_Expr_Command_Factory::create_number_command (int num) {
  return new Number_Command(stack_, num);
}

//
// create_add_command
//
Add_Command * Stack_Expr_Command_Factory::create_add_command (void) {
  return new Add_Command(stack_);
}

//
// create_subtract_command
//
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void) {
  return new Subtract_Command(stack_);
}

//
// create_multiply_command
//
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void) {
  return new Multiply_Command(stack_);
}

//
// create_division_command
//
Division_Command * Stack_Expr_Command_Factory::create_division_command (void) {
  return new Division_Command(stack_);
}

//
// create_modulus_command
//
Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void) {
  return new Modulus_Command(stack_);
}
