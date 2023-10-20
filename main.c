#include"circ_linked_list.h"

#if 0
int main()
{

    struct node* head = NULL;

    struct node* node1 = (struct node*)malloc(sizeof(struct node));
    node1->data = 132;
    AddEleInFront(&head, node1);


    printf("%d", node1->data);

    free(node1);

    return 0;
}

#elif 1

int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        printf("Niste uneli trazen broj argumenata!\n");
        return 1;
    }

    int_fast8_t n = atoi(argv[1]);
    printf("Zelite da se brise svaki %d element\n", n);

    struct node* head = NULL;

    CreateList(&head, LIST_SIZE);
    PrintList(head);
    FreeList(&head);

    CreateList(&head, LIST_SIZE);
    RemoveNth(&head, n);
    PrintList(head);


}

#endif