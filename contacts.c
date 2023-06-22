#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Contact *head = NULL;

Contact *createContact(char *name, char *firstname, char *phoneNumber)
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->firstname, firstname);
    strcpy(newContact->phoneNumber, phoneNumber);
    newContact->next = NULL;
    return newContact;
}

void addContact(Contact *contact)
{
    if (head == NULL)
    {
        head = contact;
    }
    else
    {
        Contact *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = contact;
    }
}

void deleteAllContacts()
{
    Contact *current = head;
    Contact *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

void readContactsFromFile()
{
    FILE *file = fopen("contacts.csv", "r");
    if (file == NULL)
    {
        printf("Datei konnte nicht geöffnet werden.\n");
        return;
    }

    char name[100];
    char firstname[100];
    char phoneNumber[15];

    while (fscanf(file, "%[^,],%[^,],%s\n", name, firstname, phoneNumber) == 3)
    {
        addContact(createContact(name, firstname, phoneNumber));
    }

    fclose(file);
}

void saveContactsToFile()
{
    FILE *file = fopen("contacts.csv", "w");
    if (file == NULL)
    {
        printf("Datei konnte nicht geöffnet werden.\n");
        return;
    }

    Contact *current = head;
    while (current != NULL)
    {
        fprintf(file, "%s,%s,%s\n", current->name, current->firstname, current->phoneNumber);
        current = current->next;
    }

    fclose(file);
}
