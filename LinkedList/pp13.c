#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node* next;
};

struct node* append(struct node* head,int k){
    struct node* new_node=NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = k;
    new_node->next = NULL;
    if(head==NULL){
        return new_node;
    }
    struct node* temp = NULL;
    for(temp=head;temp->next!=NULL;temp=temp->next){}
    temp->next = new_node;
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    for(temp = head;temp!=NULL;temp=temp->next){
        printf("%d -> ",temp->num);
    }
    printf("NULL\n");
}

void unique(struct node* head){
    struct node* current = NULL;
    struct node* temp = NULL;
    struct node* prev = NULL;
    for(current=head;current!=NULL;current=current->next){
        prev = current;
        temp = current->next;
        while(temp!=NULL){
            if(temp->num==current->num){
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            prev = temp;
            temp=temp->next;
        }
    }
}

int main(){
    int k;
    struct node* head=NULL;
    struct node* head1 = NULL;
    for(int i=0;i<10;i++){
        scanf("%d",&k);
        head=append(head,k);
    }
    display(head);
    unique(head);
    display(head);
    return 0;
}