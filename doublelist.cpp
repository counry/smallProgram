/*
 * =====================================================================================
 *
 *       Filename:  doublelist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2017 11:42:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

typedef struct listNode {
    struct listNode *prev;
    struct listNode *next;
    void *value;
} listNode;

typedef struct list {
    listNode *head;
    listNode *tail;
    void *(*dup)(void *ptr);
    void (*free)(void *ptr);
    void (*match)(void *ptr, void *key);
    unsigned long len;
}list;

list *create(void)
{
    list *list;
    if ((list = malloc(sizeof(*list))) == NULL)
        return NULL;
    list->head = list->tail = NULL;
    list->len = 0;
    list->dup = NULL;
    list->free = NULL;
    list->match = NULL;
    return list;
}

void free(list *list)
{
    unsigned long len;
    listNode *current, *next;
    current = list->head;
    len = list->len;
    while(len--) {
        next = current->next;
        if (list->free) list->free(current->value);
        free(current);
        current = next;
    }
    free(list);
}

list *insert_tail(list *list, void *value)
{
    listNode *node;
    if ((node = malloc(sizeof(*node))) == NULL)
        return NULL;
    node->value = value;
    if (list->len == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    } else {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
    list->len++;
    return list;
}

void del(list *list, listNode *node)
{
    /*调整前置节点*/
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;

    /*调整后置节点*/
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    if (list->free)
        list->free(node->value);
    free(node)
    list->len--;
}


