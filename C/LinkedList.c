#include <stdio.h>
#include <stdlib.h>

/*
 * ListNode represents a node in a singly linked list. It stores an integer value
 * and a pointer to the next node.
 */
typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

/*
 * List represents a singly linked list. It stores a pointer to the head node.
 */
typedef struct List {
    ListNode *head;
} List;

/*
 * createList creates a new empty list and returns a pointer to it.
 */
List *createList() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

/*
 * insertAtFront inserts a new node with the given value at the front of the list.
 */
void insertAtFront(List *list, int value) {
    ListNode *node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = list->head;
    list->head = node;
}

/*
 * removeFromFront removes the node at the front of the list and returns its value.
 * If the list is empty, the function returns -1.
 */
int removeFromFront(List *list) {
    if (list->head != NULL) {
        ListNode *node = list->head;
        list->head = node->next;
        int value = node->value;
        free(node);
        return value;
    }
    return -1;
}

/*
 * findNode finds the first node with the given value in the list and returns a
 * pointer to it, or NULL if no such node exists.
 */
ListNode *findNode(List *list, int value) {
    ListNode *node = list->head;
    while (node != NULL) {
        if (node->value == value) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/*
 * removeNode removes the first node with the given value from the list. If no such
 * node exists, the function has no effect.
 */
void removeNode(List *list, int value) {
    ListNode *prev = NULL;
    ListNode *node = list->head;
    while (node != NULL) {
        if (node->value == value) {
            if (prev == NULL) {
                // Remove first node
                list->head = node->next;
            } else {
                // Remove node in the middle or end
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

/*
 * printList prints the values of the nodes in the list, separated by spaces.
 */
void printList(List *list) {
    ListNode *node = list->head;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    return 0;
}