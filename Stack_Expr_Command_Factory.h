#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"
#include "Stack.h"

class Stack_Expr_Command_Factory: public Expr_Command_Factory {
public:
  /// Constructor
  Stack_Expr_Command_Factory (Stack <int> & stack);

  /// Deconstructor
  ~Stack_Expr_Command_Factory (void);

  /// Return pointer to a Number_Command
  Number_Command * create_number_command (int num);

  /// Return a pointer to a new Add_Command instance
  Add_Command * create_add_command (void);

  /// Return a pointer to a new Subtract_Command instance
  Subtract_Command * create_subtract_command (void);

  /// Return a pointer to a new Multiply_Command instance
  Multiply_Command * create_multiply_command (void);

  /// Return a pointer to a new Division_Command instance
  Division_Command * create_division_command (void);

  /// Return a pointer to a new Modulus_Command instance
  Modulus_Command * create_modulus_command (void);

private:
  Stack <int> & stack_;
};

#include "Stack_Expr_Command_Factory.cpp"

#endif // !define _STACK_EXPR_COMMAND_FACOTORY_H_