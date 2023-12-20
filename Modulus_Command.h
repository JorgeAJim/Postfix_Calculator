#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"


/**
 * @class Modulus_Command
 *
 * Concrete Expr_Command that deals with using mod on two numbers.
 */
class Modulus_Command : public Expr_Command {
  public:

    /**
     * Initialization Constructor
     * 
     * @param[in]    stack         The source stack
     */
    Modulus_Command (Stack <int> & s);

    /**
     * Execute Method
     *
     * Take the two top numbers from the stack and apply the modulus
     * operation upon them. Then push the result into the stack.
     */
    virtual void execute (void);

  private:

    /// Local stack instance
    Stack <int> & s_;
};

#include "Modulus_Command.cpp"

#endif   // !defined _MODULUS_COMMAND_H_