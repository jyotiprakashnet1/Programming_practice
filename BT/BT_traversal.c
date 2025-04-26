#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node* left;
	struct node* right;
};

void inorder(struct node* root){
	if(root == NULL){
		return;
	}
	struct node* temp = root;
	inorder(root->left);
	printf("%d ",root->num);
	inorder(root->right);
}
void preorder(struct node* root){
        if(root == NULL){
                return;
        }
        struct node* temp = root;
	printf("%d ",root->num);
        preorder(root->left);
        preorder(root->right);
}

void postorder(struct node* root){
        if(root == NULL){
                return;
        }
        struct node* temp = root;
        postorder(root->left);
        postorder(root->right);
	printf("%d ",root->num);
}

int leaf(struct node* root){
        if(root == NULL){
                return 0;
        }
        int count =0;
        if(root->left == NULL && root->right == NULL){
                return 1;
        }
        return leaf(root->left)+leaf(root->right);
}


struct node* insert(struct node* root, int key){
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = key;
	new_node->left = NULL;
	new_node->right = NULL;

	if(root == NULL){
		return new_node;
	}
	struct node* temp = root;
	while(1){
		if(key < temp->num){
			if(temp->left == NULL){
				temp->left = new_node;
				break;
			}
			else{
				temp = temp->left;
			}
		}
		else{
			if(temp->right == NULL){
				temp->right = new_node;
				break;
			}
			else{
				temp = temp->right;
			}
		}
	}

	return root;
}


int main(){

	struct node* root = NULL;
	int n,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		root = insert(root,k);
	}//root = insert(root,5);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	int count = leaf(root);
	printf("%d\n",count);

	return 0;
}



