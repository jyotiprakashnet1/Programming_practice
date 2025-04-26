#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node* next;
};
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

void display(struct node* head){
        struct node* temp = NULL;
        for(temp=head;temp!=NULL;temp=temp->next){
                printf("%d -> ",temp->num);
        }
        printf("NULL\n");
}

struct node* reverse_k_group(struct node* head,int k){

        if(head==NULL){
                return NULL;
        }
        struct node* next = NULL;
        struct node* curr = head;
        struct node* prev = NULL;
        int count = 0;
        while(curr!=NULL && count<k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
        }

        if(next!=NULL){
                head->next = reverse_k_group(next,k);
        }

        return prev;
}


int main(){
	int k,n;
	scanf("%d",&k);
	struct node* head = NULL;
	for(int i=0;i<10;i++){
		scanf("%d",&n);
		head = append(head,n);
	}

	display(head);
        head = reverse_k_group(head,k);

        display(head);
	return 0;
}
