#include <stdio.h>
/*char *strcpy(char *dest, char *src){
	
	char *start=dest;
	
	while(*src!='\0'){
		*dest=*src;
		dest++;
		src++;
	}
	*dest = '\0';
	return start;
}
*/

/*int strlen(char *src){
	int count=0;
	
	while(*src!='\0'){
		count++;
		src++;
	}	
	
	return count;
}
*/

/*int strcmp(char *dest, char *src){
	
	while(*dest!='\0' && *src!='\0'){
		if(*dest>*src)
			return 1;
		else if(*dest<*src)
			return -1;
		else{
			dest++;
			src++;
		}
	}	
	return 0;
}
*/

int main(){
	char dest[10]="banana";
	char src[10]="banana";
	
	//strcpy(dest,src);
	//int c=strlen(src);
	strcmp(dest,src);
	
	//printf("%s",dest);
	//printf("%d",c);
	if(strcmp(dest,src)==0)
		printf("문자열이 같다");
	else
		printf("문자열이 같지 않다.");
	
	
	return 0;
}


