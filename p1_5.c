#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

void string_order(char s[max][30],int n){
	char temp[30];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(strcmp(s[i],s[j])>0){
				strcpy(temp,s[i]);
				strcpy(s[i],s[j]);
				strcpy(s[j],temp);
			}
		}
	}
}


int main(){
	int n;
	char name[max][30];

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",name[i]);
	}

	string_order(name,n);

	for(int i=0;i<n;i++){
		printf("%s ",name[i]);
	}
	printf("\n");



	return 0;
}
