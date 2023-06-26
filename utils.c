/*
*   Autor: Florian Umlauft
*   Datum: 26/06/2023
*   Matrikelnummer: 51345
*   Modul: Programmierung 1
*   Studiennummer: 21-041-62
*   Email: florian.umlauft@htw-dresden.de
*   Hochschule: Hochschule für Technik und Wirtschaft Dresden
*/

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
        
        // Entfernen des newline-Zeichens vom Ende der Telefonnummer
        phoneNumber[strcspn(phoneNumber, "\n")] = 0;

        addContact(createContact(name, firstname, phoneNumber));
        count++;
    }
    
    fclose(file);
}


