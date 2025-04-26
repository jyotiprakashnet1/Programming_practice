#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node* next;
    struct node* friend;
};

struct node* insert(struct node* head, int num){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;
    new_node->friend = NULL;
    new_node->next = NULL;

    if(head == NULL){
        return new_node;
    }

    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp ->next;
    }
    temp->next = new_node;

    return head;

}

void printlist(struct node* head){
    struct node* temp = NULL;

    for(temp = head;temp->next != NULL; temp = temp->next){
        printf("%d->",temp->num);
    }
    printf("%d\n",temp->num);
}

struct node* create(int num){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->num = num;
    new_node->next = NULL;
    new_node->friend = NULL;
    return new_node;
}

int main(){
    int n,key,findex;
    scanf("%d",&n);
    struct node* arr[n];
    int index[n];
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        arr[i] = create(key);
        scanf("%d",&index[i]);
        if(index[i]-1 <0 || index[i]-1 >n){
            printf("Invalid value\n");
            return 1;
        }
    }

    for(int i=0;i<n-1;i++){
        // printf("%d ",index[i]);
        arr[i]->next = arr[i+1];
    }
    for(int i=0;i<n;i++){
        arr[i]->friend = arr[index[i]-1];
        //printf("%d_",arr[i]->friend->num);
    }
    for(int i=0;i<n-1;i++){
        //arr[i]->friend = arr[index[i]-1];
        printf("%d_",arr[i]->friend->num);
    }
    printf("%d\n",arr[n-1]->friend->num);
    //printlist(arr[0]);
    return 0;
}
