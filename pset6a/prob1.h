#ifndef PROB1_H
#define PROB1_H

/* maximum length of input string (including newline character) */
#define INPUT_MAX 2048

/* enable (1) or disable (0) parentheses checking in parsing strings */
/* leave disabled for part (a); enable for part (b) */
#define PARSE_PARENS 0

/* type of token */
enum token_type {
	OPERAND, /* number */
	OPERATOR, /* operator: +, -, *, / */
#if PARSE_PARENS
	LPARENS, /* left parentheses ( */
	RPARENS /* right parentheses ) */
#endif
};

#endif
