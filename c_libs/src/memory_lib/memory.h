#ifndef MEMORY_H_
#define MEMORY_H_

#include <stddef.h>

#define NULL_BLOCK NULL

typedef struct block {
    size_t size;
    struct block *next;
    struct block *prev;
    int free;
} block_t;

extern block_t *head;

#endif /* !MEMORY_H_ */