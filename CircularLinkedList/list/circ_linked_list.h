/**
 * @file circ_linked_list.h
 * @brief Circular linked list module. For use on embedded systems with limited resources
 *
 * @author Luka Sarenac
*/

#ifndef _CIRC_LINKED_LIST_H_
#define _CIRC_LINKED_LIST_H_

/* Disable misra checks for standard libs */
#pragma CHECK_MISRA("none")

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <dlfcn.h>

/* Enable misra again for the rest of the code */
#pragma CHECK_MISRA("all")
/**/
#pragma CHECK_MISRA("-20.9")
//
#pragma CHECK_MISRA("-20.10")
//
#pragma CHECK_MISRA("-10.1")

/** @brief Determins the size of the list when using CreateList function*/
#define LIST_CREATE_LIST_SIZE 10

/** @brief Used for testing the RemoveNth function*/
#define LIST_REMOVE_NTH_N 5

/** @brief Used when printing the data that is stored in the node*/
#define LIST_PRINTF_TYPE "%"PRIdFAST32""

/** @brief Used for easy manipulation with the type of data stored in the node*/
#define LIST_DATA_TYPE int_fast32_t

typedef int_fast8_t list_myInt;
typedef int_least32_t list_myLong;

int_least8_t listSize = 0;  /* this value depends on the arhitecture */

/** @brief Struct used for working with list*/
struct node
{
    /** @brief values of the nodes*/
    LIST_DATA_TYPE data;

    /** @brief a pointer to the next node*/
    struct node* next;
};

/**
 * @brief adds an element to the given position in the list
 *
 * @param[in] head a pointer to the head of the list
 * @param[in] el a node that will be added
 * @param[in] n place in the list where the element will be added
*/
int list_AddElement(struct node** head, struct node* el, LIST_DATA_TYPE n);

/**
 * @brief adds an element to the front of the list
 *
 * @param[in] head a pointer to the head of the list
 * @param[in] el a node that will be added
*/
int list_AddEleInFront(struct node** head, struct node* el);

/**
 * @brief adds an element to the back of the list
 *
 * @param[in] head a pointer to the head of the list
 * @param[in] el a node that will be addes
*/
int list_AddEleToBack(struct node** head, struct node* el);

/**
 * @brief Deletes the first element
 *
 * @param[in] head a pointer to the head of the list
*/
int list_DeleteFirstElement(struct node** head);

/**
 * @brief deletes the last element
 *
 * @param[in] head a pointer to the head of the list
*/
int list_DeleteLastElement(struct node** head);

/**
 * @brief function used to generate a list with random numbers
 *
 * @param[in] head a pointer to the head of the list
 * @param[in] size number of elements in the list
*/
void list_CreateList(struct node** head, int_least8_t size);

/**
 * @brief prints the list
 *
 * @param[in] head head of the list
*/
void list_PrintList(struct node* head);

/**
 * @brief deletes the list and frees the memory allocated for every element.
 *
 * @param[in] head a pointer to the head of the list
*/
void list_FreeList(struct node** head);


/**
 * @brief Removes every n-th element in the list until the list is empty
 *
 * @param[in] head a pointer to the head of the list
 * @param[in] n used for the removal of every n-th element
 *
 * @details this function was implemented for the purpose of the task, to save time when deleting the list use FreeList function
*/
void list_RemoveNth(struct node** head, list_myInt n);

/**
 * @brief Creates a node
 *
 * @param[in] value the value stored in nodes data
*/
struct node* list_CreateNode(LIST_DATA_TYPE value);

#endif /* CIRC_LINKED_LIST_H */
