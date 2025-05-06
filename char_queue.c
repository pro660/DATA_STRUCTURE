#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
typedef struct{
	char key;
	
} element;
element queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;

void queueFull();
void queueEmpty();
void addq(element item);
element deleteq();

int main(){
	
	addq((element){ .key = 'A'});
	addq((element){ .key = 'P'});

	printf("%c", deleteq());
	printf("%c", deleteq());
	
	return 0;
}

void addq(element item){
	rear = (rear+1) % MAX_QUEUE_SIZE;
	if(front == rear)
		queueFull();
	queue[rear] = item;
}

element deleteq(){
	if(front == rear)
		queueEmpty();
	front = (front+1) % MAX_QUEUE_SIZE;
	return queue[front];
}

void queueFull(){
	fprintf(stderr, "Queue is Full already");
	exit(1);
}

void queueEmpty(){
	fprintf(stderr, "Queue is Empty already");
	exit(1);
}









