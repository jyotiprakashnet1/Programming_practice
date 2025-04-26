#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int num;
    struct node* next;
};
// For traversal of circular linked list
void display(struct node* head){
	struct node* temp = NULL;
	for(temp=head;temp->next!=head;temp=temp->next){
		printf("%d -> ",temp->num);
	}
	printf("%d\n",temp->num);
}
// For insertion at last in circular linked list
struct node* append(struct node* head, int x){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = x;
	new_node->next = NULL;

	if(head==NULL){
        new_node->next = new_node;
		return new_node;
	}
	struct node* temp = NULL;
	for(temp = head;temp->next!=head;temp=temp->next){}
    new_node->next = head;
	temp->next = new_node;
	return head;
}

// print sum of all even in circular linked list
int print_even_sum(struct node* head){
    struct node* temp = NULL;
    int sum=0;
    for(temp = head; temp->next!=head; temp=temp->next){
        if((temp->num)%2==0){
            sum +=temp->num;
        }
    }
    if((temp->num)%2==0){
            sum +=temp->num;
    }
    return sum;
}

// print odd sum
int print_odd_sum(struct node* head){
    struct node* temp = NULL;
    int sum=0;
    for(temp = head; temp->next!=head; temp=temp->next){
        if((temp->num)%2!=0){
            sum +=temp->num;
        }
    }
    if((temp->num)%2!=0){
            sum +=temp->num;
    }
    return sum;
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
    int esum = print_even_sum(head);
    int osum = print_odd_sum(head);
    printf("Even sum: %d\n",esum);
    printf("odd sum: %d\n",osum);
    return 0;
}