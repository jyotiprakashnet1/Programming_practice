#include<stdio.h>
#include<stdlib.h>

struct node{
	int num;
	struct node* left;
	struct node* right;
};
struct node* create(int k){
	struct node* new_node = (struct node*) malloc (sizeof(struct node));
	new_node->num = k;
	new_node->left = NULL;
	new_node->right = NULL;
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

void preorder(struct node* root){
	if(root == NULL){
		return;
	}
	printf("%d_",root->num);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d_",root->num);
	inorder(root->right);
}
void postorder(struct node* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d_",root->num);
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

int max(struct node* root){
	int max = 0;
	if(root==NULL){
		return 0;
	}
	while(root->right != NULL){
		root = root->right;
	}
	return root->num;
}
int min(struct node* root){
	if(root == NULL){
		return 0;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root->num;
	
}

struct node* get_successor(struct node* root){
	struct node* temp = root;
	temp = root->right;
	while(temp != NULL && temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

struct node* delnode(struct node* root, int k){

	//base case
	if(root == NULL){
		return root;
	}
	//find the key in subtree
	if(root->num > k){
		root->left = delnode(root->left,k);
	}
	else if (root->num < k)
	{
		root->right = delnode(root->right,k);
	}
	else{
		//if root matches the with the key
		//cases when root having 0 children
		//only right child
		if(root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		// only left child
		if(root->right == NULL){
			struct node* temp = root->left;
			free(root);
			return temp;
		}
		//when both children are present
		struct node* succ = get_successor(root);
		root->num = succ->num;
		root->right = delnode(root->right,k);
	}
	return root;
	
}

int main(){
	int n,k;
	scanf("%d",&n);
	struct node* root = NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		root = insert(root,k);

	}

	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	int count = leaf(root);
	printf("leaf: %d\n",count);
	printf("Max: %d\n",max(root));
	printf("Min: %d\n",min(root));
	printf("Successor is: %d\n",get_successor(root)->num);

	root = delnode(root,1);
	inorder(root);
	printf("\n");
	
	



	return 0;
}

