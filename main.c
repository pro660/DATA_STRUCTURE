#include <stdio.h>
#include <time.h> // include clock(), CLOCKS_PER_SEC
#include "selectionSort.h"
#define MAX_SIZE 1001

int main(){
    int i,n,step=10;
    int a[MAX_SIZE];
    double duration;
    clock_t start; //save time of cpu
    clock_t end;

    printf("    n   time\n");
    for(n=0; n<=1000; n+=step){ //making array(size n)

        long repetitions=0; //실행횟수를 0으로 지정
        start = clock(); //returns the time consumed since the program started

        do{
            repetitions++; //실행횟수 세기기

            for (i = 0; i < n; i++){
                a[i]=n-i; //Create an array to worst case
            }
            
            sort(a,n); //sorting array(array name: a/ array size: n)
            end = clock();
        } while(end-start<1000); //최소 1000틱 동안 반복
        
        duration = ((double)(end-start))/CLOCKS_PER_SEC; //처음부터 현재까지 흐른 시간에 start를 뺀 실수값을 CLOCKS_PER_SEC로 나눔
        duration /= repetitions; //duration을 실행횟수로 나누어줌
                                                             //CLOCKS_PER_SEC는 틱(tick)을 초(sec)로 바꿀 때 사용하는 상수
        printf("%6d    %9d    %f\n",n,repetitions,duration);
        if(n==100)
            step=100; //n이 100이면 그때부터 증가폭을 100으로 지정
    }
    return 0;
}