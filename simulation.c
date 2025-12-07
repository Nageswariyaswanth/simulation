#include <stdio.h>

#define MAX 100

// Function prototypes
void display(int arr[], int n);
int insert(int arr[], int n, int pos, int value);
int delete(int arr[], int n, int pos);
void search(int arr[], int n, int value);
void sortArray(int arr[], int n);

int main() {
    int arr[MAX];
    int n, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n----- ARRAY OPERATIONS MENU -----\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Sort Array (Ascending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                n = insert(arr, n, pos, value);
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                n = delete(arr, n, pos);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(arr, n, value);
                break;

            case 5:
                sortArray(arr, n);
                printf("Array sorted in ascending order.\n");
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function to display array
void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to insert element
int insert(int arr[], int n, int pos, int value) {
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    printf("Element inserted.\n");
    return n + 1;
}

// Function to delete element
int delete(int arr[], int n, int pos) {
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    printf("Element deleted.\n");
    return n - 1;
}

// Function to search for an element
void search(int arr[], int n, int value) {
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            found = i;
            break;
        }
    }
    if (found != -1)
        printf("Element found at position %d.\n", found + 1);
    else
        printf("Element not found.\n");
}

// Function to sort array in ascending order
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}