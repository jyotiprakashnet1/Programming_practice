#include <stdio.h>
#include <stdlib.h>

// A B-tree node
struct BTreeNode {
    int *keys;             // key values within the node
    int t;                 // Minimum degree (defines the range for the number of keys)
    struct BTreeNode **C;  // An array of child pointers
    int n;                 // Current number of keys
    int leaf;              // Boolean: Is true when the node is a leaf, else false
};

// Function to create a new B-tree node
struct BTreeNode *createNode(int t, int leaf) {
    struct BTreeNode *node = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    node->t = t;
    node->leaf = leaf;

    node->keys = (int *)malloc((2 * t - 1) * sizeof(int));
    node->C = (struct BTreeNode **)malloc((2 * t) * sizeof(struct BTreeNode *));
    node->n = 0;

    return node;
}

// Function to traverse the B-tree
void traverse(struct BTreeNode *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf) {
                traverse(root->C[i]);
            }
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf) {
            traverse(root->C[i]);
        }
    }
}

// Function to search a key in the B-tree
struct BTreeNode *search(struct BTreeNode *root, int key) {
    int i = 0;

    while (i < root->n && key > root->keys[i]) {
        i++;
    }

    if (i < root->n && root->keys[i] == key) {
        return root;
    }

    if (root->leaf) {
        return NULL;
    }

    return search(root->C[i], key);
}

// A utility function to split the child y of this node
void splitChild(struct BTreeNode *x, int i, struct BTreeNode *y) {
    int t = y->t;
    struct BTreeNode *z = createNode(t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }

    if (!y->leaf) {
        for (int j = 0; j < t; j++) {
            z->C[j] = y->C[j + t];
        }
    }

    y->n = t - 1;

    for (int j = x->n; j >= i + 1; j--) {
        x->C[j + 1] = x->C[j];
    }

    x->C[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }
    x->keys[i] = y->keys[t - 1];
    x->n++;
}

// A utility function to insert a key in a non-full node
void insertNonFull(struct BTreeNode *x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }

        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k) {
            i--;
        }
        i++;

        if (x->C[i]->n == 2 * x->t - 1) {
            splitChild(x, i, x->C[i]);

            if (x->keys[i] < k) {
                i++;
            }
        }
        insertNonFull(x->C[i], k);
    }
}

// Function to insert a key into the B-tree
struct BTreeNode *insert(struct BTreeNode *root, int k, int t) {
    if (root == NULL) {
        root = createNode(t, 1);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            struct BTreeNode *s = createNode(t, 0);
            s->C[0] = root;

            splitChild(s, 0, root);

            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            insertNonFull(s->C[i], k);

            root = s;
        } else {
            insertNonFull(root, k);
        }
    }
    return root;
}

// A utility function to get the predecessor of a key
int getPredecessor(struct BTreeNode *node, int idx) {
    struct BTreeNode *cur = node->C[idx];
    while (!cur->leaf) {
        cur = cur->C[cur->n];
    }
    return cur->keys[cur->n - 1];
}

// A utility function to get the successor of a key
int getSuccessor(struct BTreeNode *node, int idx) {
    struct BTreeNode *cur = node->C[idx + 1];
    while (!cur->leaf) {
        cur = cur->C[0];
    }
    return cur->keys[0];
}

// A utility function to merge two children of a node
void merge(struct BTreeNode *node, int idx) {
    struct BTreeNode *child = node->C[idx];
    struct BTreeNode *sibling = node->C[idx + 1];

    int t = child->t;
    child->keys[t - 1] = node->keys[idx];

    for (int i = 0; i < sibling->n; i++) {
        child->keys[i + t] = sibling->keys[i];
    }

    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++) {
            child->C[i + t] = sibling->C[i];
        }
    }

    for (int i = idx + 1; i < node->n; i++) {
        node->keys[i - 1] = node->keys[i];
    }

    for (int i = idx + 2; i <= node->n; i++) {
        node->C[i - 1] = node->C[i];
    }

    child->n += sibling->n + 1;
    node->n--;

    free(sibling);
}

// Function to delete a key from the subtree rooted with this node
void deleteKey(struct BTreeNode *node, int k) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < k) {
        idx++;
    }

    if (idx < node->n && node->keys[idx] == k) {
        if (node->leaf) {
            for (int i = idx + 1; i < node->n; i++) {
                node->keys[i - 1] = node->keys[i];
            }
            node->n--;
        } else if (node->C[idx]->n >= node->t) {
            int pred = getPredecessor(node, idx);
            node->keys[idx] = pred;
            deleteKey(node->C[idx], pred);
        } else if (node->C[idx + 1]->n >= node->t) {
            int succ = getSuccessor(node, idx);
            node->keys[idx] = succ;
            deleteKey(node->C[idx + 1], succ);
        } else {
            merge(node, idx);
            deleteKey(node->C[idx], k);
        }
    } else if (!node->leaf) {
        int flag = (idx == node->n);
        if (node->C[idx]->n < node->t) {
            if (idx != 0 && node->C[idx - 1]->n >= node->t) {
                struct BTreeNode *child = node->C[idx];
                struct BTreeNode *sibling = node->C[idx - 1];

                for (int i = child->n - 1; i >= 0; i--) {
                    child->keys[i + 1] = child->keys[i];
                }

                if (!child->leaf) {
                    for (int i = child->n; i >= 0; i--) {
                        child->C[i + 1] = child->C[i];
                    }
                }

                child->keys[0] = node->keys[idx - 1];
                if (!child->leaf) {
                    child->C[0] = sibling->C[sibling->n];
                }

                node->keys[idx - 1] = sibling->keys[sibling->n - 1];

                child->n++;
                sibling->n--;
            } else if (idx != node->n && node->C[idx + 1]->n >= node->t) {
                struct BTreeNode *child = node->C[idx];
                struct BTreeNode *sibling = node->C[idx + 1];

                child->keys[child->n] = node->keys[idx];
                if (!child->leaf) {
                    child->C[child->n + 1] = sibling->C[0];
                }

                node->keys[idx] = sibling->keys[0];

                for (int i = 1; i < sibling->n; i++) {
                    sibling->keys[i - 1] = sibling->keys[i];
                }

                if (!sibling->leaf) {
                    for (int i = 1; i <= sibling->n; i++) {
                        sibling->C[i - 1] = sibling->C[i];
                    }
                }

                child->n++;
                sibling->n--;
            } else {
                if (idx != node->n) {
                    merge(node, idx);
                } else {
                    merge(node, idx - 1);
                    idx--;
                }
            }
        }

        if (flag && idx > node->n) {
            deleteKey(node->C[idx - 1], k);
        } else {
            deleteKey(node->C[idx], k);
        }
    }
}

// Function to delete a key from the B-tree
struct BTreeNode *delete(struct BTreeNode *root, int k) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return NULL;
    }

    deleteKey(root, k);

    if (root->n == 0) {
        struct BTreeNode *tmp = root;
        if (root->leaf) {
            root = NULL;
        } else {
            root = root->C[0];
        }
        free(tmp);
    }

    return root;
}

// Main function
int main() {
    int key,t;
    scanf("%d",&t);
    struct BTreeNode* root = NULL;
    while(1){
        scanf("%d",&key);
        if(key != 0){
            if(key>0){
                root=insert(root,key,t);
            }
            else{
            key = -key;
            root = delete(root,key);
            }
        }
        else{
            break;
        }
    }
    traverse(root);
    struct BTreeNode* k = search(root,7);
    return 0;
}
