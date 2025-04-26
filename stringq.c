#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	char str[100];

	printf("Enter the string:\n");
	scanf("%s",str);
	int s = strlen(str);

	printf("%s,length:%d\n", str,s);

	return 0;
}
