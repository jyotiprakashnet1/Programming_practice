#include<stdio.h>
#include<stdlib.h>

struct node{
	int n;
	struct node* next;
};

   void display(struct node* head) {
       if (head == NULL) {
           printf("List is empty\n");
           return;
       }
       struct node* temp = head;
       do {
           printf("%d ", temp->n);
           temp = temp->next;
       } while (temp != head);
       printf("\n");
   }


struct node* append(struct node* head, int x){
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->n = x;
	new_node->next = NULL;
	if(head==NULL){
		new_node->next = new_node;
		return new_node;
	}
	else{
	struct node* temp;
	for(temp=head;temp->next!=head;temp=temp->next){}
	new_node->next = temp->next;
	temp->next = new_node;
	return head;}
}

int main(){
	struct node* head = NULL;
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		head = append(head,x);
	}
	display(head);
//	head = append(head,10);
//	display(head);
}
