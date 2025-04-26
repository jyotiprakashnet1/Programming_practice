#include<stdio.h>
#include<stdlib.h>
#define max 100

int main(){

	int n, a[max][max];
	scanf("%d",&n);
	int sum_row[n],sum_column[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(int i=0;i<n;i++){
		sum_row[i]=0;
		sum_column[i]=0;
		for(int j=0;j<n;j++){
			sum_row[i]+= a[i][j];
			sum_column[i] += a[j][i];
		}

		//printf("Sum of %d row: %d\n",i,sum_row[i]);
		//printf("sum of %d col: %d\n",i,sum_column[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sum_row[i] == sum_column[j]){
				printf("Row: %d\nColumn: %d\n",i+1,j+1);
				return 0;
			}
		}
	}

	return 0;
}
