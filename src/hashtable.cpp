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

HashTable HashTable::gHashTable;

s32 HashTable::ComputeHash(char * key)
{
    s32 hash = 0;
    signed char * it = (signed char *)key;

    while (*it != 0)
    {
        hash =  hash * 31 + *it++;
    }

    return hash;
}

void HashTable::ComputeBucketAndHash(char * key, u32 * hash1, u32 * hash2)
{
    signed char * it = (signed char *)key;

    *hash2 = 0;
    *hash1 = 0;

    while (*it != 0)
    {
        *hash1 = (*hash1 * 37) + *it;
        *hash2 = (*hash2 * 31) + *it;
        it++;
    }

    *hash1 %= this->numBuckets;
}

void HashTable::_Init(s32 poolSize, s32 numBuckets)
{
    s32 i;

    this->nextIdx = 0;
    this->poolSize = poolSize;
    this->numBuckets = numBuckets;
    this->pool = new struct HashNode[poolSize];
    this->buckets = new struct HashNode *[numBuckets];

    for (i = 0; i < poolSize; i++)
    {
        this->pool[i].next = NULL;
        this->pool[i].hash = 0;
        this->pool[i].key = NULL;
        this->pool[i].value = NULL;
    }

    for (i = 0; i < numBuckets; i++)
    {
        this->buckets[i] = NULL;
    }

    return;
}

struct HashNode * HashTable::_Insert(char * key, void * value)
{
    struct HashNode * node;
    s32 size;
    s32 i;

    size = this->poolSize;

    for (i = 0; i < size; i++)
    {
        node = &this->pool[this->nextIdx++];
        this->nextIdx %= this->poolSize;

        if (node->key == NULL)
        {
            break;
        }
    }

    node->next = NULL;
    node->hash = this->ComputeHash(key);
    node->key = key;
    node->value = value;

    return node;
}

void * HashTable::_Get1(char * key)
{
    u32 sp4;
    u32 sp0;
    struct HashNode * node;

    if (key == NULL)
    {
        return NULL;
    }

    this->ComputeBucketAndHash(key, &sp4, &sp0);

    for (node = this->buckets[sp4]; node != NULL; node = node->next)
    {
        if (sp0 == node->hash)
        {
            return node->value;
        }
    }

    return NULL;
}

void * HashTable::_Get2(char * key)
{
    return this->_Get1(key);
}

void HashTable::_Put(char * key, void * value)
{
    u32 sp4;
    u32 unused;
    struct HashNode * var_r0;
    struct HashNode * var_r4;

    this->ComputeBucketAndHash(key, &sp4, &unused);

    var_r0 = this->buckets[sp4];

    if (var_r0 == NULL)
    {
        this->buckets[sp4] = this->_Insert(key, value);
        return;
    }

    while (var_r0 != NULL)
    {
        var_r4 = var_r0;
        var_r0 = var_r0->next;
    }

    var_r4->next = this->_Insert(key, value);

    return;
}

BOOL HashTable::_Remove(char * key)
{
    u32 sp4;
    u32 sp0;
    struct HashNode * it;
    struct HashNode * var_lr;

    this->ComputeBucketAndHash(key, &sp4, &sp0);

    var_lr = this->buckets[sp4];

    for (it = var_lr; it != NULL; it = it->next)
    {
        struct HashNode * var_r0;

        if (sp0 != it->hash)
        {
            continue;
        }

        if (var_lr == it)
        {
            this->buckets[sp4] = it->next;
            it->key = 0;
            return TRUE;
        }

        var_r0 = var_lr->next;
        if (var_r0 != it)
        {
            do
            {
                var_lr = var_r0;
                var_r0 = var_r0->next;
            } while (var_r0 != it);
        }

        var_lr->next = it->next;
        it->key = NULL;

        return TRUE;
    }

    return FALSE;
}

void HashTable::Init(void)
{
    HashTable::gHashTable._Init(3400, 61);
    return;
}

void * HashTable::Get1(char * key)
{
    return HashTable::gHashTable._Get1(key);
}

void * HashTable::Get2(char * key)
{
    return HashTable::gHashTable._Get2(key);
}

void HashTable::Put(char * key, void * value)
{
    HashTable::gHashTable._Put(key, value);
    return;
}

BOOL HashTable::Remove(char * key)
{
    return HashTable::gHashTable._Remove(key);
}
