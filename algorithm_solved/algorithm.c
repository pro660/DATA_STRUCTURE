#include <stdio.h>
#define SIZE 100000

void solve();
void push(int item);
int pop();

int stack[SIZE];
int top = -1;

int main(){

    solve();
    return 0;

}

void solve(){
    int k, i, num, sum=0;

    scanf("%d", &k);

    for(i=0; i<k; i++){
        scanf("%d", &num);
        if(num == 0)
            pop();
        else
            push(num);
    }

    for(i=0; i<top+1; i++)
        sum+=stack[i];
    
    printf("%d", sum);
}

void push(int item){
    stack[++top] = item;
}

int pop(){
    return stack[top--];
}