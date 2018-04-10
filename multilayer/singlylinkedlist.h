#ifndef SINGLYLL_H
#define SINGLYLL_H
typedef struct nodes{
    void *value;
    struct nodes *next;
}node;

node *createList(void* headValue);
void insert(node* head, void* val);
void delEnd(node* head);
void freeList(node* head);

#endif