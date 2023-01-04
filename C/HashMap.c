#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 16

typedef struct HashMapEntry {
    char *key;
    void *value;
    struct HashMapEntry *next;
} HashMapEntry;

typedef struct HashMap {
    HashMapEntry *entries[HASH_MAP_SIZE];
} HashMap;

// Hash function to determine the index for a given key
int hash(char *key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % HASH_MAP_SIZE;
}

// Create a new hash map
HashMap *createHashMap() {
    HashMap *map = malloc(sizeof(HashMap));
    for (int i = 0; i < HASH_MAP_SIZE; i++) {
        map->entries[i] = NULL;
    }
    return map;
}

// Set the value for a key in the hash map
void set(HashMap *map, char *key, void *value) {
    int index = hash(key);
    HashMapEntry *entry = map->entries[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            // Update value if key already exists
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    // Key does not exist, create a new entry
    entry = malloc(sizeof(HashMapEntry));
    entry->key = key;
    entry->value = value;
    entry->next = map->entries[index];
    map->entries[index] = entry;
}

// Get the value for a key in the hash map
void *get(HashMap *map, char *key) {
    int index = hash(key);
    HashMapEntry *entry = map->entries[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

// Remove the entry for a key in the hash map
void removeEntry(HashMap *map, char *key) {
    int index = hash(key);
    HashMapEntry *entry = map->entries[index];
    HashMapEntry *prev = NULL;
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                // Remove first entry
                map->entries[index] = entry->next;
            } else {
                // Remove entry in the middle or end
                prev->next = entry->next;
            }
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}

int main() {
    return 0;
}