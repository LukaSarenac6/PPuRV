#include "circ_linked_list.h"


list_myInt main(void);

list_myInt main(void)
{
    list_myInt arg = 0;
    struct node* head_node = NULL;
    void* handle = dlopen("libcirc_linked_list.so", RTLD_LAZY);

    if (handle)
    {
        void (*list_CreateList)(struct node**, int_least8_t) = dlsym(handle, "list_CreateList");
        void (*list_PrintList)(struct node*) = dlsym(handle, "list_PrintList");
        void (*list_RemoveNth)(struct node**, list_myInt) = dlsym(handle, "list_RemoveNth");
        int (*list_AddEleInFront)(struct node**, struct node*) = dlsym(handle, "list_AddEleInFront");
        int (*list_AddEleToBack)(struct node**, struct node*) = dlsym(handle, "list_AddEleToBack");
        void (*list_DeleteFirstElement)(struct node**) = dlsym(handle, "list_DeleteFirstElement");
        void (*list_DeleteLastElement)(struct node**) = dlsym(handle, "list_DeleteLastElement");
        struct node* (*list_CreateNode)(LIST_DATA_TYPE) = dlsym(handle, "list_CreateNode");
        void (*list_FreeList)(struct node**) = dlsym(handle, "list_FreeList");
        int (*list_AddElement)(struct node**, struct node*, LIST_DATA_TYPE) = dlsym(handle, "list_AddElement");

        if (list_CreateList && list_PrintList && list_RemoveNth && list_AddEleInFront && list_AddEleToBack && list_DeleteFirstElement && list_DeleteLastElement && list_CreateNode && list_FreeList && list_AddElement)
        {
            printf("\n\n1.Testing automatic creation and RemoveNth function\n");
            list_CreateList(&head_node, LIST_CREATE_LIST_SIZE);
            list_PrintList(head_node);
            list_RemoveNth(&head_node, LIST_REMOVE_NTH_N);
            list_PrintList(head_node);

            printf("\n!!!Enter a char to continue testing!!!\n");
            getchar();

            printf("\n\n2.Testing manual adding and deleting\n");
            list_PrintList(head_node);

            printf("\nAdded 3 elements in front\n");
            list_AddEleInFront(&head_node, list_CreateNode(10.6757));
            list_AddEleInFront(&head_node, list_CreateNode(11));
            list_AddEleInFront(&head_node, list_CreateNode(12));
            list_PrintList(head_node);

            printf("\nRemoved first element\n");
            list_DeleteFirstElement(&head_node);
            list_PrintList(head_node);

            printf("\nAdded 3 elements to back\n");
            list_AddEleToBack(&head_node, list_CreateNode(100));
            list_AddEleToBack(&head_node, list_CreateNode(200));
            list_AddEleToBack(&head_node, list_CreateNode(300));
            list_PrintList(head_node);

            printf("\nRemoved last element\n");
            list_DeleteLastElement(&head_node);
            list_PrintList(head_node);

            list_FreeList(&head_node);
            list_PrintList(head_node);

            printf("\n!!!Enter a char to continue testing!!!\n");
            getchar();
            getchar();
            printf("\n\n3. Testing the addition to the given place\n");

            printf("\nAdded 1, 2, 3, 4 in that order\n");
            list_AddElement(&head_node, list_CreateNode(1), 1);
            list_AddElement(&head_node, list_CreateNode(2), 2);
            list_AddElement(&head_node, list_CreateNode(3), 3);
            list_AddElement(&head_node, list_CreateNode(4), 4);
            list_PrintList(head_node);

            printf("\nAdd 22 in 2nd place\n");
            list_AddElement(&head_node, list_CreateNode(22), 2);
            list_PrintList(head_node);

            printf("\nAdd 232 in 4th place\n");
            list_AddElement(&head_node, list_CreateNode(232), 4);
            list_PrintList(head_node);

            printf("\nAdd 252 in 3rd place\n");
            list_AddElement(&head_node, list_CreateNode(252), 3);
            list_PrintList(head_node);

            list_FreeList(&head_node);

        }
        else
        {
            printf("Failed to obtain function pointers: %s\n", dlerror());
        }

        dlclose(handle);
    }
    else
    {
        printf("Failed to load library: %s\n", dlerror());
    }

    return 0;
}
