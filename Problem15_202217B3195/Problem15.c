#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;        // key is string
    char* value;      // value is also string
    struct node* next;
};

// Function to create and initialize a new node
struct node* new_node(char* key, char* value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = strdup(key);       // Duplicate the key string
    temp->value = strdup(value);   // Duplicate the value string
    temp->next = NULL;
    return temp;
}

// HashMap structure
struct hashMap {
    int numOfElements;
    int capacity;
    struct node** arr;
};

// Function to initialize a hash map
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;  // Default capacity
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function to compute bucket index
int hashFunction(struct hashMap* mp, char* key) {
    int bucketIndex = 0;
    int factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        bucketIndex = (bucketIndex * factor + key[i]) % mp->capacity;
    }
    return bucketIndex;
}

// Function to insert a key-value pair into the hash map
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = new_node(key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}

// Function to delete a key-value pair from the hash map
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (prevNode == NULL) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a value by key in the hash map
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(key, bucketHead->key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.";
}

// Main function demonstrating the hash map operations
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer")); // Manish
    printf("%s\n", search(mp, "Yogaholic"));         // Anjali
    printf("%s\n", search(mp, "pluto14"));           // Vartika
    printf("%s\n", search(mp, "decentBoy"));         // Mayank
    printf("%s\n", search(mp, "GFG"));               // BITS
    printf("%s\n", search(mp, "randomKey"));         // Oops! No data found.

    printf("\nAfter deletion:\n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));         // Oops! No data found.

    // Free allocated memory
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* nextNode = currNode->next;
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            currNode = nextNode;
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
