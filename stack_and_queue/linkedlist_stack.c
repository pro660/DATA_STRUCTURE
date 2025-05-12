#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10
#define MALLOC(p,s)\
    if(!((p) = malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    } //매크로 함수에서 역슬래시는 줄이 끝나지 않음을 표시하는 것(\뒤에 공백 X)   

typedef struct element{
    int key;
} element;

typedef struct stack *stack_pointer;
typedef struct stack{
    element item;
    stack_pointer link;
} stack;

void stackEmpty();
void push(element item);
element pop();
void printList();

stack_pointer top = NULL;

int main(){
    element item;
    item.key = 5;
    push(item);
    item.key = 3;
    push(item);
    item.key = 1;
    push(item);
    
    printList();
    pop();
    printf("popped\n");
    printList();
    
    return 0;
}

void printList(){
    stack_pointer temp = top;
    printf("The list contains: ");
    printf("top->");
    for(; temp; temp=temp->link)
        printf("%4d", temp->item.key);
    printf("  ->NULL");
    printf("\n");
}

void push(element item){
    stack_pointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->item = item;
    temp->link = top;
    top = temp;
}

element pop(){
    stack_pointer temp = top;
    element item;
    if(!temp)
        stackEmpty();
    item = temp->item;
    top = temp->link;
    free(temp);
    
    return item;
}

void stackEmpty(){
    fprintf(stderr, "stack is Empty already\n");
    exit(EXIT_FAILURE);
}