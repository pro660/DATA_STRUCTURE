#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 10
#define MALLOC(p,s)\
    if(!((p) = malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    } //매크로 함수에서 역슬래시는 줄이 끝나지 않음을 표시하는 것(\뒤에 공백 X)   

typedef struct element{
    int key;
} element;

typedef struct queue *queuePointer;
typedef struct queue{
    element data;
    queuePointer link;
} queue;

queuePointer front, rear;

void queueEmpty();
void addq(element item);
element deleteq();
void printList();



int main(){
    element item;
    /*
    item.key = 10;
    addq(item);
    item.key = 3;
    addq(item);
    item.key = 0;
    addq(item);
    */

    printList();
    deleteq();
    printf("deleted\n");
    printList();
    
    return 0;
}

void printList(){
    queuePointer temp = front;
    printf("The list contains: ");
    //printf("front->");
    for(; temp; temp=temp->link)
        printf("%4d", temp->data.key);
    //printf("   ->rear");
    printf("\n");
}

void addq(element item){
    queuePointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->data = item;
    temp->link = NULL;
    if(front)
        rear->link = temp;
    else 
        front = temp;
    
        rear = temp;
}

element deleteq(){
    queuePointer temp = front;
    element item;
    if(!temp)
        queueEmpty();
    item = temp->data;
    front = temp->link;
    free(temp);
    
    return item;
}

void queueEmpty(){
    fprintf(stderr, "queue is Empty already\n");
    exit(EXIT_FAILURE);
}