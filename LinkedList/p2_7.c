/*
7. Take N numbers as input from the user and create a doubly linked list.
8. Find the smallest number in the doubly linked list.
9. Delete the smallest number in the doubly linked list.
10. Reverse a doubly linked list.
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int num;
    struct node* prev;
    struct node* next;
};
void display(struct node* head){
    struct node* temp = NULL;
    for(temp = head;temp!=NULL;temp=temp->next){
        printf("%d -> ",temp->num);
    }
    printf("NULL\n");
}

struct node* append(struct node* head, int x){
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = x;
    new_node->prev = NULL;
    new_node->next = NULL;

    if(head == NULL){
        return new_node;
    }
    struct node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new_node->prev = temp;
    temp->next = new_node;
    return head;
}

void rev_display(struct node* head){
    struct node* temp = NULL;
    for(temp = head;temp->next!=NULL;temp=temp->next){
        head = temp->next;
    }
    for(temp = head;temp!=NULL;temp=temp->prev){
        printf("%d -> ",temp->num);
    }
    printf("NULL\n");
}
int smallest(struct node* head){
    int min = head->num;
    struct node* temp = NULL;
    for(temp = head;temp!=NULL;temp= temp->next){
        if(min > temp->num){
            min = temp->num;
        }
    }
    return min;
}
struct node* del_smallest(struct node* head,int min){
    //int min = head->num;
    struct node* temp = NULL;
    /*for(temp = head;temp!=NULL;temp= temp->next){
        if(min > temp->num){
            min = temp->num;
        }
    }*/
    for(temp=head;temp!= NULL;temp = temp->next){
        if(min == temp->num){
            if(temp->prev==NULL){
                head = temp->next;
                return head;
            }
            else if(temp->next == NULL){
                temp->prev->next = NULL;
                return head;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                return head;
            }
        }
    }
    //return head;
}

int main(){
    struct node* head = NULL;
    int n,x;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head = append(head,x);
    }
    display(head);
    //rev_display(head);
    int min = smallest(head);
    printf("Smallest: %d\n",smallest(head));
    head = del_smallest(head,min);
    display(head);
    
    return 0;
}