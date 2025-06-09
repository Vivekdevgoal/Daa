#include <stdio.h>

// Iterative Binary Search
int iterativeBinarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return recursiveBinarySearch(arr, low, mid - 1, key);
    else
        return recursiveBinarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key, result, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\nChoose search method:\n");
    printf("1. Iterative Binary Search\n");
    printf("2. Recursive Binary Search\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = iterativeBinarySearch(arr, n, key);
            break;
        case 2:
            result = recursiveBinarySearch(arr, 0, n - 1, key);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    if (result == -1)
        printf("Element not found.\n");
    else {
        printf("Element found at:\n");
        printf("Index    : %d\n", result);       // 0-based index
        printf("Position : %d\n", result + 1);   // 1-based position
    }

    return 0;
}

