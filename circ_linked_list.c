#include"circ_linked_list.h"

void AddEleInFront(struct node** head, struct node* el){

    if(*head == NULL){

        el->next = el;
        *head = el;

    }else{

        struct node* last = *head;

        while(last->next != *head){
            last = last->next;

        }

        el->next = *head;
        last->next = el;
        *head = el;
    }
}

void CreateList(struct node** head, int_least32_t size){
    int_fast32_t i;

    for(i = 0; i < size; ++i){
        struct node* node1 = (struct node*)malloc(sizeof(struct node));
        node1->data = i+10;
        AddEleInFront(head, node1);
    }
}

void PrintList(struct node* head){
    struct node* current = head;

    if(head == NULL){
        printf("\nLista je prazna\n");
    }else{

        while(current->next != head){

            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("%d -> (%d)", current->data, current->next->data);
    }
}

void FreeList(struct node** head){
    struct node* node_to_free = *head;
    struct node* next_node;

    if(*head==NULL){
        return;
    }else{
        do{
            next_node = node_to_free->next;
            free(node_to_free);
            node_to_free = next_node;
            /*printf("\nMemorija oslobodjena!");*/
        }while(node_to_free != *head);
    }
    *head = NULL;
}

void RemoveNth(struct node** head, int_fast8_t n){

    struct node* nodeN = *head;
    struct node* first = *head;
    struct node* previous = *head;

    int_fast8_t j;
    int i = 0;
    if(*head==NULL){
        return;
    }else{
        while(previous->next != previous){
            for(j = 1; j < n; ++j){
                previous = previous->next;
            }
            nodeN = previous->next;
            previous->next = nodeN->next;

            if(nodeN == *head){
                *head = nodeN->next;
            }

            printf("\tIzbacen element %d", nodeN->data);
            free(nodeN);

            printf("\n");

            PrintList(*head);

        }
        printf("\tIzbacen element %d", previous->data);

        free(previous);

        *head = NULL;
        //PrintList(*head);

    }
}