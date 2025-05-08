#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
void sort(int [], int);
int binsearch(int [], int, int, int);
int compare(int, int);
int main(void)
{
	int i, n, seed, searchnum;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: "); 
	scanf("%d", &n); 
	
	if (n < 1 || n > MAX_SIZE)	{  //If the value of n is less than 1 or greater than 101, which is set to MAX_SIZE, an error message is printed and the program is terminated.
		fprintf(stderr, "Improper value of n\n");
		exit(1);
}
	printf("Enter your favorite number: ");//input seed value
	scanf("%d",&seed);
	
	srand(seed); //Change the seed value using the srand function  
	for (i = 0; i < n; i++)	{ //Generate numbers randomly and put them in a list 
		list[i] = rand() % 1000; 
		printf("%d", list[i]); printf(" "); //Separate numbers with blanks when printing
}
	
	sort(list, n); //sort list
	
	printf("\n Sorted array:\n");
	for (i=0; i<n; i++){	//Print the element values of the list
		printf("%d", list[i]); printf(" ");}
		printf("\n");
		
	printf("\nEnter the number you want to find: "); //Enter number to find
	scanf("%d",&searchnum);
	
	if(binsearch(list,searchnum,0,n-1)==-1) //find searchnum using binary search
		printf("No value found");
	else{
		printf("The value you are looking for is at index value %d.\n",binsearch(list,searchnum,0,n-1));
	}
	return 0;
}

void sort(int list[], int n) //Sorts the element values in the list in ascending order.
{
	int i, j, min, temp;
	for(i=0; i < n - 1; i++)	{ //Set i to the initial value in min (i is an index value, not an element value)
		min = i;
		for (j=i + 1; j < n; j++) //Find the smallest element value among the element values ??in the list and store the index value of that element value in min. 
			if (list[j] < list[min]) 
				min = j;
		SWAP(list[i], list[min], temp); //Put the smallest element value in the smallest index value position (sort in ascending order)
}
}

int binsearch(int list[], int searchnum, int left, int right) //parameter is one list, three integer
{
	int middle;

	if (left <= right)	{
		middle = (left+right)/2;
		switch(compare(list[middle], searchnum))	{ //if list[middle] is smaller than searchnum, return -1. if list[middle] is bigger than searchnum, return 1. else return 0
			case -1: return
				binsearch(list, searchnum, middle+1, right); 
			case 0: return middle;
			case 1: return
				binsearch(list, searchnum, left, middle-1);
		}
	}
	return -1; //if searchnum is not exist at list, return -1;
}

int compare(int x,int y){
	if(x<y)
		return -1;
	else if(x==y)
		return 0;
	else 
		return 1;
}

