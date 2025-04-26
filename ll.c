#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void print_list(struct node *head);
// for the inserting option

struct node* at_begining(struct node *head, int num);
struct node* at_k_position(struct node *head, int k, int num);
struct node* at_tail(struct node *head, int num);

int main(){
	struct node *head=NULL;
	
	printf("Before any operation:\n");	
	print_list(head);

	printf("After 1 insertion at beg:\n");
	head = at_begining(head, 5);	
	print_list(head);

	head = at_tail(head, 9);
	head = at_tail(head,10);
	head = at_tail(head,11);
	printf("After 1 insertion at beg and 3 at tail:\n"); 
	print_list(head);

	at_k_position(head,3,40);
	printf("After insertion at 3rd pos:\n");
	print_list(head);

	head = at_begining(head,25);
	printf("inserted 25 at begining:\n");
	print_list(head);	

	return 0;
}

void print_list(struct node* head){

	struct node *temp = NULL;
	// if list is empty
	
	if(head == NULL){
		printf("(empty)\n");
		return;
	}

	/* store the head address to temp for loop initialization */

	for(temp = head; temp != NULL; temp = temp -> next){
		printf("%d\t",temp->data);
	}
	printf("\n");
	return;
}

// definition of insertion at begining
struct node* at_begining(struct node *head, int num){
	struct node *temp = NULL;
	struct node *new_node = NULL;

	new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;
	if(head == NULL){

		return new_node;
	}
	else{
		temp = head;
		new_node -> next = temp;
		head = new_node;
	}
}


struct node* at_tail(struct node* head, int num)
{
	struct node *tail = NULL;
	struct node *new_node = NULL;

	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = num;
	new_node->next = NULL;

	/* new_node is head if the linked list is empty */
	if (head == NULL) {
		return new_node;
	}

	/* go to the last node (tail) */
	for (tail = head; tail->next != NULL; tail = tail->next) {
	}

	/* append the new node */
	tail->next = new_node;

	return head;
}


struct node* at_k_position(struct node* head, int k, int num)
{
	struct node *temp = NULL;
	struct node *new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = num;
	new_node->next = NULL;

	temp = head;

	for(int i=1;i<k-1;i++){
		temp = temp->next;
	}
	new_node->next = temp->next;
	temp->next = new_node;
	return head;
}

