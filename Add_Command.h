#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Expr_Command.h"


/**
 * @class Add_Command
 *
 * Concrete Expr_Command that deals with adding two integers together.
 */
class Add_Command : public Expr_Command {
  public:

    /**
     * Initialization Constructor
     * 
     * @param[in]    stack         The source stack
     */
    Add_Command (Stack <int> & s);

    /**
     * Execute Method
     *
     * Take the two top numbers from the stack and apply the addition
     * operation upon them. Then push the result into the stack.
     */
    virtual void execute (void);

  private:

    /// Local stack instance
    Stack <int> & s_;
};

#include "Add_Command.cpp"

#endif   // !defined _ADD_COMMAND_H_