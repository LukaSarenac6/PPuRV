#include "circ_linked_list.h"

int list_AddElement(struct node** head, struct node* el, LIST_DATA_TYPE n)
{
    struct node* node = *head;

    if (n == 1)
    {
        /* adds the element to the first place*/
        list_AddEleInFront(head, el);

    }
    else if (n == listSize+1)
    {
        /* adds the element to the back*/
        list_AddEleToBack(head, el);

    }
    else if (n < listSize && n > 0)
    {
        /* adds the element and corrects the list pointers*/
        for (; n > 2; --n)
        {
            node = node->next;
        }

        el->next = node->next;
        node->next = el;

        listSize++;
        return 1;

    }
    else
    {
        /* n must be in range 1 to "list size" + 1*/

        printf("\n The place where you want to put the element exceeds the size of the list %"PRIdLEAST8"\n", listSize);
        return 0;
    }
}

int list_AddEleInFront(struct node** head, struct node* el)
{
    /* If empty list: point head to new node and node to itself */
    if (*head == NULL)
    {
        el->next = el;
        *head = el;
        listSize++;
        return 1;
    }
    /* Point new node where head was pointing, point last node and head to the new node */
    struct node* last = *head;

    while (last->next != *head)
    {
        last = last->next;
    }

    el->next = *head;
    last->next = el;
    *head = el;

    listSize++;
    return 1;
}

int list_AddEleToBack(struct node** head, struct node* el)
{
    struct node* last_node = *head;
    /* If empty list: point head to new node and node to itself */
    if (*head == NULL)
    {
        el->next = el;
        *head = el;

        listSize++;
        return 1;
    }

    /* Find the last node */
    while (last_node->next != *head)
    {
        last_node = last_node->next;
    }

    last_node->next = el;
    el->next = *head;

    listSize++;
    return 1;

}

int list_DeleteFirstElement(struct node** head)
{
    if (*head == NULL)
    {
        printf("\nList already empty\n");
        return 0;
    }

    struct node* first = *head;
    struct node* last = *head;

    while (last->next != *head)
    {
        last = last->next;
    }

    last->next = first->next;
    *head = first->next;

    listSize--;
    free(first);
    return 1;

}

int list_DeleteLastElement(struct node** head)
{
    if (*head == NULL)
    {
        printf("\nList already empty\n");
        return 0;
    }
    struct node* last = *head;
    struct node* penultimate = *head;

    while (last->next != *head)
    {
        last = last->next;
    }

    while (penultimate->next != last)
    {
        penultimate = penultimate->next;
    }

    penultimate->next = *head;

    listSize--;
    free(last);

    return 1;


}

void list_CreateList(struct node** head, int_least8_t size)
{
    int_fast8_t i;

    for (i = 0; i < size; ++i)
    {
        struct node* node1 = (struct node*)malloc(sizeof(struct node));
        node1->data = i+11;
        if (list_AddEleToBack(head, node1)==0)
        {
            printf("Error when adding element");
            return;
        }
    }
}

void list_PrintList(struct node* head)
{
    struct node* current = head;
    /* List is empty */
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\n");
        while (current->next != head)
        {

            printf(""LIST_PRINTF_TYPE" -> ", current->data);
            current = current->next;
        }

        printf(""LIST_PRINTF_TYPE" -> ", current->data);
        printf("\n^... ("LIST_PRINTF_TYPE")", current->data);
        printf("\n\n");
    }
}

void list_FreeList(struct node** head)
{
    struct node* node_to_free = *head;
    struct node* next_node;

    /* List empty: no need to remove anything else, just return */
    if (*head==NULL)
    {
        return;
    }

    do{
        next_node = node_to_free->next;
        free(node_to_free);
        node_to_free = next_node;
    }while (node_to_free != *head);


    listSize = 0;
    *head = NULL;
}

void list_RemoveNth(struct node** head, list_myInt n)
{

    struct node* nodeN = *head;
    struct node* first = *head;
    struct node* previous = *head;

    int_fast8_t j = 0;

    /* List empty: no need to remove anything else, just return */
    if (*head==NULL)
    {
        return;
    }

    /* Points the previous element of the element we want to remove to the one he pointed to */
    while (previous->next != previous)
    {
        for (j = 1; j < n; ++j)
        {
            previous = previous->next;
        }
        nodeN = previous->next;
        previous->next = nodeN->next;
        /* if first element is to be removed point head to the second one */
        if (nodeN == *head)
        {
            *head = nodeN->next;
        }

        printf("\tRemoved element "LIST_PRINTF_TYPE"", nodeN->data);
        free(nodeN);

        printf("\n");

        list_PrintList(*head);

    }
    printf("\tRemoved element "LIST_PRINTF_TYPE"", previous->data);

    free(previous);

    listSize = 0;
    *head = NULL;

}

struct node* list_CreateNode(LIST_DATA_TYPE value)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = value;
    return node;
}