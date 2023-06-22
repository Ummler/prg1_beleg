#include "search.h"
#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Contact *head;

Contact *getTail(Contact *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

int compareContacts(Contact *a, Contact *b, int field)
{
    switch (field)
    {
    case 1:
        return strcmp(a->name, b->name);
    case 2:
        return strcmp(a->firstname, b->firstname);
    case 3:
        return strcmp(a->phoneNumber, b->phoneNumber);
    default:
        return 0;
    }
}

Contact *partition(Contact *head, Contact *end, Contact **newHead, Contact **newEnd, int field)
{
    Contact *pivot = end;
    Contact *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (compareContacts(cur, pivot, field) < 0)
        {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            Contact *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Contact *quickSortRecur(Contact *head, Contact *end, int field)
{
    if (!head || head == end)
        return head;

    Contact *newHead = NULL, *newEnd = NULL;

    Contact *pivot = partition(head, end, &newHead, &newEnd, field);

    if (newHead != pivot)
    {
        Contact *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp, field);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd, field);

    return newHead;
}

int startsWith(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}

void sortContacts(int order, int field)
{
    head = quickSortRecur(head, getTail(head), field);

    if (order == 2)
    {
        Contact *prev = NULL;
        Contact *current = head;
        Contact *next;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
}

void searchContacts(char *searchTerm)
{
    int num = 0;
    Contact *ptr = head;
    while (ptr != NULL)
    {
        if (startsWith(searchTerm, ptr->name) || startsWith(searchTerm, ptr->firstname) || startsWith(searchTerm, ptr->phoneNumber))
        {
            printf("%s | %s | %s\n", ptr->name, ptr->firstname, ptr->phoneNumber);
            num++;
        }
        ptr = ptr->next;
    }
    if (num == 0)
    {
        printf("Keine Kontakte gefunden.\n");
    }
    else
    {
        printf("> Anzahl der Kontakte: %d\n", num);
    }
}
