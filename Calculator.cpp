#include "Calculator.h"

//
// Constructor
//
Calculator :: Calculator (void) { }

//
// run
//
void Calculator :: run (void) {
  // Store the final result
  Stack <int> result;

  // Stores the user's input
  std::string infix;

  Stack_Expr_Command_Factory factory(result);

  bool keep_going = true;

  while(keep_going) {
    try{
      // clean resources used
      infix.clear();
      result.clear();

      std::cout<< "Enter a mathematical equation: " << std::endl;
      std::getline(std::cin, infix);

      if (infix == "QUIT") {
        keep_going = false;
        break;
      }

      Array <Expr_Command *> postfix;
      infix_to_postfix (infix, factory, postfix);

      int res = result.top();
      std::cout << res << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
    catch (...) {
      std::cout << "Invalid input" << std::endl;
    }
  } 
}

//
// infix_to_postfix
//
void Calculator :: infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> postfix) {
  // Use a stream to seperate the elements in the input equation
  std::istringstream input(infix);
  std::string token;
  Expr_Command * cmd = 0;
  Stack <Expr_Command *> temp;

  // Use a second stack to hold a history of priorities
  Stack <int> operation_priority;

  // Create a queue to hold all the number commands.
  Queue <Expr_Command *> queue;

  // Stack to hold the different parentheses levels, to
  // deal with nested loops.
  int parenthesis_level = 0;
  Stack <int> parentheses;


  // Determine if the token is an operator command, or a number command. If operator command, create instace
  // of the operator command to be inserted into postfix array. Insert number command instance into the temp
  // stack to keep track of the order the numbers arrived in.
  while (std::getline(input, token, ' ')) {
    int priority = 0;

    if(token == "+") {
      cmd = factory.create_add_command();
      priority = 1;
    }
    else if (token == "-") {
      cmd = factory.create_subtract_command();
      priority = 1;
    }
    else if (token == "*") {
      cmd = factory.create_multiply_command();
      priority = 2;
    }
    else if (token == "/") {
      cmd = factory.create_division_command();
      priority = 2;
    }
    else if (token == "%") {
      cmd = factory.create_modulus_command();
      priority = 2;
    }
    else if (token == "(") {
        // COMMENT: Create a design that does not require having parenthesis as
        // as command object since parenthesis are not executed.
        
        // REPLY: I removed the open_command class. I still try to use the open parenthesis
        // to determine how many operations to pop from the stack. I do this by storing what
        // level of nested loop I am in and then poping from the stack until I return to a
        // parenthesis of level zero.

      parenthesis_level++; 

      // Force the while loop to move onto the next iteration
      continue;
    }
    else if (token == ")") {
      parenthesis_level--;

      // Check if the open parentheis created an instance in the parenthesis_operator stack
      if (parenthesis_level < 0) {
        throw std::runtime_error("Unmatched parenthesis");
      }

      // Pop from the operator stack into the postfix array based on how may operators are in the parenthesis
      while (!temp.is_empty() && !parentheses.is_empty() && (parenthesis_level < parentheses.top())) {
        queue.enqueue(temp.top());
        temp.pop();
        operation_priority.pop();
        parentheses.pop();
      }

      continue;

    }
    else {
      // Turn string token into an integer
      int num_token = std::stoi(token);
      cmd = factory.create_number_command(num_token);

      // Number commands don't go into the temp stack, they go into the postfix array.
      // Use a queue to hold the number commands until ready to insert into postfix array,
      queue.enqueue(cmd);

      // Since number operators aren't being placed in the stack, the code shouldn't continue pass this
      // point. Thus, the continue keyword is used to move to the next iteration of the while loop
      continue;
    }

    // Push the operator commands into the stack, if stack is empty or if it's priority is greather
    // than the current priority ontop of the of the priority stack
    if (priority > 0 && (temp.is_empty() || (priority > operation_priority.top()) || parenthesis_level > 0)) {
      temp.push(cmd);
      operation_priority.push(priority);
      parentheses.push(parenthesis_level);
    }
    else {
      // Add the operator to the postfix queue
      queue.enqueue(temp.top());

      // Clear the top operator, its priority, and its parentheses' level
      temp.pop();
      operation_priority.pop();
      parentheses.push(parenthesis_level);

      // Push the new item, its priority, and its parentheses' level
      temp.push(cmd);
      operation_priority.push(priority);
      parentheses.push(parenthesis_level);
    }

  }

  // Push any remaining operators out of the stack and into the queue
  while (!temp.is_empty()) {
    queue.enqueue(temp.top());
    temp.pop();
  }

  // Move everything to the postfix array
  postfix.resize(queue.size());
  
  int i = 0;
  while (!queue.is_empty()){
    Expr_Command * postfix_cmd = queue.dequeue();

    postfix[i] = postfix_cmd;

    i++;
  }

  // Create an Array_Iterator instance to go through the postfix array
  Array_Iterator <Expr_Command *> iter(postfix);
  evaluate_postfix(iter);
}

//
// evaluate_postfix
//
void Calculator :: evaluate_postfix (Array_Iterator <Expr_Command *> & iter) {
  for(; !iter.is_done(); iter.advance()) {
    (*iter)->execute();
    delete *iter;
  }
}
