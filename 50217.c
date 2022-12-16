#include <stdio.h>
#include <stdlib.h>

#define INSERT 0
#define DELETE_HEAD 1
#define DELETE_TAIL 2

typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
 
typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;
 
/* submit */
ListNode *genNode(int data, ListNode *next, ListNode *prev){
    
    ListNode *new = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;
    new->next = next;
    new->prev = prev;

    if(next != NULL)
        next->prev = new;

    if(prev != NULL) 
        prev->next = new;

    return new;
}

void insert(LinkedList *list, int data){
    
    if(list->head == NULL && list->tail == NULL){
        list->head = genNode(data, NULL, NULL);
        list->tail = list->head;
        return;
    }

    if(data <= list->head->data){
        list->head = genNode(data, list->head, NULL);
        return;
    }

    if(data >= list->tail->data){
        list->tail = genNode(data, NULL, list->tail);
        return;
    }

    ListNode *current = list->head;
    while(current != NULL){
        if(current->data >= data){
            genNode(data, current, current->prev);
            return;
        }
        else{
            current = current->next;
        }
    }
    return;
}

void delete_head(LinkedList *list){
    if(list->head == list->tail){
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    if(list->head != NULL){
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
        return;
    }
    return;
}

void delete_tail(LinkedList *list){
    if(list->head == list->tail){
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    if(list->tail != NULL){
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    }
    return;
}
/* submit */


void head_traverse(LinkedList *list){
    ListNode *node = list -> head;
    for(; node != NULL; node = node -> next)
        printf("%d%c", node -> data, (node -> next == NULL) ? '\n' : ' ');
}
 
void tail_traverse(LinkedList *list){
    ListNode *node = list -> tail;
    for(; node != NULL; node = node -> prev)
        printf("%d%c", node -> data, (node -> prev == NULL) ? '\n' : ' ');
}
 
int main(){
 
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list -> head = NULL;
    list -> tail = NULL;
    int func, val;
 
    while(scanf("%d%d", &func, &val) != EOF){
        switch (func){
            case INSERT:
                insert(list, val);
                break;
            case DELETE_HEAD:
                delete_head(list);
                break;
            case DELETE_TAIL:
                delete_tail(list);
                break;
        }
    }
 
    head_traverse(list);
    tail_traverse(list);
 
    return 0;
}