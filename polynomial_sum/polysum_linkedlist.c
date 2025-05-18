#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y)((x)<(y)?-1:(x)==(y)?0:1)
#define MALLOC(p,s)\
    if(!((p) = malloc(s))){\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

typedef struct polyNode *polyPointer;
typedef struct polyNode{
    int coef;
    int expon;
    polyPointer link;
} polyNode;

polyPointer a = NULL, b = NULL;

polyPointer padd(polyPointer a, polyPointer b);
void attach(int coefficient, int exponent, polyPointer *ptr);

int main(){
    // 5x^5 + 3x^2
    attach(5, 5, &a);
    attach(3, 2, &a);

    // 7x^4 + x^2 + 5x^0
    attach(7, 4, &b);
    attach(1, 2, &b);
    attach(5, 0, &b);

    polyPointer result = padd(a, b);
    polyPointer temp;

    for (temp=result; temp; temp = temp->link){
        printf("%dx^%d ", temp->coef, temp->expon);
        if(temp->expon)
            printf("+ ");
    }
    printf("\n");

    return 0;
}

polyPointer padd(polyPointer a, polyPointer b) {
    polyPointer c = NULL; // 결과 리스트 초기화
    polyPointer rear = NULL; // 마지막 노드 초기화
    int sum;

    while (a && b) {
        switch (COMPARE(a->expon, b->expon)) {
            case -1:
                attach(b->coef, b->expon, &rear);
                b = b->link;
                break;
            case 0:
                sum = a->coef + b->coef;
                if (sum)
                    attach(sum, a->expon, &rear);
                a = a->link;
                b = b->link;
                break;
            case 1:
                attach(a->coef, a->expon, &rear);
                a = a->link;
        }
        
        // 결과 리스트의 첫 번째 노드 설정
        if (!c) {
            c = rear; 
        }
    }

    for (; a; a = a->link)
        attach(a->coef, a->expon, &rear);
    for (; b; b = b->link)
        attach(b->coef, b->expon, &rear);

    return c; // 결과 리스트 반환
}

void attach(int coefficient, int exponent, polyPointer *ptr) {
    polyPointer temp;
    MALLOC(temp, sizeof(*temp));

    temp->coef = coefficient;
    temp->expon = exponent;
    temp->link = NULL;

    if (*ptr) {
        polyPointer rear = *ptr;
        while (rear->link) rear = rear->link; // 마지막 노드 찾기
        rear->link = temp; // 새 노드 추가
    } else {
        *ptr = temp; 
    }
}
