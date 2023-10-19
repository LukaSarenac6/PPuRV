#include"circ_linked_list.h"

#if 0
int main(){

    struct node* head = NULL;

    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = 132;
    AddEleInFront(&head, node1);


    printf("%d", node1->data);

    free(node1);

    return 0;
}

#elif 1

int main(){
    struct node* head = NULL;

    CreateList(&head, LIST_SIZE);
    PrintList(head);
    FreeList(&head);
    //printf("USAO1");
    CreateList(&head, LIST_SIZE);
    RemoveNth(&head, 5);
    PrintList(head);

    //PrintList(head);
}

#endif