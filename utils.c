#include "utils.h"
#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void generateRandomContacts(int num) {
    FILE* file = fopen("example_contacts.csv", "r");
    char line[256];
    int count = 0;
    
    if(file == NULL) {
        printf("Konnte die Datei example_contacts.csv nicht öffnen\n");
        return;
    }
    
    while(fgets(line, sizeof(line), file) && count < num) {
        char *name = strtok(line, ",");
        char *firstname = strtok(NULL, ",");
        char *phoneNumber = strtok(NULL, ",");
        
        // Entfernen Sie das newline-Zeichen vom Ende der Telefonnummer
        phoneNumber[strcspn(phoneNumber, "\n")] = 0;

        addContact(createContact(name, firstname, phoneNumber));
        count++;
    }
    
    fclose(file);
}


