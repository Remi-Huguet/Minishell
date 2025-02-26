#include "macros.h"
#include "memory.h"
#include <unistd.h>

void *allocate_memory(size_t size);
void free_memory(void *ptr);
void *copy_memory(void *dest, const void *src, size_t n);

void *reallocate_memory(void *ptr, size_t new_size)
{
    if (ptr == NULL_POINTER) {
        return allocate_memory(new_size);
    }
    if (new_size == 0) {
        free_memory(ptr);
        return NULL_POINTER;
    }
    block_t *block = (block_t*)ptr - 1;
    size_t current_size = block->size;

    if (new_size <= current_size) {
        return ptr;
    }
    void *new_ptr = allocate_memory(new_size);
    if (new_ptr == MALLOC_ERROR) return NULL_POINTER;

    copy_memory(new_ptr, ptr, current_size);
    free_memory(ptr);
    return new_ptr;
}