#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* append(struct node *head, int num){

	struct node* new_node = NULL;
	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;

	if(head == NULL){
		return new_node;
	}
	struct node *temp = NULL;

	for(temp = head; temp->next != NULL; temp = temp ->next){}

	temp -> next = new_node;
	return head;
}

void print_list(struct node* head){
	struct node* temp = NULL;


	if(head == NULL){
		printf("List is empty");
		return;
	}

	for(temp = head; temp != NULL; temp = temp->next){
		printf("%d ",temp->data);
	}
	printf("\n");
}



int main(){

	struct node* head = NULL;
	int n, num,k;

	scanf("%d",&n);
	scanf("%d",&k);
	for( int i =0 ; i<n; i++){
		scanf("%d",&num);
		head = append(head, num);
	}
	struct node* temp = NULL;
	struct node* first = NULL;

	int c=0;
	for(temp = head;c != 2 || temp != NULL; temp = temp->next){
		if(temp->data == k){
			c+=1;
		}
	}
	for(first = head; first -> next -> data !=k; first= first->next){
	}
	first->next = temp->next;

	//printf("%d\n",c);
	
	
	print_list(head);
	return 0;
}
