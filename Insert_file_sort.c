#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    FILE *file;
    int num, count = 0;
    int *arr = NULL;

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read integers from the file
    while (fscanf(file, "%d", &num) != EOF) {
        arr = (int *) realloc(arr, (count + 1) * sizeof(int));
        arr[count++] = num;
    }

    fclose(file);

    // Sort the array using insertion sort
    insertionSort(arr, count);

    // Open the file again for appending the sorted output
    file = fopen("input.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        free(arr);
        return 1;
    }

    // Append sorted data to the file
    fprintf(file,"\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
    free(arr);

    printf("Sorting complete. Data appended to the file.\n");

    return 0;
}

