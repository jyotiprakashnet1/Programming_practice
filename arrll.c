#include<stdio.h>
#define N 10

void printarr(long long A[10]){
	int n = 10;
	for(int i=0;i<n;i++){
		printf("%lld\t",A[i]);
	}
	printf("\n");
}

long long delete(long long A[10], int pos){
	long long temp, *arr;
	for(int i=0; i<pos;i++){
                if(i==4){
                        arr= A+4;
                        temp = A[4];
                        for(int j=4;j<N-1;j++){
                                *(A+j)=*(A+j+1);
                        }
                }
        }
	return temp;
}

void insertion(long long A[10], long long val){
	
	*(A+9) = val;
}


int main(){

	long long A[N];
	long long k=0;
	for(int i = 0; i<N; i++){
		scanf("%lld",&A[i]);
	}

	//printf("1st ptr: %p 2nd ptr: %p", A, A+1);

	//delete the element from index 4 and insert into last
	
	for(int i=0;i<10;i++){
	k = delete(A,5);
	insertion(A,k);
	
	printf("Result after performing the deletion from index 4 and insertion at the last: %d time\n",i+1);
	printarr(A);
	}
	return 0;
}

