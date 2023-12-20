#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"

/**
 * @class Number_Command
 *
 * Concrete Expr_Command that deals with adding the numbers from the inputted
 * expression into the source stack.
 */
class Number_Command : public Expr_Command {
  public:

    /**
     * Initialization Constructor
     * 
     * @param[in]    stack         The source stack
     * @param[in]    integer       Number from the inputted expression
     */
    Number_Command (Stack <int> & s, int n);

    /**
     * Execute Method
     *
     * Insert the number into the stack.
     */
    virtual void execute (void);

  private:

    /// Local stack instance
    Stack <int> & s_;

    /// Number from the inputted expression
    int n_;
};

#include "Number_Command.cpp"

#endif   // !defined _NUMBER_COMMAND_H_