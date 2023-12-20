#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include "Stack_Expr_Command_Factory.h"
#include "Expr_Command_Factory.h"
#include "Expr_Command.h"
#include "Stack.h"
#include "Array_Iterator.h"
#include "Array.h"
#include "Queue.h"
#include <string>
#include <sstream>

/**
 * @class Calculator
 * 
 * Runs the calculator using the infix to postfix
 * algorithm.
 */
class Calculator {
public:
  /// Constructor
  Calculator (void);

  /**
   * Takes user input in the terminal and class infix_to_postfix method.
   * Then returns the final result to the terminal.
   */
  void run (void);

  /**
   * Converts inputed equations from infix format to postfix format using
   * stacks, queues, and stringstream.
   * 
   * @param[in]      string        User input
   * @param[in]      factory       Stack Command Factory Instance
   * @param[in]      postfix       Array to hold the equation in postfix order
   */
  void infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> postfix);

  /**
   * Iterate through the postfix array and execute every command.
   * The final solution should be the top of the result stack.
   * 
   * @param[in]      Iterator      Array Iterator Instance
  */
  void evaluate_postfix (Array_Iterator <Expr_Command *> & iter);

};

#include "Calculator.cpp"


#endif