#include "singlylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
node *createList(void* headVal)
{
    node *head = (node *)malloc(sizeof(node));
    head->value = headVal;
    head->next = NULL;
    return head;
}
void insert(node *head, void* val)
{
    int x = val;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = val;
    newnode->next = NULL;
    node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newnode;
}

/**
void delEnd(node *head)
{
    node **p = &head;
    while (*p != 0)
    {
        p = &(*p)->next;
    }
    node* deleted = *p;
    *p = deleted->next;
    deleted->next = 0;
    return deleted;
}
*/
void freeList(node *head)
{
}