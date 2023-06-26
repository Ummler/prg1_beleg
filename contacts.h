/*
*   Autor: Florian Umlauft
*   Datum: 26/06/2023
*   Matrikelnummer: 51345
*   Modul: Programmierung 1
*   Studiennummer: 21-041-62
*   Email: florian.umlauft@htw-dresden.de
*   Hochschule: Hochschule für Technik und Wirtschaft Dresden
*/
typedef struct Contact {
    char name[100];
    char firstname[100];
    char phoneNumber[15];
    struct Contact *next;
} Contact;

void addContact(Contact* contact);
void deleteAllContacts();
void readContactsFromFile();
void saveContactsToFile();
Contact* createContact(char* name, char* firstname, char* phoneNumber);
