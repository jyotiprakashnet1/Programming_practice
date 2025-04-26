#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node{
        int data;
        struct node* next;
};

struct node* append(struct node* head, int num){
        struct node* temp = NULL;
        struct node* new_node = NULL;

        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        new_node -> next = NULL;
        if(head == NULL){
                return new_node;
        }
        for(temp = head; temp->next!=NULL; temp = temp->next){
        }
        temp->next = new_node;
        return head;
}

struct node* append(struct node* head, int num){
	struct node* temp = NULL;
	struct node* new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = NULL;
	if(head == NULL){
		return new_node;
	}
	for(temp = head; temp->next!=NULL; temp = temp->next){
	}
	temp->next = new_node;
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

struct node* reverselist(struct node* head){
	struct node *prev, *current, *next;

	prev = NULL;
	current = head;
	while(current != NULL){
		next = current -> next;

		current ->next = prev;

		prev = current;
		current = next;
	}
	return prev;
}




int main(){

	struct node* head = NULL;
        int n, num;

        scanf("%d",&n);
        for( int i =0 ; i<n; i++){
                scanf("%d",&num);
                head = append(head, num);
        }

	print_list(head);

	head = reverselist(head);
	print_list(head);
	
	return 0;
}
