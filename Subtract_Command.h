#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Expr_Command.h"


/**
 * @class Subtract_Command
 *
 * Concrete Expr_Command that deals with subtracting two integers and returning
 * the result.
 */
class Subtract_Command : public Expr_Command {
  public:

    /**
     * Initialization Constructor
     * 
     * @param[in]    stack         The source stack
     */
    Subtract_Command (Stack <int> & s);

    /**
     * Execute Method
     *
     * Take the two top numbers from the stack and apply the subtraction
     * operation. Then push the result into the stack.
     */
    virtual void execute (void);

  private:

    /// Local stack instance
    Stack <int> & s_;
};

#include "Subtract_Command.cpp"

#endif   // !defined _SUBTRACT_COMMAND_H_