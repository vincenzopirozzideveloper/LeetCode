#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Per memset

typedef struct {
    int key;
    int value;
    int is_used;  // Flag per indicare se l'elemento è stato utilizzato
} HashItem;

typedef struct {
    HashItem* items;
    int size;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->items = (HashItem*) calloc(size, sizeof(HashItem));
    return table;
}

void freeHashTable(HashTable* table) {
    free(table->items);
    free(table);
}

int hash(int key, int size) {
    int index = (key % size + size) % size;  // Assicura un indice positivo
    return index;
}

void insert(HashTable* table, int key, int value) {
    int index = hash(key, table->size);
    while (table->items[index].is_used && table->items[index].key != key) {
        index = (index + 1) % table->size;  // Linear probing
    }
    table->items[index].key = key;
    table->items[index].value = value;
    table->items[index].is_used = 1;  // Segna come usato
}

int search(HashTable* table, int key) {
    int index = hash(key, table->size);
    while (table->items[index].is_used) {
        if (table->items[index].key == key) {
            return table->items[index].value;
        }
        index = (index + 1) % table->size;
    }
    return -1;  // Not found
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* hashTable = createHashTable(numsSize);
    int* result = (int*) malloc(2 * sizeof(int));
    *returnSize = 2;  // Always return 2 elements

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = search(hashTable, complement);
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            freeHashTable(hashTable);
            return result;
        }
        insert(hashTable, nums[i], i);
    }

    freeHashTable(hashTable);
    return result;  // This line in real scenarios would not execute if solution is guaranteed
}

int main() {
    // Definizione degli array di test e dei target corrispondenti
    int test_cases[][4] = {
        {2, 7, 11, 15},  // Dati per il primo caso
        {3, 2, 4},       // Dati per il secondo caso
        {3, 3}           // Dati per il terzo caso
    };
    int targets[] = {9, 6, 6};
    int sizes[] = {4, 3, 2};  // Dimensioni degli array di test

    for (int i = 0; i < 3; i++) {  // Ciclo attraverso ogni caso di test
        int* indices;
        int returnSize;
        indices = twoSum(test_cases[i], sizes[i], targets[i], &returnSize);  // Chiamata a twoSum

        if (indices != NULL) {
            printf("Test case %d - Indices: %d, %d\n", i + 1, indices[0], indices[1]);
            free(indices);  // Libera la memoria allocata
        } else {
            printf("Test case %d - No valid indices found.\n", i + 1);
        }
    }

    return 0;
}

