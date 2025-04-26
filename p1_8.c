#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

bool dia_sumof_neig(int a[max][max],int n){
	int x[] = {-1,0,1,0};
	int y[] = {0,-1,0,1};
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<4;j++){
			int ni= i+x[j];
			int nj= i+y[j];

			if(ni>=0 && ni<n && nj>=0 && nj<n){
				sum += a[ni][nj];
			}
		}
		if(a[i][i]!= sum){
			return false;
		}
	}
	return true;
}
int main(){
	int x[] = {-1,0,1,-1,1,-1,0,1};
	int y[] = {-1,-1,-1,0,0,1,1,1};

	int n;
	int a[max][max];

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}

	bool i = dia_sumof_neig(a,n);
	if(i==true){
		printf("yes\n");
	}
	else{
	printf("no\n");}

	return 0;
}
