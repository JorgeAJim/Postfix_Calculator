#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Division_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"

/**
 * @interface Expr_Command_Factory
 *
 * Basic interface for the implementation of the Abstract
 * Factory Pattern.
 */
class Expr_Command_Factory {
public:

  /// Deconstructor
  virtual ~Expr_Command_Factory (void) = 0;

  /**
   * Create an instance of a number command object.
   *
   * @return       Number_Command instance
   */
  virtual Number_Command * create_number_command (int num) = 0;

  /**
   * Create an instance of an add command object.
   *
   * @return       Add_Command instance
   */
  virtual Add_Command * create_add_command (void) = 0;

  /**
   * Create an instance of a subtract command object
   *
   * @return       Subtract_Command instance
   */
  virtual Subtract_Command * create_subtract_command (void) = 0;

  /**
   * Create an instance of a Multiply_Command object.
   *
   * @return       Multiply_Command object
   */
  virtual Multiply_Command * create_multiply_command (void) = 0;

  /**
   * Create an instance of a Division_Command object
   *
   * @return       Division_Command instance 
   */
  virtual Division_Command * create_division_command (void) = 0;

  /**
   * Create an instance of a Modulus_Command object
   *
   * @return       Modulus_Command insance
   */
  virtual Modulus_Command * create_modulus_command (void) = 0;

private:
  /// Constructor
  //Expr_Command_Factory (const Expr_Command_Factory &);

  /**
   * @overload
   *
   * Overload operator= so that the lhs of the operator
   * matches the rhs of the operator.
   */
  // const Expr_Command_Factory & operator = (const Expr_Command_Factory &);

};

#include "Expr_Command_Factory.cpp"

#endif // !define _EXPR_COMMAND_FACTORY_H_