#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *dfrom_beg(struct node *head)
{
	struct node *temp = NULL;

	if(head == NULL){
		printf("Deletion not possible since list is empty.\n");
		return NULL;
	}

	temp = head ->next;
	head = temp;
	return head;
}

void print_list(struct node* head){
	
	struct node* temp = NULL;

	if(head == NULL){
		printf("(empty)\n");
	}
	else{
		for(temp=head; temp!=NULL; temp=temp->next){
			printf("%d\t",temp->data);
		}
		printf("\n");
	}
}

struct node* append(struct node *head, int num){

	struct node* temp = NULL;
	struct node* new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;

	if(head == NULL)
	{
		return new_node;
	}
	for(temp = head; temp->next != NULL; temp = temp->next){}
	temp->next = new_node;
	return head;

}


int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;
	struct node *new_node = NULL;
	int n =0,num=0;
	printf("How many num want to enter:\n");
	scanf("%d",&n);

	for(int i=0; i<n; i++){

		scanf("%d",&num);
		head = append(head, num);
	}
	printf("After appending %d element:\n",n);
	print_list(head);
		
	
	head = dfrom_beg(head);
	printf("After deletion from beg:\n");
	print_list(head);

	return 0;
}

