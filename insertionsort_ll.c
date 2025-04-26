#include<stdio.h>
#include<stdlib.h>
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

struct node *sortedInsert(struct node* new_node, struct node* sorted){

        if(sorted == NULL || sorted->data >= new_node->data){
                new_node->next = sorted;
                sorted = new_node;
        }
        else{
                struct node* temp = sorted;

                while(temp != NULL && temp->next->data < new_node->data){
                        temp = temp->next;
                }
                new_node->next = temp->next;
                temp->next = new_node;
        }
        return sorted;
}


struct node* insertionsort(struct node *head){
	struct node *sorted = NULL;
	struct node* current = head;

	while(current != NULL){
		struct node* next = current->next;

		sorted = sortedInsert(current, sorted);
		current = next;
	}

	return sorted;
}




int main(){

	struct node* head = NULL;
	int num,k;
	printf("Enter the no. of elements:\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d", &k);
		head = append(head, k);
	}

	print_list(head);
	//head = insertionsort(head);
	//print_list(head);


	return 0;
}
