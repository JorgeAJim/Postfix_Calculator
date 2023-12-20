#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#include "Stack.h"

/**
 * @interface Expr_Command
 *
 * Template for the different commands the calculator must perform.
 */
class Expr_Command {
  public:
    /**
     * Execute method
     *
     * Take two elements from the stack and use the appropriate
     * mathematical operations on it. Then return it to the stack.
     */
    virtual void execute (void) = 0;

};

#endif   // !defined _EXPR_COMMAND_H_