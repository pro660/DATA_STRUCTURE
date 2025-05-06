#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 11

typedef struct{
	char key;
	//else
} element;

void stackFull();
void stackEmpty();
void push(char item);
element pop();

element stack[MAX_STACK_SIZE];
int top = -1;

int main(){
	
	push('A');
	printf("%c", pop());
	
	return 0;
}

void push(char item){

	if(top>=MAX_STACK_SIZE-1)	
		stackFull();
		
	stack[++top].key = item;
}

element pop(){
	if(top==-1)
		stackEmpty();
	
	return stack[top--];
}

void stackFull(){
	fprintf(stderr, "stack is Full already");
	exit(1);
}

void stackEmpty(){
	fprintf(stderr, "stack is Empty already");
	exit(1);
}

