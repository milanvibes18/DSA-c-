#include <stdio.h>
#include <stdlib.h>

/* ----------------- STRUCTURES ----------------- */
struct DNode {
    int data;
    struct DNode *prev, *next;
};

/* ----------------- FUNCTION DECLARATIONS ----------------- */
void concatenateDLL();
void towerOfHanoiMain();
void arrayMinMax();
void petrolPumpTour();
void linearSearch();
void binarySearch();
void interpolationSearchMain();
void bubbleSort();
void insertionSort();
void selectionSort();

/* ----------------- HELPER FUNCTIONS ----------------- */
// Tower of Hanoi Recursive
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / 
                    (arr[high] - arr[low])) * (x - arr[low]);

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

/* ----------------- MAIN ----------------- */
int main() {
    printf("\n--- Problem 1: Concatenate Two Doubly Linked Lists ---\n");
    concatenateDLL();

    printf("\n--- Problem 2: Tower of Hanoi ---\n");
    towerOfHanoiMain();

    printf("\n--- Problem 3: Array Operations with Min-Max Removal ---\n");
    arrayMinMax();

    printf("\n--- Problem 4: Petrol Pump Circular Tour ---\n");
    petrolPumpTour();

    printf("\n--- Problem 5: Linear Search ---\n");
    linearSearch();

    printf("\n--- Problem 6: Binary Search ---\n");
    binarySearch();

    printf("\n--- Problem 7: Interpolation Search ---\n");
    interpolationSearchMain();

    printf("\n--- Problem 8: Bubble Sort ---\n");
    bubbleSort();

    printf("\n--- Problem 9: Insertion Sort ---\n");
    insertionSort();

    printf("\n--- Problem 10: Selection Sort ---\n");
    selectionSort();

    return 0;
}

/* ----------------- PROBLEM FUNCTIONS ----------------- */

// 1. Concatenate Two Doubly Linked Lists
void concatenateDLL() {
    struct DNode *head1 = NULL, *head2 = NULL, *temp, *tail;

    // Create first list (1 -> 2 -> 3)
    head1 = (struct DNode*)malloc(sizeof(struct DNode));
    head1->data = 1; head1->prev = NULL;
    temp = head1;
    for (int i = 2; i <= 3; i++) {
        struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
        newNode->data = i;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }

    // Create second list (4 -> 5 -> 6)
    head2 = (struct DNode*)malloc(sizeof(struct DNode));
    head2->data = 4; head2->prev = NULL;
    temp = head2;
    for (int i = 5; i <= 6; i++) {
        struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
        newNode->data = i;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }

    // Concatenate
    tail = head1;
    while (tail->next) tail = tail->next;
    tail->next = head2;
    head2->prev = tail;

    printf("Concatenated List: ");
    temp = head1;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 2. Tower of Hanoi
void towerOfHanoiMain() {
    int n = 3; // Example: 3 disks
    towerOfHanoi(n, 'A', 'C', 'B');
}

// 3. Array Operations with Min-Max Removal
void arrayMinMax() {
    int arr[] = {5, 1, 9, 3, 7};
    int n = 5, k = 2;

    for (int op = 0; op < k; op++) {
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }
        int diff = arr[maxIdx] - arr[minIdx];

        int newArr[n - 1];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i != minIdx && i != maxIdx) newArr[j++] = arr[i];
        }
        newArr[j] = diff;
        n = j + 1;
        for (int i = 0; i < n; i++) arr[i] = newArr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    printf("Sum after %d operations = %d\n", k, sum);
}

// 4. Petrol Pump Circular Tour
void petrolPumpTour() {
    int petrol[] = {6, 3, 7};
    int dist[]   = {4, 6, 3};
    int n = 3;

    int start = 0, balance = 0, deficit = 0;
    for (int i = 0; i < n; i++) {
        balance += petrol[i] - dist[i];
        if (balance < 0) {
            start = i + 1;
            deficit += balance;
            balance = 0;
        }
    }
    if (balance + deficit >= 0) printf("Start at pump index %d\n", start);
    else printf("No solution exists.\n");
}

// 5. Linear Search
void linearSearch() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key = 30;

    int found = -1, comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) { found = i; break; }
    }
    if (found != -1) printf("Element %d found at index %d\n", key, found);
    else printf("Element not found.\n");
    printf("Comparisons = %d\n", comparisons);
}

// 6. Binary Search
void binarySearch() {
    int arr[] = {5, 10, 15, 20, 25, 30};
    int n = 6, key = 20;

    int low = 0, high = n - 1, mid, found = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) { found = mid; break; }
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    if (found != -1) printf("Element %d found at index %d\n", key, found);
    else printf("Element not found.\n");
}

// 7. Interpolation Search
void interpolationSearchMain() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7, key = 40;

    int idx = interpolationSearch(arr, n, key);
    if (idx != -1) printf("Element %d found at index %d\n", key, idx);
    else printf("Element not found.\n");
}

// 8. Bubble Sort
void bubbleSort() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7, swaps = 0;

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
                swaps++;
            }
        }
    }

    printf("After sorting: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTotal swaps = %d\n", swaps);
}

// 9. Insertion Sort
void insertionSort() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;

    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n");
    }
}

// 10. Selection Sort
void selectionSort() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5, comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            int t = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = t;
            swaps++;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nComparisons = %d, Swaps = %d\n", comparisons, swaps);
}