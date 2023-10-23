/*
Luka Sarenac RA 36-2020

U prvom delu zadatka trebao sam da napravim modul koji predstavlja jednostruko spregnutu kruznu listu.
Jednostruko spregnuta kruzna lista je lista u kojoj svaki element pokazuje na sledeceg, a poslenji na pocetak,
lista takodje sadrzi i glavu koja pokazuje na prvi element. Lista je implementirana pomocu strukture "node", struktura ima dva polja
pokazivac na sledeci node kao i data odnosno neki podatak koji se nalazi u njemu, u ovom slucaju ja sam samo stavljao brojeve od 10 pa na dalje. Lista je napravljena pomocu funkcija
AddElInFront koja dodaje element na pocetak i koju koristim u funkciji CreateList kojoj prosledjujemo velicinu liste koj zelimo i glavu liste. Drugi deo zadatka zahtevao je da
se napravi funkcija koja izbacuje svaki n-ti element i ispisuje ga, to je funkcija RemoveNth, u njoj se koristi i funkcija PrintList (koja ispisuje listu), nakon svakog izbacivanja.
Funkciji RemoveNth se prosledjuje broj n, koji se dobija ili preko komandne linije ili preko scanf-a, koriscenjem pretprocesorskih direktiva #if #elif #endif moze se izabrati koji nacin zelimo.
Na kraju, koristeci znanje sa vezbi, modul je izveden kao dinamicka biblioteka, i kao takav se koristi.

*/


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

myInt main(int_fast8_t argc, const char* const argv[]);

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
