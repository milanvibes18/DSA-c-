#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
#define HASH_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
    struct Node* hnext; // for hashmap chaining
} Node;

typedef struct {
    Node* head;
    Node* tail;
    Node* hashmap[HASH_SIZE];
    int size;
} LRUCache;

// Hash function
int hash(int key) {
    return key % HASH_SIZE;
}

// Create a new node
Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = node->next = node->hnext = NULL;
    return node;
}

// Remove node from doubly linked list
void removeNode(LRUCache* cache, Node* node) {
    if (node->prev) node->prev->next = node->next;
    else cache->head = node->next;

    if (node->next) node->next->prev = node->prev;
    else cache->tail = node->prev;
}

// Insert node at head of doubly linked list
void insertAtHead(LRUCache* cache, Node* node) {
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) cache->head->prev = node;
    cache->head = node;
    if (!cache->tail) cache->tail = node;
}

// Create the cache
LRUCache* createCache() {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = cache->tail = NULL;
    cache->size = 0;
    for (int i = 0; i < HASH_SIZE; i++) cache->hashmap[i] = NULL;
    return cache;
}

// Get value by key
int get(LRUCache* cache, int key) {
    int idx = hash(key);
    Node* node = cache->hashmap[idx];
    while (node && node->key != key) node = node->hnext;
    if (!node) return -1;

    removeNode(cache, node);
    insertAtHead(cache, node);
    return node->value;
}

// Put key-value pair
void put(LRUCache* cache, int key, int value) {
    int idx = hash(key);
    Node* node = cache->hashmap[idx];
    Node* prev = NULL;

    while (node && node->key != key) {
        prev = node;
        node = node->hnext;
    }

    if (node) {
        node->value = value;
        removeNode(cache, node);
        insertAtHead(cache, node);
    } else {
        if (cache->size == CAPACITY) {
            int tailIdx = hash(cache->tail->key);
            Node* temp = cache->hashmap[tailIdx];
            Node* prevTemp = NULL;
            while (temp && temp != cache->tail) {
                prevTemp = temp;
                temp = temp->hnext;
            }
            if (prevTemp) prevTemp->hnext = temp->hnext;
            else cache->hashmap[tailIdx] = temp->hnext;

            removeNode(cache, cache->tail);
            free(temp);
            cache->size--;
        }

        Node* newNode = createNode(key, value);
        insertAtHead(cache, newNode);
        newNode->hnext = cache->hashmap[idx];
        cache->hashmap[idx] = newNode;
        cache->size++;
    }
}

// Display cache state
void display(LRUCache* cache) {
    Node* curr = cache->head;
    printf("Cache: ");
    while (curr) {
        printf("(%d:%d) ", curr->key, curr->value);
        curr = curr->next;
    }
    printf("\n");
}

// Main function
int main() {
    LRUCache* cache = createCache();

    put(cache, 1, 10);
    display(cache);
    put(cache, 2, 20);
    display(cache);
    put(cache, 3, 30);
    display(cache);
    printf("Get 2: %d\n", get(cache, 2));
    display(cache);
    put(cache, 4, 40); // Evicts key 1
    display(cache);
    printf("Get 1: %d\n", get(cache, 1));
    printf("Get 3: %d\n", get(cache, 3));
    display(cache);

    return 0;
}
