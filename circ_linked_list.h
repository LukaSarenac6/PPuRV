#ifndef _CIRC_LINKED_LIST_H_
#define _CIRC_LINKED_lIST_H_

#pragma CHECK_MISRA("none")

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#pragma CHECK_MISRA("all")
#pragma CHECK_MISRA("-20.9")    /* izbacen da bi se mogao koristiti printf */
/*#pragma CHECK_MISRA("-20.10")*/
#pragma CHECK_MISRA("-10.1")



#define LIST_SIZE 4
#define DEFAULT 3

typedef int_fast8_t myInt;

typedef int_least32_t myLong;


struct node
{
    int32_t data;
    struct node* next;
};

void AddEleInFront(struct node** head, struct node* el);

void CreateList(struct node** head, int_least8_t size);

void PrintList(struct node* head);

void FreeList(struct node** head);

void RemoveNth(struct node** head, myInt n);




#endif
