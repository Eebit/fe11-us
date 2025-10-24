#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "global.h"

struct HashNode
{
    /* 00 */ struct HashNode * next;
    /* 04 */ u32 hash;
    /* 08 */ char * key;
    /* 0C */ void * value;
};

class HashTable
{
public:
    /* 00 */ s32 nextIdx;
    /* 04 */ s32 poolSize;
    /* 08 */ s32 numBuckets;
    /* 0C */ struct HashNode * pool;
    /* 10 */ struct HashNode ** buckets;

    HashTable()
    {
        this->pool = NULL;
        this->buckets = NULL;
    };

    ~HashTable()
    {
        if (this->buckets)
        {
            delete[] this->buckets;
            this->buckets = NULL;
        }

        if (this->pool)
        {
            delete[] this->pool;
            this->pool = NULL;
        }
    };

    static void Init(void);
    static void * Get1(char * key);
    static void * Get2(char * key);
    static void Put(char * key, void * value);
    static BOOL Remove(char * key);

private:
    static HashTable gHashTable;

    s32 ComputeHash(char * key);
    void ComputeBucketAndHash(char * key, u32 * hash1, u32 * hash2);
    void _Init(s32 poolSize, s32 numBuckets);
    struct HashNode * _Insert(char * key, void * value);
    void * _Get1(char * key);
    void * _Get2(char * key);
    void _Put(char * key, void * value);
    BOOL _Remove(char * key);
};

#endif // HASHTABLE_HPP