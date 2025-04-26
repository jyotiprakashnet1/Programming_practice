#include <stdio.h>

#define MAX 1000  // Maximum number of elements

int parent[MAX];
int rank[MAX];

// Function to create a new set for element x
void make_set(int x) {
	parent[x] = x;
	rank[x] = 0;
}

// Function to find the representative of the set containing x
int find_set(int x) {
	if (parent[x] != x) {
		parent[x] = find_set(parent[x]);  // Path compression
	}
	return parent[x];
}

// Function to merge the sets containing x and y
void union_sets(int x, int y) {
	int root_x = find_set(x);
	int root_y = find_set(y);

	if (root_x != root_y) {
		// Union by rank
		if (rank[root_x] > rank[root_y]) {
			parent[root_y] = root_x;
		} else if (rank[root_x] < rank[root_y]) {
			parent[root_x] = root_y;
		} else {
			parent[root_y] = root_x;
			rank[root_x]++;
		}
	}
}

int main() {
	// Example usage
	int n = 5,x; // Number of elements
		     // Create sets for each element
	for (int i = 0; i < n; i++) {
		//scanf("%d",&x);
		make_set(i);
	}

	// Perform some union operations
	union_sets(0, 1);
	//union_sets(1, 2);
	//union_sets(3, 4);
	union_sets(1,4);

	// Find and print representatives of each set
	for (int i = 0; i < n; i++) {
		printf("Find-Set(%d): %d\n", i, find_set(i));
	}

	return 0;
}

