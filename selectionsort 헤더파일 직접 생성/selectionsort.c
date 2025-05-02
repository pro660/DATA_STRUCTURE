#include <stdio.h>
#include "selectionSort.h"

void sort(int list[],int n){
    int i,j,min,temp;

    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(list[j]<list[min])
                min=j;
        }
        temp=list[i];
        list[i]=list[min];
        list[min]=temp;
    }
}