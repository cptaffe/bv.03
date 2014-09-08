typedef struct {
	int len;
	int size;
	void **stack;
} stack;

stack *stack_init(int size) {
	stack *stack = calloc(1, sizeof (stack));
	stack->stack = malloc(size * sizeof (void *));
	stack->size = size;
	return stack;
}

stack *stack_expand(stack *stack) {
	int size = (stack->size * 2);
	stack->stack = realloc(stack->stack, size);
	stack->size = size;
	return stack;
}

stack *stack_push(stack *stack, void *ptr) {
	if ((stack->len - 1) >= stack->size) {
		stack = stack_expand(stack);
	}
	stack->stack[stack->len++] = ptr;
	return stack;
}