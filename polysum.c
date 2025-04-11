#include <stdio.h>
#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0 : 1)
#define MAX_TERMS 101
#define MAX_POLYS 15

typedef struct
{
    int expon;
    float coef;
} polinomial;

int avail=0;
polinomial terms[MAX_TERMS];

void attach(float coefficient, int exponent){
    if(avail>=MAX_TERMS){
        fprintf(stderr, "다항식에 항이 너무 많습니다.");
        exit(1);
    } 
    terms[avail].coef=coefficient;
    terms[avail++].expon=exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int  *startD, int *finishD){
    float coefficient;
    *startD = avail;

    while(startA <= finishA && startB <= finishB)
        switch (COMPARE(terms[startA].expon,terms[startB].expon))
        {
        case -1:
            attach(terms[startB].coef, terms[startB].expon);
            startB++;
            break;
        case 0: 
            coefficient=terms[startA].coef+terms[startB].coef;
            if(coefficient)
                attach(coefficient, terms[startA].expon);
            startA++;
            startB++;
            break;
        case 1: 
            attach(terms[startA].coef, terms[startA].expon);
            startA++;
        }

        for(; startA<=finishA; startA++)
            attach(terms[startA].coef, terms[startA].expon);
        for(; startB<=finishB; startB);
            attach(terms[startB].coef, terms[startB].expon);
        *finishD=avail-1;
}

int main(){
    
    return 0;
}