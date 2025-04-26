#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 100

bool ispalindrome(char s[]){
	int r = strlen(s)-1;
	int i=0;
	while(i<r){
		if(s[i] != s[r]){
			return false;
		}
		i++;
		r--;
	}
	return true;
}

int main(){

	int n;
	char s[max][20];

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	//printf("%ld\n",strlen(s[0]));

	for(int i=0;i<n;i++){
		bool j = ispalindrome(s[i]);
		if(j==true){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}


	return 0;
}
