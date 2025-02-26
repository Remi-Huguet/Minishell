#include "macros.h"
#include "memory.h"
#include <unistd.h>

block_t *head = NULL_BLOCK;

block_t *find_free_block(size_t size)
{
    block_t *current = head;

    while (current) {
        if (current->size >= size && current->free) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void *allocate_memory(size_t size)
{
    if (size <= 0) return NULL_POINTER;
    block_t *block;
    void *ptr;

    block = find_free_block(size);
    if (block) {
        block->free = 0;
        return (void*)(block + 1);
    } else {
        ptr = sbrk(size + sizeof(block_t));
        if (ptr == (void*) -1) return NULL_POINTER;
        block = ptr;
        block->size = size;
        block->free = 0;
        block->next = NULL_BLOCK;
        block->prev = NULL_BLOCK;
        if (!head) {
            head = block;
        } else {
            block_t *current = head;

            while (current->next) {
                current = current->next;
            }
            current->next = block;
            block->prev = current;
        }
    }
    return (void*)(block + 1);
}