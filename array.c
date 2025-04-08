#include <stdio.h>
#include <stdlib.h> //rand() 헤더파일일
#define MAX_SIZE 5
void print1(int *, int); //함수 선언

int main(){
    int i;
    int array[MAX_SIZE];

    for(i=0; i<MAX_SIZE; i++) //랜덤으로 MAX_SIZE 개수만큼 수를 리스트에 저장장
        array[i]=rand() % 1000; 
    
    print1(array,MAX_SIZE);

    return 0;
}

void print1(int *ptr, int rows){ //리스트는 0번 인덱스의 주소값을 가짐짐
    int i;

    printf("Address Contents\n");

    for(i=0; i<rows; i++)
        printf("%8u%5d\n", ptr+i, *(ptr+i)); //참조연산자로 주소 값과 주소 위치에 할당된 값을 출력

    printf("\n");
}
