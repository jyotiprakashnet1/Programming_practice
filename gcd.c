#include<stdio.h>

int gcd(int a, int b){
	int q =0,r;
	if(a==0){
		return b;
	}
	else if(b==0){
		return a;
	}
	else{
		while(b>0){
			q = a/b;
			r = a - b * q;
			a=b;
			b=r;
		}
		return a;
	}
}

int main(){

	printf("Enter the number to find gcd:\n");
	int a,b;

	scanf("%d",&a);
	scanf("%d",&b);

	int n = gcd(a,b);

	printf("%d is gcd of %d and %d.\n",n,a,b);

	return 0;
}
