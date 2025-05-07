#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 11

typedef struct{
	char key;
	//else
} element;

void stackFull();
void stackEmpty();
void push(char item); //문자를 입력하기 위해 char 타입으로 매개변수를 받아줌
element pop();

element stack[MAX_STACK_SIZE]; //구조체형 배열(스택 선언)
int top = -1;

int main(){
	
	push('A');
	push('P');
	push('P');
	push('L');
	push('E');
	printf("%c", pop());
	printf("%c", pop());
	printf("%c", pop());
	return 0;
}

void push(char item){ //top이 사이즈-1보다 크거나 같으면 Full, 따라서 종료 or Full이 아닐 시 item 삽입

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

