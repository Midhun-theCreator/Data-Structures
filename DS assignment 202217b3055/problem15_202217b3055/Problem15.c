#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Function to create a new node
void setNode(struct node* node, char* key, char* value) {
    node->key = strdup(key);  // Allocate and copy the key
    node->value = strdup(value);  // Allocate and copy the value
    node->next = NULL;
}

// Hash map structure
struct hashMap {
    int numOfElements, capacity;
    struct node** arr;
};

// Function to initialize hash map
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)calloc(mp->capacity, sizeof(struct node*));
}

// Hash function to get the index for a given key
int hashFunction(struct hashMap* mp, char* key) {
    int bucketIndex;
    int sum = 0, factor = 31;

    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum * factor) + key[i]) % mp->capacity;
    }
    bucketIndex = sum;
    return bucketIndex;
}

// Function to insert a key-value pair into the hash map
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete a key from the hash map
void deleteNode(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
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
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.\n";
}

// Driver function to test the hash map
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    // Key is not inserted
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion:\n");
    // Deletion of key
    deleteNode(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    // Freeing remaining nodes and the hash map
    for (int i = 0; i < mp->capacity; i++) {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) {
            struct node* temp = currNode;
            currNode = currNode->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
