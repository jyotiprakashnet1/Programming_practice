#include<stdio.h>
#include<stdlib.h>

struct DyArray{
	int *arr;
	int size;
	int capacity;
};

void initarray(struct DyArray *da, int initialCapacity){

	da->capacity = initialCapacity;
	
	da->arr = (int*)malloc((da->capacity)*sizeof(int));
	da->size = 0;
}

void resizeArray(struct DyArray *da){

	da->capacity *=2;
	da->arr = (int*)realloc(da->arr, (da->capacity)*sizeof(int));

}

void insert(struct DyArray *da, int num){

	if(da->capacity == da->size){
		resizeArray(da);
	}
	da->arr[da->size] = num;
	(da->size)++;
}

void DisplayArray(struct DyArray *da){

	printf("Capacity: %d, Size: %d, elements: ",da->capacity, da->size);
	for(int i=0;i<(da->size);i++){
		printf("%d ",da->arr[i]);
	}
	printf("\n");
}

int main(){

	struct DyArray da;
	
	int n,num;

	initarray(&da,1);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		insert(&da,num);
		DisplayArray(&da);
	}

	//DisplayArray(&da);

	return 0;
}
