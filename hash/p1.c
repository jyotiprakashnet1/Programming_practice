#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *friend;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->friend = NULL;
    return newNode;
}

// Function to print the list along with friend pointers
void printListWithFriend(Node *head) {
    Node *current = head;
    while (current) {
        printf("Node data: %d, Friend data: %d\n", current->data,
               current->friend ? current->friend->data : -1);
        current = current->next;
    }
}

// Function to clone the linked list with friend pointers
Node* cloneList(Node *head) {
    // Hash map for original to clone mapping
    Node *hashMap[100] = {NULL}; // Assumption: max 100 nodes for simplicity

    // Step 1: Clone nodes and next pointers, populate hash map
    Node *original = head;
    Node *dummyHead = createNode(0); // Temporary head for new list
    Node *cloneCurrent = dummyHead;

    int index = 0;
    while (original) {
        // Clone the current node
        Node *clonedNode = createNode(original->data);
        hashMap[index++] = clonedNode; // Store clone in hash map
        cloneCurrent->next = clonedNode;
        cloneCurrent = cloneCurrent->next;
        
        // Advance the original node
        original = original->next;
    }

    // Step 2: Assign friend pointers using the hash map
    original = head;
    cloneCurrent = dummyHead->next;
    index = 0;
    while (original) {
        if (original->friend) {
            // Map friend's index from original to clone using hash map
            int friendIndex = 0;
            Node *friendPtr = head;
            while (friendPtr != original->friend) {
                friendPtr = friendPtr->next;
                friendIndex++;
            }
            cloneCurrent->friend = hashMap[friendIndex];
        }
        // Move to next pair of nodes
        original = original->next;
        cloneCurrent = cloneCurrent->next;
    }
    
    // Return the head of the new list
    return dummyHead->next;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    // Allocate an array of nodes
    Node *nodes[n];

    // Input the node data
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        nodes[i] = createNode(data);
    }

    // Link the NEXT pointers
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }

    // Input the FRIEND pointers
    for (int i = 0; i < n; i++) {
        int friendIndex;
        printf("Enter friend node index (1 to %d) for node %d (or 0 if no friend): ", n, i + 1);
        scanf("%d", &friendIndex);

        if (friendIndex > 0 && friendIndex <= n) {
            nodes[i]->friend = nodes[friendIndex - 1];
        } else if (friendIndex != 0) {
            printf("Invalid friend index for node %d.\n", i + 1);
            return 1;
        }
    }

    // Clone the list
    Node *clonedHead = cloneList(nodes[0]);

    // Print the cloned list with friend pointers
    printf("\nCloned List:\n");
    printListWithFriend(clonedHead);

    // Free the original and cloned lists
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }
    Node *current = clonedHead;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

