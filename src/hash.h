#ifndef __HASH_H
#define __HASH_H

#include "utils.h"


struct Entry;

/* 
 * Entry is the basic element in hash table, including key and
 * value and the next pointer.
 */
typedef struct Entry{
    uintptr_t key;
    uintptr_t value;
    struct Entry *next;
}Entry;

typedef struct HashTable{
    const char *tabname; /* Table' name */
    Entry **bucket;  /* Buckets to store the list of entries */
    HashFunc hfunc; /* Hash function for key */
    EqualFunc eqfunc; /* Equal function for key */
}HashTable;
uint32_t string_hash(uintptr_t key);
bool string_equal(const void *p1, const void *p2);
HashTable *CreateHashTable(const char *name, HashFunc hfunc, EqualFunc eqfunc);
void DestroyHashTable(HashTable *htab);
Entry *Find(HashTable *htab, uintptr_t key);
bool Insert(HashTable *htab, uintptr_t key, uintptr_t value);

#endif