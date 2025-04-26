#include<stdio.h>
#include<stdlib.h>
#define max 100

void print(int a[max][max],int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

}

void transpose(int a[max][max],int *m,int *n){
	int temp[max][max];
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			temp[j][i] = a[i][j];
		}
	}
	for(int i=0;i<*n;i++){
		for(int j=0;j<*m;j++){
			a[i][j] = temp[i][j];
		}
	}
	int tempsize = *m;
	*m = *n;
	*n = tempsize;

}

int main(){

	int m,n, a[max][max];
	scanf("%d",&m);
	scanf("%d",&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	print(a,m,n);
	printf("Transpose of matrix is:\n");
	transpose(a,&m,&n);

	print(a,m,n);

	return 0;
}
