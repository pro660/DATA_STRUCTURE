#include <stdio.h>
#include <stdlib.h>

// 타입 정의
typedef enum { /** 토큰에 직접적인 이름을 부여하기 위한 enum 타입 */
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

// typedef struct {
//     char key;
// } element;

// 함수 선언
int eval(void);
precedence getToken(char*, int*);
int pop();
void push(int);
void stackFull();
void stackEmpty();
void EnterNot();

//전역 변수 선언
#define MAX_EXPR_SIZE 100
int top = -1;
#define MAX_STACK_SIZE 5
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

int main(){ 
    printf("Enter the postfix notation(Enter '~' to finish) : ");
    EnterNot();

    printf("Result => %d\n", eval());
    return 0; 
}

/** 후위 표기식을 계산하는 함수 */
int eval(void){
    precedence token;
    char symbol;
    int op1, op2;
    int n=0; /* 수식 스트링을 위한 카운터 */

    token = getToken(&symbol, &n);
    
    while(token != eos){
        if(token == operand)
            push(symbol - '0'); // 문자형 정수를 실제 정수형으로 변환
        else{
            /* 두 피연산자를 삭제하여 연산을 수행 한 후, 그 결과를 스택에 삽입함 */
            op2 = pop();
            op1 = pop();

            switch(token){
                case plus: push(op1+op2); break;
                case minus: push(op1-op2); break;
                case times: push(op1*op2); break;
                case divide: push(op1/op2); break;
                case mod: push(op1%op2); break;
                default: break;
            }
        }
        token = getToken(&symbol, &n);   
    }
    return pop();
}

/** 문자 변수와 0이 저장되어 있는 변수의 주소를 불러와서 연산자를 확인하는 함수 */
precedence getToken(char *symbol, int *n){
    *symbol = expr[(*n)++];
    
    switch(*symbol){
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '/': return divide;
        case '*': return times;
        case '%': return mod;
        case '~':
        case '\0': return eos;
        default : return operand;
    }
}

void EnterNot(){
    int n, i=0;

    while(1){
        scanf("%c", &n);
        if(n != '\n')
            expr[i++] = n;
        else 
            break;
    }
}

void push(int item){ //top이 사이즈-1보다 크거나 같으면 Full, 따라서 종료 or Full이 아닐 시 item 삽입

	if(top>=MAX_STACK_SIZE-1) {
		stackFull();
    }
	stack[++top] = item;
}

int pop(){
	if(top==-1) {
		stackEmpty();
    }
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