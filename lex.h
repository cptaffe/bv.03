#include <stdlib.h>
#include <stdio.h>

#import "stack.h"

typedef struct {
	FILE *input;
	stack *stack;
} lexer;

// error throwing
void error(char *str) {printf("err: %s\n", str); exit(1);}

// next character
char next(lexer *l) {return getc(l->input);}

// backup character
char backup(lexer *l, char c) {return ungetc(c, l->input);}

lexer *lex_init(FILE *file) {
	lexer *lexer = calloc(1, sizeof(lexer));
	lexer->input = file;
	lexer->stack = stack_init(10);
	return lexer;
}

void lex_push(lexer *l, void *ptr) {
	stack_push(l->stack, ptr);
}

// lexes keywords or function handles
void lex_keyword(lexer *l, void *ptr) {
	char *str = calloc(100, sizeof (char));
	char c; int j = 0;
	for (int i = 0; (c = next(l)) != EOF; i++) {
		// lex until special or space character
		if (!isspecial(c) && !isspace(c)) {
			str[j++] = c;
		} else {
			// handle special or space character
			if (isspecial(c) && c != ')' && c != '(') {
				error("unknown special character");
			} else if (c == '(') {
				// string is function handle
			}
			str[j+1] = '\0'; // c string
			lex_push(l, str);
		}
	}
	error("unexpected EOF");
}

void lex_function()



// takes file to lex, returns stack.
stack *lex(FILE *file){
	lexer *l = lex_init(file);
	char c;
	while ((c = next(l)) != EOF) {
		printf("FUCK\n");
	}
	stack* stack = l->stack;
	free(l);
	return stack;
}