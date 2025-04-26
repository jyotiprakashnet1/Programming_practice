#include<stdio.h>


int main(){
	
	int n;
	scanf("%d",&n);
	int a[n][n];

	for(int i =0 ;i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(int i=0; i<n; i++){
		int dig = a[i][i];
		int sum = 0;

		if(i>0){
			sum+= a[i-1][i] + a[i][i-1];
		}

		if(i<n-1){
			sum+= a[i+1][i] + a[i][i+1];
		}

		if(dig != sum){
			printf("no\n");
			return 0;
		}
	}

	printf("yes\n");

	return 0;
}
