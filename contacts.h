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
