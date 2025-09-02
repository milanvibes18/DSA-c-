
class DNode:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

def concatenateDLL():
    
    head1 = DNode(1)
    temp = head1
    for i in [2, 3]:
        newNode = DNode(i)
        temp.next = newNode
        newNode.prev = temp
        temp = newNode

    
    head2 = DNode(4)
    temp = head2
    for i in [5, 6]:
        newNode = DNode(i)
        temp.next = newNode
        newNode.prev = temp
        temp = newNode

    
    tail = head1
    while tail.next:
        tail = tail.next
    tail.next = head2
    head2.prev = tail

    
    print("Concatenated List:", end=" ")
    temp = head1
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()


# ---------------- Problem 2: Tower of Hanoi ----------------
def towerOfHanoi(n, from_rod, to_rod, aux_rod):
    if n == 0:
        return
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod)
    print(f"Move disk {n} from {from_rod} to {to_rod}")
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod)

def towerOfHanoiMain():
    n = 3  # Example: 3 disks
    towerOfHanoi(n, 'A', 'C', 'B')


# ---------------- Problem 3: Array Operations with Min-Max Removal ----------------
def arrayMinMax():
    arr = [5, 1, 9, 3, 7]
    n, k = len(arr), 2

    for _ in range(k):
        min_val = min(arr)
        max_val = max(arr)
        arr.remove(min_val)
        arr.remove(max_val)
        arr.append(max_val - min_val)

    print(f"Sum after {k} operations = {sum(arr)}")


# ---------------- Problem 4: Petrol Pump Circular Tour ----------------
def petrolPumpTour():
    petrol = [6, 3, 7]
    dist = [4, 6, 3]
    n = len(petrol)

    start, balance, deficit = 0, 0, 0
    for i in range(n):
        balance += petrol[i] - dist[i]
        if balance < 0:
            start = i + 1
            deficit += balance
            balance = 0

    if balance + deficit >= 0:
        print(f"Start at pump index {start}")
    else:
        print("No solution exists.")


# ---------------- Problem 5: Linear Search ----------------
def linearSearch():
    arr = [10, 20, 30, 40, 50]
    key = 30

    comparisons = 0
    found = -1
    for i, val in enumerate(arr):
        comparisons += 1
        if val == key:
            found = i
            break

    if found != -1:
        print(f"Element {key} found at index {found}")
    else:
        print("Element not found.")
    print(f"Comparisons = {comparisons}")


# ---------------- Problem 6: Binary Search ----------------
def binarySearch():
    arr = [5, 10, 15, 20, 25, 30]
    key = 20

    low, high = 0, len(arr) - 1
    found = -1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            found = mid
            break
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    if found != -1:
        print(f"Element {key} found at index {found}")
    else:
        print("Element not found.")


# ---------------- Problem 7: Interpolation Search ----------------
def interpolationSearch(arr, n, x):
    low, high = 0, n - 1
    while low <= high and arr[low] <= x <= arr[high]:
        if low == high:
            return low if arr[low] == x else -1
        pos = low + ((high - low) // (arr[high] - arr[low])) * (x - arr[low])
        if arr[pos] == x:
            return pos
        if arr[pos] < x:
            low = pos + 1
        else:
            high = pos - 1
    return -1

def interpolationSearchMain():
    arr = [10, 20, 30, 40, 50, 60, 70]
    key = 40
    idx = interpolationSearch(arr, len(arr), key)
    if idx != -1:
        print(f"Element {key} found at index {idx}")
    else:
        print("Element not found.")


# ---------------- Problem 8: Bubble Sort ----------------
def bubbleSort():
    arr = [64, 34, 25, 12, 22, 11, 90]

    print("Before sorting:", arr)
    swaps = 0
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swaps += 1

    print("After sorting:", arr)
    print(f"Total swaps = {swaps}")


# ---------------- Problem 9: Insertion Sort ----------------
def insertionSort():
    arr = [12, 11, 13, 5, 6]
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print(f"Pass {i}:", arr)


# ---------------- Problem 10: Selection Sort ----------------
def selectionSort():
    arr = [64, 25, 12, 22, 11]
    n = len(arr)
    comparisons, swaps = 0, 0

    for i in range(n - 1):
        minIdx = i
        for j in range(i + 1, n):
            comparisons += 1
            if arr[j] < arr[minIdx]:
                minIdx = j
        if minIdx != i:
            arr[i], arr[minIdx] = arr[minIdx], arr[i]
            swaps += 1

    print("Sorted array:", arr)
    print(f"Comparisons = {comparisons}, Swaps = {swaps}")


# ---------------- Main Function ----------------
def main():
    print("\n--- Problem 1: Concatenate Two Doubly Linked Lists ---")
    concatenateDLL()

    print("\n--- Problem 2: Tower of Hanoi ---")
    towerOfHanoiMain()

    print("\n--- Problem 3: Array Operations with Min-Max Removal ---")
    arrayMinMax()

    print("\n--- Problem 4: Petrol Pump Circular Tour ---")
    petrolPumpTour()

    print("\n--- Problem 5: Linear Search ---")
    linearSearch()

    print("\n--- Problem 6: Binary Search ---")
    binarySearch()

    print("\n--- Problem 7: Interpolation Search ---")
    interpolationSearchMain()

    print("\n--- Problem 8: Bubble Sort ---")
    bubbleSort()

    print("\n--- Problem 9: Insertion Sort ---")
    insertionSort()

    print("\n--- Problem 10: Selection Sort ---")
    selectionSort()


if __name__ == "__main__":
    main()