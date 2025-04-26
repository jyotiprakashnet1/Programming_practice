#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node* prev;
	struct node* next;
};

struct node* append(struct node* head, int x){
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->num = x;
	new_node->prev = NULL;
	new_node->next = NULL;

	struct node* temp;
	if(head == NULL){
		return new_node;
	}
	else{
		for(temp=head;temp->next!=NULL;temp=temp->next){}
		temp->next = new_node;
		new_node->prev = temp;
		return head;
	}
}

struct node* at_begin(struct node* head, int x){
	struct node* new_node = NULL;
        new_node = (struct node*)malloc(sizeof(struct node));

        new_node->num = x;
        new_node->prev = NULL;
        new_node->next = NULL;
	
	if(head == NULL){
		return new_node;
	}
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	return head;
}

void printlist(struct node* head){
	struct node* temp;
	for(temp = head; temp != NULL; temp= temp->next){
		printf("%d ",temp->num);
	}
	//printf("%p",head);
	printf("\n");
}

int main(){
	int n,x;
	struct node* head=NULL;
	printf("Number of nodes wnat to enter at end:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		head = append(head,x);
	}
	printf("After %d insertion at last in list is:\n",n);
	printlist(head);
	printf("Enter the no. of node want to insert at begining:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		head = at_begin(head,x);
	}
	printf("After %d insertion at begining the list is:\n",n);
	printlist(head);



	return 0;
}

