#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node* next;
};

void display(struct node* head){
	struct node* temp = NULL;
	for(temp=head;temp!=NULL;temp=temp->next){
		printf("%d -> ",temp->num);
	}
	printf("NULL\n");
}
struct node* append(struct node* head, int x){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = x;
	new_node->next = NULL;

	if(head==NULL){
		return new_node;
	}
	struct node* temp = NULL;
	for(temp = head;temp->next!=NULL;temp=temp->next){}
	temp->next = new_node;
	return head;
}
struct node* del_greater(struct node* head){

	struct node* prev = NULL;
	struct node* current = head;
	while(current && current->next){
		if(current->next->num > current->num){
			struct node* temp = current;
			if(prev == NULL){
				head = current->next;
			}
			else{
				prev->next = current->next;
			}
			current = current->next;
			free(temp);
		}
		else{
			prev = current;
			current= current->next;
		}
	}
	return head;
}
int main(){
	int n,x;
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	for(int i=0;i<8;i++){
		scanf("%d",&x);
		head1 = append(head1,x);
	}
	for(int i=0;i<8;i++){
		scanf("%d",&x);
		head2 = append(head2,x);
	}
	for(int i=0;i<8;i++){
		scanf("%d",&x);
		head3 = append(head3,x);
	}

	display(head1);
	head1 = del_greater(head1);
	display(head1);
	display(head2);
	head2 = del_greater(head2);
	display(head2);
	display(head3);
	head3 = del_greater(head3);
	display(head3);

	return 0;
}
