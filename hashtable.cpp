/*
 * =====================================================================================
 *
 *       Filename:  hashtable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2017 02:25:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

typedef struct dictEntry {
    void *key;
    union {
        void *val;
        long s64;
    }v;
    struct dictEntry *next;
}dictEntry;

typedef struct dictType {
    unsigned int (*hashFunction)(const void *key);
    void *(*keyDup)(const void *key);
    void *(*valDup)(const void *obj);
    int (*keyCompare)(const void *key1, const void *key2);
    void (*keyDestructor)(void *key);
    void (*valDestructor)(void *obj);
} dictType;

typedef struct dictht {
    dictEntry **table;
    /*哈希表大小 */
    unsigned long size;
    /*哈希表大小掩码，用于计算索引值, 总是size-1*/
    unsigned long sizemask;
    /*该哈希表已有节点的数量*/
    unsigned long used;
    dictType *type;
}dictht;

static unsigned long get_next_power(unsigned long size)
{
    unsigned long i = 4;
    while (1) {
        if (i >= size)
            return i;
        i *= 2;
    }
}

dictht *create(unsigned long size, dictType *type)
{
    dictht *d = malloc(sizeof(*d));
    if (d == NULL)
        return NULL;
    unsigned long realsize = get_next_power(size);

    d->table = malloc(realsize*sizeof(dictEntry*));;
    d->size = realsize;
    d->sizemask = realsize - 1;
    d->used = 0;
    d->type = type;
    return d;
}

int add(dictht *d, void *key, void *val)
{
    dictEntry *entry;
    unsigned int h, idx, table;
    dictEntry *he;
    h = d->type->hashFunction(key);
    idx = h & d->sizemask;
    he = d->table[idx];
    while(he) {
        if (d->type->keyCompare(key, he->key))
            /*键已存在*/
            return -1;
        he = he->next;
    }
    entry = (dictEntry *)malloc(sizeof(*entry));
    if (entry == NULL)
        return -1;
    /*将新节点插入到链表表头*/
    entry->next = d->table[idx];
    d->table[idx] = entry;
    d->used++;
    /*key和val的设置需要malloc后赋值*/
    entry->key = d->type->keyDup(key);
    entry->v.val = d->type->valDup(val);
    return 0;
}

int del(dictht *d, const void *key)
{
    unsigned int h, idx;
    dictEntry *he, *prevHe;
    if (d->size == 0)
        return -1;
    h = d->type->hashFunction(key);
    idx = h & d->sizemask;
    he = d->table[idx];
    while(he) {
        if (d->type->keyCompare(key, he->key)) {
            if (prevHe)
                prevHe->next = he->next;
            else
                d->table[idx] = he->next;

            d->type->keyDestructor(he->key);
            d->type->valDestructor(he->v.val);
            free(he);
            d->used--;
            return 0;
        }
        prevHe = he;
        he = he->next;
    }
    return -1;
}

dictEntry *search(dictht *d, const void *key)
{
    dictEntry *he;
    unsigned int h, idx, table;
    if (d->size == 0)
        return NULL;
    h = d->type->hashFunction(key);
    dx = h & d->sizemask;
    he = d->table[idx];
    while(he) {
        if (d->type->keyCompare(key, he->key))
            return he;
        he = he->next;
    }
    return NULL;
}

