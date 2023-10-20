#include"circ_linked_list.h"

myInt main(void);

#if 1
myInt main(void)
{

    myInt arg = 0;

    printf("Unesite n\t");
    scanf("%hhd", &arg);
    struct node* head_node = NULL;

    CreateList(&head_node, LIST_SIZE);
    PrintList(head_node);
    FreeList(&head_node);

    CreateList(&head_node, LIST_SIZE);
    RemoveNth(&head_node, arg);
    PrintList(head_node);


    return 0;
}

#elif 0

myInt main(int_fast8_t argc, const char* const argv[])
{

    if (argc != 2)
    {
        printf("Niste uneli trazen broj argumenata!\n");

    }else
    {
        myInt arg = atoi(argv[1]);
        struct node* head_node = NULL;

        CreateList(&head_node, LIST_SIZE);
        PrintList(head_node);
        FreeList(&head_node);

        CreateList(&head_node, LIST_SIZE);
        RemoveNth(&head_node, arg);
        PrintList(head_node);
    }

    return 0;
}
#endif
