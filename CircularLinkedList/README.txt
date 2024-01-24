Luka Sarenac RA 36-2020

U prvom delu zadatka trebao sam da napravim modul koji predstavlja jednostruko spregnutu kruznu listu.
Jednostruko spregnuta kruzna lista je lista u kojoj svaki element pokazuje na sledeceg, a poslenji na pocetak,
lista takodje sadrzi i glavu koja pokazuje na prvi element. Ovaj modul implementiran je u direktorijumu list.
Lista je implementirana pomocu strukture "node", struktura ima dva polja: pokazivac na sledeci node kao i data odnosno neki podatak koji se nalazi u njemu,
korisniku je omoguceno da sam stavlja vrednosti koje zeli ili da automatski kreira listu sa nasumicnim vrednostima,
kao i da iste brise (preporucivo uvek obrisati listu da bi se oslobodila zauzeta memorija!). Kao deo projektnog zadatka napravljena je i funkcija list_removeNTh
koja brise svaki n-ti element sve dok ne obrise sve elemente iz liste.
Drugi deo zadatka zahtevao je da se ovaj modul realizuje kao dinamicka biblioteka tokom izvrsavanja, ta funkcionalnost implementirana je u main.c s obzirom
da se poziva tokom izvrsavanja.



Manuelno pokretanje:     1. Pozicionirati se u direktorijum "list"
                         2. Run: gcc -c -fpic circ_linked_list.c
                         3. Run: gcc -shared -o libcirc_linked_list.so circ_linked_list.o
                         4. Vratiti se u prethodni direktorijum "projekat" gde se nalazi main.c
                         5. Run: gcc main.c -I list/ -L list/ -o main
                         6. Run: export LD_LIBRARY_PATH="apsolutna putanja do direktorijuma gde se nalazi .so":$LD_LIBRARY_PATH (ovaj korak potrebno je uraditi samo jednom, ali i svaki put po ulasku!)
                         7. Run: ./main

Ili pomocu bash skripte:    1. Pozicionirati se u direktorijum "projekat"
                            2. Run: ./build.sh
                            3. Procitati i uraditi korake 6. i 7. iz prethodne opcije.
