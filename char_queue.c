#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
typedef struct{ //구조체 선언
	char key;
	
} element;
element queue[MAX_QUEUE_SIZE];
int front = 0; //원형 큐 이므로 -1이 아닌 0으로 설정
int rear = 0;

void queueFull();
void queueEmpty();
void addq(element item);
element deleteq();

int main(){
	
	addq((element){ .key = 'A'}); // char자료형을 사용하지 않고 직접 구조체 자료형으로 입력
	addq((element){ .key = 'P'});

	printf("%c", deleteq());
	printf("%c", deleteq());
	
	return 0;
}

void addq(element item){
	rear = (rear+1) % MAX_QUEUE_SIZE; //원형 큐는 1자리 비어있는 것이 Full인 상태
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









