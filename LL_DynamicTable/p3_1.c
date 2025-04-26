#include<stdio.h>
#include<stdlib.h>
struct DArray{
	int *arr;
	int size;
	int capacity;
};
void init_darray(struct DArray* da,int cap){
	da->capacity = cap;
	da->arr = (int*)malloc((da->capacity)*sizeof(int));
	da->size = 0;
}
void insert(struct DArray* da, int n){
	if(da->size == da->capacity){
		da->capacity *=2;
		da->arr = (int*)realloc(da->arr, (da->capacity)*sizeof(int));
	}
	da->arr[(da->size)++]=n;
}

void display(struct DArray* da){
	printf("capacity= %d; size= %d; elements = ",da->capacity,da->size);
	for(int i=0;i<da->size;i++){
		printf("%d ",da->arr[i]);
	}
	printf("\n");
}

int main(){
	struct DArray da;
	init_darray(&da,1);
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		insert(&da,x);
		display(&da);
	}

	
	return 0;
}
