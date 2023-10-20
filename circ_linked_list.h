#ifndef _CIRC_LINKED_LIST_H_
#define _CIRC_LINKED_lIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define LIST_TYPE int
#define LIST_SIZE 4

struct node
{

    LIST_TYPE data;
    struct node* next;
};

void AddEleInFront(struct node** head, struct node* el);

void CreateList(struct node** head, int_least32_t size);

void PrintList(struct node* head);

void FreeList(struct node** head);

void RemoveNth(struct node** head, int_fast8_t n);




#endif