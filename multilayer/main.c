#include "singlylinkedlist.h"
#include "stdio.h"

void printList(node *head){
    node *p = head;
    while(p){
        printf("%d",*(int*)p->value);
        p = p->next;
    }
    printf("\n");
}

int main(){
    int val=10;
    node *head = createList(&val);
    printList(head);
    return 0;
}
