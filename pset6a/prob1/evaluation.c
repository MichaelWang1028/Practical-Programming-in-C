#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prob1.h"
#include "evaluation.h"

/* handles evaluation process (calls above functions) for expression string str */
/* returns the final answer */
double evaluate(const char * str) {
	char * strbuffer; /* mutable buffer for string (modified in calls to strtok()) */
	double ans; /* answer to return */
	token_queue queue_infix, queue_postfix;

	/* copy str into mutable buffer */
	strbuffer = strcpy((char *)malloc(strlen(str)+1),str);

	/* get queue of tokens in infix order from string buffer */
	queue_infix = convert_expression_to_infix_queue(strbuffer);

	/* get queue of tokens in postfix order from infix-ordered queue */
	queue_postfix = convert_infix_to_postfix_queue(&queue_infix);

	/* get answer from postfix-ordered queue */
	ans = evaluate_postfix_queue(&queue_postfix);

	free(strbuffer); /* free memory from heap */
	return ans;
}

/* constructs a queue of tokens in infix order from a space-delimited string */
token_queue convert_expression_to_infix_queue(char * str) {
	token_queue queue_infix; /* queue with infix ordering */
	enum token_type type = OPERATOR;
	token_value value;

	/* initialize the queue to empty */
	queue_infix.front = NULL;
	queue_infix.back = NULL;

	/* delimiter string for strtok() -- contains whitespace characters */
#define DELIMS_STR " \n\r\t"
	for (str = strtok(str, DELIMS_STR); str; str = strtok(NULL, DELIMS_STR)) {
		/* parse token */
		if (strlen(str) == 1) { /* operators are all 1 character */
			switch (str[0]) {
			case '+':
				if (type == OPERATOR){
					value.op_code = KEEP; /* unary */
        }
#if PARSE_PARENTHESES
				else if (type == LEFT_PARENTHESES)
					value.op_code = KEEP; /* unary */
#endif
				else
					value.op_code = ADD; /* binary */
				type = OPERATOR;
				break;
			case '-':
				/* check previous token to distinguish between
				   negate (unary) and subtract (binary) */
				if (type == OPERATOR){
					value.op_code = NEGATE; /* unary */
        }
#if PARSE_PARENTHESES
				else if (type == LEFT_PARENTHESES)
					value.op_code = NEGATE; /* unary */
#endif
				else
					value.op_code = SUBTRACT; /* binary */
				type = OPERATOR;
				break;
			case '*':
				type = OPERATOR;
				value.op_code = MULTIPLY;
				break;
			case '/':
				type = OPERATOR;
				value.op_code = DIVIDE;
				break;
#if PARSE_PARENTHESES
			case '(':
				type = LEFT_PARENTHESES;
				break;
			case ')':
				type = RIGHT_PARENTHESES;
				break;
#endif
			default:
				/* not an operator */
				type = OPERAND;
				value.operand = strtod(str, NULL);
			}
		} else {
			type = OPERAND;
			value.operand = strtod(str, NULL);
		}
		/* add token with parsed type and value to end of queue */
		enqueue(&queue_infix, create_new_token(type, value));
	}
	return queue_infix;
}

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be
   empty */
token_queue convert_infix_to_postfix_queue(token_queue * pqueue_infix) {
	token_queue infix_to_postfix_queue;
  infix_to_postfix_queue.front = NULL;
  infix_to_postfix_queue.back = NULL;

	p_expr_token operator_stack_top = NULL;
  p_expr_token current_token = NULL;

	while ((current_token = dequeue(pqueue_infix))) {
		enum token_type type = current_token->type;
		token_value value = current_token->value;

		if (type == OPERAND) {
			enqueue(&infix_to_postfix_queue, create_new_token(type, value));
      free(current_token);
		}

		if (type == LEFT_PARENTHESES) {
			push(&operator_stack_top, current_token);
		}

		if (type == RIGHT_PARENTHESES) {
			p_expr_token stack_token = NULL;

			while (true) {
				stack_token = pop(&operator_stack_top);
				enum token_type stack_type = stack_token->type;
				token_value stack_value = stack_token->value;

				if (stack_type == LEFT_PARENTHESES) {
					free(stack_token);
					free(current_token);
					break;
				}

				enqueue(&infix_to_postfix_queue, create_new_token(stack_type, stack_value));
				free(stack_token);
			}
		}

		if (type == OPERATOR){
      p_expr_token stack_token = NULL;

      while ((stack_token = pop(&operator_stack_top))) {
        enum token_type stack_type = stack_token->type;
        token_value stack_value = stack_token->value;

				if (stack_type == LEFT_PARENTHESES) {
					push(&operator_stack_top, stack_token);
					break;
				}

        if (should_enqueue_operator(value, stack_value)) {
          enqueue(&infix_to_postfix_queue, create_new_token(stack_type, stack_value));
          free(stack_token);
        } else {
          push(&operator_stack_top, stack_token);
          break;
        }
      }
			push(&operator_stack_top, current_token);
		}
	}

  while ((current_token = pop(&operator_stack_top))) {
    enqueue(&infix_to_postfix_queue, create_new_token(current_token->type, current_token->value));
    free(current_token);
  }

	return infix_to_postfix_queue;
}

bool should_enqueue_operator(token_value current_value, token_value stack_value)
{
  int current_precedence = op_precedences[current_value.op_code];
  int current_associativity = op_associativity[current_precedence];
  int stack_precedence = op_precedences[stack_value.op_code];

  return (current_precedence < stack_precedence) || (current_precedence == stack_precedence && current_associativity == LEFT);
}

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix_queue(token_queue * pqueue_postfix) {
	/* TODO: process postfix-ordered queue and return final answer;
	   all tokens from postfix-ordered queue is freed */
  p_expr_token stack_result = NULL;
  p_expr_token current_token = NULL;

  int counter = 0;

  while ((current_token = dequeue(pqueue_postfix)))  {
    counter++;
    enum token_type type = current_token->type;
    token_value value = current_token->value;

    if (type == OPERAND) {
      push(&stack_result, current_token);
    } else if (type == OPERATOR) {
      free(current_token);
      p_expr_token stack_token = pop(&stack_result);
      double result = stack_token->value.operand;
      free(stack_token);

      if (value.op_code == NEGATE) {
        result *= -1;
      }

      for (unsigned int i = 0; i < op_operands[value.op_code] - 1; i++) {
        stack_token = pop(&stack_result);
        double current_value = stack_token->value.operand;
        free(stack_token);
        switch (value.op_code) {
          case ADD:
            result += current_value;
            break;
          case SUBTRACT:
            result -= current_value;
            result *= -1;
            break;
          case MULTIPLY:
            result *= current_value;
            break;
          case DIVIDE:
            result /= current_value;
            result = 1 / result;
            break;
					case KEEP:
          case NEGATE:
            break;
        }
      }

      enum token_type type = OPERAND;
    	token_value value;
      value.operand = result;

      push(&stack_result, create_new_token(type, value));
    }
  }

  p_expr_token last_token = pop(&stack_result);
  double final_result = last_token->value.operand;
  free(last_token);

  return final_result;
}

void print_queue(token_queue * pointer_to_queue)
{
  while (true) {
    p_expr_token expression_token = dequeue(pointer_to_queue);
    if (expression_token == NULL) {
      break;
    }
    enum token_type type = expression_token->type;
    token_value value = expression_token->value;

    if (type == OPERAND) {
      printf("%f\t", value.operand);
    } else if (type == OPERATOR) {
      printf("%c\t", operators[value.op_code]);
    }
  }
  puts("");
}
