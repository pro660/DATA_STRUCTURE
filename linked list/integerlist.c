#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
    if(!((p) = malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    } //매크로 함수에서 역슬래시는 줄이 끝나지 않음을 표시하는 것(\뒤에 공백 X)

//구조체 선언
typedef struct listNode *listPointer; 
typedef struct listNode{

    int data;
    listPointer link;
} listNode;


//함수 선언
listPointer create2();
void printList();
void insert(listPointer *first, listPointer x);
void delete(listPointer *first, listPointer trail, listPointer x);

//전역 변수 선언
listPointer first = NULL;

int main(){

    create2();
    insert(&first, first);
    delete(&first, first, first->link);
    printList();

    return 0;
}

//링크드리스트 생성 함수
listPointer create2(){
    listPointer second;
    MALLOC(first, sizeof(*first));
    MALLOC(second, sizeof(*second));
    
    second->link = NULL;
    second->data = 20;
    first->data = 10;

    first->link = second;
    
    return second;
}

//리스트 출력 함수
void printList(){
    printf("The list contains: ");
    for(; first; first = first->link)
        printf("%4d", first->data);
}

void insert(listPointer *first, listPointer x){ //x는 선행노드
    listPointer temp;

    MALLOC(temp, sizeof(*temp));
    temp->data = 50;

    if(*first){
        temp->link = x->link;
        x->link = temp;
    }
    else{
        temp->link = NULL;
        *first = temp;

    }
}

void delete(listPointer *first, listPointer trail, listPointer x){ //trail:이전노드, x:삭제할 노드
    if(trail)
        trail->link = x->link;
    else
        *first = (*first)->link;

    free(x);
}
