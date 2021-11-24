#include "hash.h"
#include "log.h"


/*
 * Create Hash table with name, hash function and equal function.
 */
HashTable *CreateHashTable(const char *name, HashFunc hfunc, EqualFunc eqfunc){
    int i;
    HashTable *htab = (HashTable *) malloc(sizeof(HashTable));

    htab->hfunc   = hfunc;
    htab->tabname = name;
    htab->eqfunc = eqfunc;

    /* 
     * Bucket is an arrar of (Entry*). Each element is a start 
     * node of one list. 
     */
    htab->bucket = (Entry **) malloc(sizeof(Entry *) * DEFAULT_BUCKET_SIZE);
    for(i = 0; i < DEFAULT_BUCKET_SIZE; i++){
        htab->bucket[i] = (Entry *) malloc(sizeof(Entry *));
        memset(htab->bucket[i], 0, sizeof(Entry));
    }    

    return htab; 
}


/*
 * Find target entry in htab accroding to given key. 
 * It will return NULL if there is no suck entry.
 */
Entry *Find(HashTable *htab, uintptr_t key){

    /* Get entry list from hash value. */
    uint32_t hash_value = htab->hfunc(key) % DEFAULT_BUCKET_SIZE;
    Entry *entry = htab->bucket[hash_value];

    /* Skip the header. */
    entry = entry->next;
    while(entry != NULL){
        bool flag = false;

        /* 
         * Compare each item'key by equal function of hash table if it exists.
         * Otherwise use '=' operator. This will traverse the whole list of 
         * target bucket. 
         */
        if(htab->eqfunc)
            flag = htab->eqfunc((const void *)key, (const void *)entry->key);
        else
            flag = entry->key == key;
        if(flag)
            return entry;
        entry = entry->next;
    }

    return NULL;
}

/*
 * Insert key and value in htab. If there is an entry occupied
 * target positon, it will replace the value with new one.
 */ 
bool Insert(HashTable *htab, uintptr_t key, uintptr_t value){
    Entry *entry = Find(htab, key);
    
    if(entry != NULL)
        entry->value = value;
    else{
        uint32_t hash_value = htab->hfunc(key) % DEFAULT_BUCKET_SIZE;
        entry = htab->bucket[hash_value];

        while(entry->next != NULL){
            entry = entry->next;
        }

        /* Allocate new entry and append to target list. */
        entry->next = malloc(sizeof(Entry));
        entry = entry->next;
        entry->key = key;
        entry->value = value;
        entry->next = NULL; 
    }

    return true;

}

void DestroyHashTable(HashTable *htab){
    int i;

    for(i = 0; i < DEFAULT_BUCKET_SIZE; i++){
        Entry *head = htab->bucket[i];
        Entry *entry = head->next;

        while(entry != NULL){
            Entry *next = entry->next;
            free(entry);
            entry = next;
        }
    }

    free(htab->bucket);
}


/* 
 * Hash function for string. It will
 * xor each two characters in this string.
 */
uint32_t string_hash(uintptr_t key){
    char *str = (char *)key;
    uint32_t value = *str;

    str++;
    while(*str != '\0'){
        value ^= *str;
        str++;
    }

    return value;
}

bool string_equal(const void *p1, const void *p2){
    const char *s1 = (const char *)p1;
    const char *s2 = (const char *)p2;

    return strcmp(s1, s2) == 0;
}