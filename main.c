/*
*   Autor: Florian Umlauft
*   Datum: 26/06/2023
*   Matrikelnummer: 51345
*   Modul: Programmierung 1
*   Studiennummer: 21-041-62
*   Email: florian.umlauft@htw-dresden.de
*   Hochschule: Hochschule für Technik und Wirtschaft Dresden
*/

#include "contacts.h"
#include "utils.h"
#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char *progName);
extern Contact *head;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        usage(argv[0]);
        return -1;
    }

    // Initialisiere Kontaktliste
    readContactsFromFile();

    if (strcmp(argv[1], "-n") == 0)
    {
        if (argc != 5)
        {
            printf("Falsche Anzahl von Argumenten für die Option -n\n");
            usage(argv[0]);
            return -1;
        }
        addContact(createContact(argv[2], argv[3], argv[4]));
        printf("Kontakt erfolgreich hinzugefügt.\n");
    }
    else if (strcmp(argv[1], "-o") == 0)
    {
        char sort_order[10];
        char sort_field[10];

        printf("Soll aufsteigend (A-Z) oder absteigend (Z-A) sortiert werden? (A/Z): ");
        scanf("%s", sort_order);
        printf("Nach welchem Feld soll sortiert werden? (Name, Vorname, Telefonnummer): ");
        scanf("%s", sort_field);

        int order = (strcmp(sort_order, "A") == 0) ? 1 : 2;
        int field = (strcmp(sort_field, "Name") == 0) ? 1 : ((strcmp(sort_field, "Vorname") == 0) ? 2 : 3);
        int num = 0;
        sortContacts(order, field);

        Contact *ptr = head;
        while (ptr != NULL)
        {
            printf("%-20s | %-20s | %-15s\n", ptr->name, ptr->firstname, ptr->phoneNumber);
            ptr = ptr->next;
            num++;
        }
        if (num == 0)
        {
            printf("Keine Kontakte gefunden.\n");
        }
        else
        {
            printf("> Anzahl der Kontakte: %d\n", num);
        }

        //
    }
    else if (strcmp(argv[1], "-s") == 0)
    {
        if (argc != 3)
        {
            printf("Falsche Anzahl von Argumenten für die Option -s\n");
            usage(argv[0]);
            return -1;
        }
        searchContacts(argv[2]);
    }
    else if (strcmp(argv[1], "-k") == 0)
    {
        deleteAllContacts();
        printf("Alle Kontakte erfolgreich gelöscht.\n");
    }
    else if (strcmp(argv[1], "-c") == 0)
    {
        generateRandomContacts(25);
        printf("25 zufällige Kontakte erfolgreich erstellt.\n");
    }
    else
    {
        printf("Unbekannte Option: %s\n", argv[1]);
        usage(argv[0]);
        return -1;
    }

    saveContactsToFile();

    return 0;
}

void usage(char *progName)
{
    fprintf(stderr, "Usage: %s [option] [arguments]\n", progName);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "-n [Name] [Vorname] [Telefonnummer] : neuen Kontakt hinzufügen\n");
    fprintf(stderr, "-o : sortiert und listet Kontakte\n");
    fprintf(stderr, "-s [Argument] : sucht Kontakte\n");
    fprintf(stderr, "-k : löscht alle Kontakte\n");
    fprintf(stderr, "-c : erstellt zufällige Kontakte\n");
}
