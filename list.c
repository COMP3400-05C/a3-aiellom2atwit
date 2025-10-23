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
 * Creates a new node from given int data.
 * 
 * @param data Integer value to be stored in the node.
 * @return struct ll_node* Returns the created node.
 */
struct ll_node *ll_create(int data) {
    //creates new node
    struct ll_node *node = malloc(sizeof(struct ll_node));
    //failure case if malloc didn't allocate space
    if (node == NULL) {
        return NULL;
    }
    //sets the pointers of the node and returns it
    node -> data = data;
    node -> next = NULL;
    return node;
}

/**
 * Cycles through every node in the linked list and frees them to remove them.
 * 
 * @param head Pointer to the first node of the linked list.
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *node = head;
    //cycles through every node in linked list, deleting it
    while (node != NULL) {
        struct ll_node *next = node -> next;
        free(node);
        node = next;
    }
}

/**
 * Creates a new node with specific integer value and appends it to linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @param data The integer value to be stored in the appended node.
 */
void ll_append(struct ll_node *head, int data) {
    struct ll_node *node = head;
    //cycles to the end of the array
    while (node -> next != NULL) {
        node = node -> next;
    }
    //appends a new node to the linked list with the data
    node -> next = ll_create(data);
}

/**
 * Takes an array of ints and converts it into a new linked list array.
 * 
 * @param data Integer array to be converted to linked list.
 * @param len Length of int array.
 * @return struct ll_node* Returns head of the linked list.
 */
struct ll_node *ll_fromarray(int* data, int len) {
    //tests for invalid lengths, returns null
    if (len <= 0) {
        return NULL;
    }
    //creates the first node of the array as the head
    struct ll_node *head = ll_create(data[0]);
    struct ll_node *node = head;

    //cycles through every number in array after first
    for (int i = 1; i < len; i++) {
        //creates a new node in the linked list with the data from the array
        node -> next = ll_create(data[i]);
        node = node -> next;
    }
    //returns head of the array
    return head;
}

/**
 * Searches for a value in linked list, removes it, and fixes linked node chain.
 * 
 * @param head Pointer to the first node of the linked list.
 * @param value Integer value that is searched for in linked list.
 * @return struct ll_node* Returns the removed node (Returns NULL if no node was found).
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    //checks if linked list is valid, if not return NULL
    if (head == NULL) {
        return NULL;
    }
    
    //if head matches value remove it and set second node as head
    if (head -> data == value) {
        struct ll_node *removed = head;
        head = head -> next;
        free(removed);
        return head;
    }

    //assigns previous and next node to cycle through linked list
    struct ll_node *previous = head;
    struct ll_node *current = head -> next;

    //cycle through linked list
    while (current != NULL) {
        //if the current array's data pointer matches search value, remove it
        if (current -> data == value) {
            //set previous node's pointer after removed node
            previous -> next = current -> next;
            free(current);
            break;
        }
        //iterate to next node in chain
        previous = current;
        current = current -> next;
    }

    //return head of the list
    return head;

}

