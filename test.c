#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	char name[20][10],temp[10];
	int n;
	printf("Enter the number of name:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",name[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(strcmp(name[i],name[j])>0){
				strcpy(temp,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp);
			}
		}
	}

	for(int i=0;i<n;i++){
		printf("%s ",name[i]);
		}
	printf("\n");


	return 0;
}
