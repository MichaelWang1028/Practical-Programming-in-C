#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
	queue_infix = expr_to_infix(strbuffer);

	/* get queue of tokens in postfix order from infix-ordered queue */
	queue_postfix = infix_to_postfix(&queue_infix);

	/* get answer from postfix-ordered queue */
	ans = evaluate_postfix(&queue_postfix);

	free(strbuffer); /* free memory from heap */
	return ans;
}

/* constructs a queue of tokens in infix order from a space-delimited string */
token_queue expr_to_infix(char * str) {
	token_queue queue_infix; /* queue with infix ordering */
	enum token_type type = OPERATOR;
	union token_value value;

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
				type = OPERATOR;
				value.op_code = ADD;
				break;
			case '-':
				/* check previous token to distinguish between
				   negate (unary) and subtract (binary) */
				if (type == OPERATOR)
					value.op_code = NEGATE; /* unary */
#if PARSE_PARENS
				else if (type == LPARENS)
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
#if PARSE_PARENS
			case '(':
				type = LPARENS;
				break;
			case ')':
				type = RPARENS;
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
		enqueue(&queue_infix, new_token(type, value));
	}
	return queue_infix;
}

/* creates a queue of tokens in postfix order from a queue of tokens in infix order */
/* postcondition: returned queue contains all the tokens, and pqueue_infix should be
   empty */
token_queue infix_to_postfix(token_queue * pqueue_infix) {
	/* TODO: construct postfix-ordered queue from infix-ordered queue;
	   all tokens from infix queue should be added to postfix queue or freed */

	token_queue infix_to_postfix_queue;
	p_expr_token operator_stack = NULL;

	while (true) {
		p_expr_token temp_token = dequeue(pqueue_infix);
		if (temp_token == NULL) {
			break;
		}
		enum token_type type = temp_token->type;
		union token_value value = temp_token->value;

		if (type == OPERAND) {
			printf("Value %g\n", value.operand);
		} else if (type == OPERATOR){
			push(&operator_stack, temp_token);
			printf("Operator %c\n", operators[value.op_code]);
		}
	}

	while(true) {
		p_expr_token temp_token = pop(&operator_stack);
		if (temp_token == NULL) {
			break;
		}

		union token_value value = temp_token->value;
		printf("%c\t", operators[value.op_code]);
	}
	puts("");


	return infix_to_postfix_queue;
}

/* evalutes the postfix expression stored in the queue */
/* postcondition: returned value is final answer, and pqueue_postfix should be empty */
double evaluate_postfix(token_queue * pqueue_postfix) {
	/* TODO: process postfix-ordered queue and return final answer;
	   all tokens from postfix-ordered queue is freed */
}
