#include <stdio.h>
#define MAX_TERMS 101 

typedef struct 
{
	int col;
	int row;
	int value;
} term;

void transpose(term a[],term b[]);
void matrix_Input(term a[]);
void matrix_Output(term trans_a[]);

term a[MAX_TERMS];
term trans_a[MAX_TERMS];

int main(){
	
	matrix_Input(a);
	transpose(a,trans_a);
	matrix_Output(trans_a);
	
	return 0;
}

void matrix_Input(term a[]){
	
	int i;
	
	printf("Enter the size of matrix, count of numbers: \nRow Column Value\n");
	scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);
	
	printf("Enter the location of value and the value: \nRow Column Value\n");
	for(i=1; i<=a[0].value; i++){
		scanf("%d %d %d",&a[i].row ,&a[i].col ,&a[i].value );
	}
}

void matrix_Output(term trans_a[]){
	
	int i;
	
	printf("\nTransposed matrix:\n");
	for(i = 1; i <= trans_a[0].value; i++) {
		printf("Row: %d, Column: %d, Value: %d\n", trans_a[i].row, trans_a[i].col, trans_a[i].value);
	}
}

void transpose (term a[], term b[]){

	int n, i, j, currentb;

	n = a[0].value;

	b[0].row = a[0].col; 
	b[0].col = a[0].row; 

	b[0].value = n;

    if (n>0) {
	    currentb = 1;
	    for(i=0;  i<a[0].col; i++)
	        for(j=1;  j<=n;  j++)
	            if(a[j].col == i) {
		            b[currentb].row = a[j].col;
		            b[currentb].col = a[j].row;
		            b[currentb].value = a[j].value;
		            currentb++;
		        }
	}
}

