#ifndef _DIVISION_COMMAND_H_
#define _DIVISION_COMMAND_H_

#include "Expr_Command.h"


/**
 * @class Division_Command
 *
 * Concrete Expr_Command that deals with dividing two integers and returning
 * the result.
 */
class Division_Command : public Expr_Command {
  public:

    /**
     * Initialization Constructor
     * 
     * @param[in]    stack         The source stack
     */
    Division_Command (Stack <int> & s);

    /**
     * Execute Method
     *
     * Take the two top numbers from the stack and apply the division
     * operation upon them. Then push the result into the stack.
     */
    virtual void execute (void);

  private:

    /// Local stack instance
    Stack <int> & s_;
};

#include "Division_Command.cpp"

#endif   // !defined _DIVISION_COMMAND_H_