#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LIST_INITIAL_CAPACITY 10

/*
 * ArrayList is a dynamic data structure that stores a sequence of elements and
 * automatically resizes itself as needed.
 */
typedef struct ArrayList {
    int *data;
    int size;
    int capacity;
} ArrayList;

/*
 * createArrayList creates a new empty array list and returns a pointer to it.
 */
ArrayList *createArrayList() {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->data = malloc(ARRAY_LIST_INITIAL_CAPACITY * sizeof(int));
    list->size = 0;
    list->capacity = ARRAY_LIST_INITIAL_CAPACITY;
    return list;
}

/*
 * ensureCapacity ensures that the array list has the given capacity or more. If
 * the array list must be resized, the data is copied to a new array of the
 * appropriate size.
 */
void ensureCapacity(ArrayList *list, int capacity) {
    if (capacity > list->capacity) {
        int *newData = malloc(capacity * sizeof(int));
        for (int i = 0; i < list->size; i++) {
            newData[i] = list->data[i];
        }
        free(list->data);
        list->data = newData;
        list->capacity = capacity;
    }
}

/*
 * add adds an element to the end of the array list.
 */
void add(ArrayList *list, int value) {
    ensureCapacity(list, list->size + 1);
    list->data[list->size] = value;
    list->size++;
}

/*
 * insert inserts an element at the given index in the array list. If the index is
 * outside the range of the array list, the function has no effect.
 */
void insert(ArrayList *list, int index, int value) {
    if (index >= 0 && index <= list->size) {
        ensureCapacity(list, list->size + 1);
        for (int i = list->size; i > index; i--) {
            list->data[i] = list->data[i - 1];
        }
        list->data[index] = value;
        list->size++;
    }
}

/*
 * get retrieves the element at the given index in the array list. If the index is
 * outside the range of the array list, the function returns -1.
 */
int get(ArrayList *list, int index) {
    if (index >= 0 && index < list->size) {
        return list->data[index];
    }
    return -1;
}

/*
 * remove removes the element at the given index in the array list. If the index is
 * outside the range of the array list, the function has no effect.
 */
void removeAt(ArrayList *list, int index) {
    if (index >= 0 && index < list->size) {
        for (int i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];
        }
        list->size--;
    }
}

/*
 * printArrayList prints the elements in the array list, separated by spaces.
 */
void printArrayList(ArrayList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    ArrayList *list = createArrayList();
    add(list, 1);
    add(list, 2);
    insert(list, 1, 3);
    printf("%d\n", get(list, 1));  // prints 3
    removeAt(list, 1);
    printArrayList(list);  // prints "1 2"
    return 0;
}
