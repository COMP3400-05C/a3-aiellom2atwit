#include "list.h"
#include <stdlib.h>

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns the tail of a linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The tail of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_tail(struct ll_node *head) {
    //test for NULL list, return null
    if (head == NULL) {
        return NULL;
    }
    //create node variable to cycle through linked list
    struct ll_node *node = head;
    while ((node -> next) != NULL) {
        //iterate through list until the end
        node = node -> next;
    }
    //return last node found
    return node;
}

/**
 * Returns the number of nodes in a linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return int representing the number of nodes in linked list.
            If the list is empty (NULL), returns 0.
 */
int ll_size(struct ll_node *head) {
    struct ll_node *node = head;
    int size = 0;
    //cycles through nodes of linked list
    while (node != NULL) {
        //add 1 to size for each node
        size++;
        //iterate to next node
        node = node -> next;
    }
    //return the size we found
    return size;
}

/**
 * Returns the first node in the linked list matching the value.
 * 
 * @param head Pointer to the first node of the linked list.
 * @param value The data value (int) being searched for.
 * @return The first node in the linked list which matches the value.
            If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    //if list is NULL, returns NULL
    if (head == NULL) {
        return NULL;
    }
    struct ll_node *node = head;
    //iterate through nodes
    while (node != NULL) {
        //if data of the node matches value, return that node
        if (node -> data == value) {
            return node;
        }
        //iterate to next node
        node = node -> next;
    }
}

/**
 * Returns a malloc int array filled with each node's data of linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return An integer array with the same data values as the linked list.
            If list is empty (NULL), returns NULL.
 */
int *ll_toarray(struct ll_node *head) {
    //if list is NULL, returns NULL
    if (head == NULL) {
        return NULL;
    }
    //retrieve size of list from ll_size method
    int size = ll_size(head);

    struct ll_node *node = head;
    //create dynamic array with linked list size
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        //set array data to node's data
        arr[i] = node -> data;
        node = node -> next;
    }
    //return array result
    return arr;
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_create(int data) {
   
}

/**
 * TODO: Describe what the function does
 */
void ll_destroy(struct ll_node *head) {
    
}

/**
 * TODO: Describe what the function does
 */
void ll_append(struct ll_node *head, int data) {
 
}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_fromarray(int* data, int len) {

}

/**
 * TODO: Describe what the function does
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {

}

