#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

bool ispresent(int a[], int size, int value){
	for(int i=0;i<size;i++){
		if(a[i] == value){
			return true;
		}
	}
	return false;
}

void unique_row(int a[max][max],int n){
	for(int i=0;i<n;i++){
		int uniquerow[max];
		int uniquecount=0;
		for(int j=0;j<n;j++){
			if(!ispresent(uniquerow, uniquecount, a[i][j])){
				uniquerow[uniquecount++] = a[i][j];
			}
		}
		for(int j=0;j<uniquecount;j++){
			printf("%d ",uniquerow[j]);
		}
		printf("\n");
	}
}
void unique_column(int a[max][max],int n){

	for(int j=0;j<n;j++){
		int uniquecolumn[max];
		int uniquecount = 0;
		for(int i=0;i<n;i++){
			if(!ispresent(uniquecolumn, uniquecount, a[i][j])){
				uniquecolumn[uniquecount++] = a[i][j];
			}
		}
		for(int i=0;i<uniquecount;i++){
			printf("%d ",uniquecolumn[i]);
		}
		printf("\n");
	}
}

int main(){

	int n, a[max][max];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Along row:\n");

	unique_row(a,n);

	printf("Along column:\n");
	unique_column(a,n);


	return 0;
}
