#ifndef EVALUATION_H
#define EVALUATION_H

/* constructs a queue of tokens in infix order from a space-delimited string */
token_queue convert_expression_to_infix_queue(char * str);

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be
   empty */
token_queue convert_infix_to_postfix_queue(token_queue * pqueue_infix);

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix_queue(token_queue * pqueue_postfix);

/* handles evaluation process (calls above functions) for expression string str */
double evaluate(const char * str);

void print_queue(token_queue * pointer_to_queue);

#endif
