#include<stdio.h>
#include<stdlib.h>

void isort (int A[], int n){
	int i=0,j, key;

	for(j=1; j<n; j++){
		key = A[j];

		i = j-1;
		while( i >= 0 && A[i]>key){
			A[i+1] = A[i];

			i--;
		}
		A[i+1] = key;
	}
}




int main(int argc, char *argv[]){
	int arr[10]= {999,7,5,4,1,2,0,6,3,8};
	
        isort(arr,10);
	for(int i=0;i<10;i++){
		printf("%d ", arr[i]);

	}
	printf("\n");




	return 0;
}
