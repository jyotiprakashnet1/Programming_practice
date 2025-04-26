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

int maximum(struct node* head){
	int max=0;
	for(struct node* temp = head; temp!=NULL;temp=temp->next){
		if(temp->num>max){
			max = temp->num;
		}
	}
	return max;
}
int minimum(struct node* head){
	int min = head->num;
	for(struct node* temp = head; temp!=NULL;temp=temp->next){
		if(temp->num<min){
			min = temp->num;
		}
	}
	return min;
}
int main(){
    struct node* head = NULL;
    int n,x;
    printf("Enter the no.of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head = append(head,x);
    }
    display(head);
	int max = maximum(head);
	printf("Max: %d\n",max);
	int min = minimum(head);
	printf("Min: %d\n",min);
	printf("max-min= %d\n",max-min);
    return 0;
}