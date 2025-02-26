#ifndef MEMORY_LIB_H_
#define MEMORY_LIB_H_

#include "macros.h"

void *allocate_memory(size_t size);
void *copy_memory(void *dest, const void *src, size_t n);
void free_memory(void *ptr);
void *reallocate_memory(void *ptr, size_t new_size);

#endif /* !MEMORY_LIB_H_ */