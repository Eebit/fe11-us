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

    // func_02037850
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
};

HashTable data_02197240;

EC s32 func_02037460(void * self, char * key)
{
    s32 hash = 0;
    signed char * it = (signed char *)key;

    while (*it != 0)
    {
        hash =  hash * 31 + *it++;
    }

    return hash;
}

EC void func_0203748c(struct HashTable * self, char * key, u32 * hash1, u32 * hash2)
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

    *hash1 %= self->numBuckets;
}

EC void func_020374f4(HashTable * self, s32 poolSize, s32 numBuckets)
{
    s32 i;

    self->nextIdx = 0;
    self->poolSize = poolSize;
    self->numBuckets = numBuckets;
    self->pool = new struct HashNode[poolSize];
    self->buckets = new struct HashNode *[numBuckets];

    for (i = 0; i < poolSize; i++)
    {
        self->pool[i].next = NULL;
        self->pool[i].hash = 0;
        self->pool[i].key = NULL;
        self->pool[i].value = NULL;
    }

    for (i = 0; i < numBuckets; i++)
    {
        self->buckets[i] = NULL;
    }

    return;
}

EC struct HashNode * func_02037598(struct HashTable * self, char * key, void * value)
{
    struct HashNode * node;
    s32 size;
    s32 i;

    size = self->poolSize;

    for (i = 0; i < size; i++)
    {
        node = &self->pool[self->nextIdx++];
        self->nextIdx %= self->poolSize;

        if (node->key == NULL)
        {
            break;
        }
    }

    node->next = NULL;
    node->hash = func_02037460(self, key);
    node->key = key;
    node->value = value;

    return node;
}

EC void * func_02037614(struct HashTable * self, char * key)
{
    u32 sp4;
    u32 sp0;
    struct HashNode * node;

    if (key == NULL)
    {
        return NULL;
    }

    func_0203748c(self, key, &sp4, &sp0);

    for (node = self->buckets[sp4]; node != NULL; node = node->next)
    {
        if (sp0 == node->hash)
        {
            return node->value;
        }
    }

    return NULL;
}

EC void * func_02037680(struct HashTable * self, char * key)
{
    return func_02037614(self, key);
}

EC void func_0203768c(struct HashTable * self, char * key, void * value)
{
    u32 sp4;
    u32 unused;
    struct HashNode * var_r0;
    struct HashNode * var_r4;

    func_0203748c(self, key, &sp4, &unused);

    var_r0 = self->buckets[sp4];

    if (var_r0 == NULL)
    {
        self->buckets[sp4] = func_02037598(self, key, value);
        return;
    }

    while (var_r0 != NULL)
    {
        var_r4 = var_r0;
        var_r0 = var_r0->next;
    }

    var_r4->next = func_02037598(self, key, value);

    return;
}

EC BOOL func_02037714(struct HashTable * self, char * key)
{
    u32 sp4;
    u32 sp0;
    struct HashNode * it;
    struct HashNode * var_lr;

    func_0203748c(self, key, &sp4, &sp0);

    var_lr = self->buckets[sp4];

    for (it = var_lr; it != NULL; it = it->next)
    {
        struct HashNode * var_r0;

        if (sp0 != it->hash)
        {
            continue;
        }

        if (var_lr == it)
        {
            self->buckets[sp4] = it->next;
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

EC void func_020377c8(void)
{
    func_020374f4(&data_02197240, 3400, 61);
    return;
}

EC void * func_020377e8(char * key)
{
    return func_02037614(&data_02197240, key);
}

EC void * func_02037800(char * key)
{
    return func_02037680(&data_02197240, key);
}

EC void func_02037818(char * key, void * value)
{
    func_0203768c(&data_02197240, key, value);
    return;
}

EC BOOL func_02037838(char * key)
{
    return func_02037714(&data_02197240, key);
}
