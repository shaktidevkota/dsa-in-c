#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX];
    int n, i, choice, pos, value, found;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Display
                printf("Array elements: ");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2: // Insert
                printf("Enter position (0 to %d) to insert: ", n);
                scanf("%d", &pos);
                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                for(i = n; i > pos; i--) {
                    arr[i] = arr[i-1];
                }
                arr[pos] = value;
                n++;
                printf("Element inserted.\n");
                break;

            case 3: // Delete
                printf("Enter position (0 to %d) to delete: ", n-1);
                scanf("%d", &pos);
                if(pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                    break;
                }
                for(i = pos; i < n-1; i++) {
                    arr[i] = arr[i+1];
                }
                n--;
                printf("Element deleted.\n");
                break;

            case 4: // Search
                printf("Enter element to search: ");
                scanf("%d", &value);
                found = -1;
                for(i = 0; i < n; i++) {
                    if(arr[i] == value) {
                        found = i;
                        break;
                    }
                }
                if(found != -1) {
                    printf("Element found at index %d\n", found);
                } else {
                    printf("Element not found.\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
