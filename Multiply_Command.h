#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Expr_Command.h"

/**
 * @class Multiply_Command
 *
 * Concrete Expr_Command that deals with multiplying two integers together.
 */
class Multiply_Command : public Expr_Command {
  public:

    /**
     * Initialization Constructor
     * 
     * @param[in]    stack         The source stack
     */
    Multiply_Command (Stack <int> & s);

    /**
     * Execute Method
     *
     * Take the two top numbers from the stack and apply the multiplication
     * operation upon them. Then push the result into the stack.
     */
    virtual void execute (void);

  private:

    /// Local stack instance
    Stack <int> & s_;
};

#include "Multiply_Command.cpp"

#endif   // !defined _MULTIPLY_COMMAND_H_